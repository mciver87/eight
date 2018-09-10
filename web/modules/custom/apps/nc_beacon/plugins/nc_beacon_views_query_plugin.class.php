<?php
/**
 * @file
 * A Views query plugin for executing queries against the NC BEACON API
 */

class nc_beacon_views_query_plugin extends views_plugin_query {
  /**
   * Properties
   */
  var $where = array();
  var $orderby = array();
  var $group_operator = NULL;

  /**
   * Constructor; Create the basic query object and fill with default values.
   */
  public function init($base_table, $base_field, $options) {
    parent::init($base_table, $base_field, $options);
  }

  /**
   * Get aggregation info for group by queries.
   *
   * If NULL, aggregation is not allowed.
   */
  public function get_aggregation_info() {
    return NULL;
  }

  /**
   * Generate a query and a countquery from all of the information supplied
   * to the object.
   *
   * @param $get_count
   *   Provide a countquery if this is true, otherwise provide a normal query.
   */
  public function query($get_count = FALSE) {
    // Construct query from Views filter grouping.
    $groups = array();
    foreach ($this->where as $where) {
      $queries = array();
      foreach ($where['conditions'] as $cond) {
        // Multiple values for condition, suss out.
        if (is_array($cond['value']) && !is_string($cond['value']) && !empty($cond['value'])) {
          $in_queries = array();
          foreach ($cond['value'] as $in_val) {
            $query['params']['$where'][$cond['field']] = trim($in_val);
          }
        }
        // Otherwise simple field-value comparison.
        else {
          $query['params']['$where'][$cond['field']] = trim($cond['value']);
        }
      }
    }

    // If this is a full query build vs a counter query, add on options.
    if (!$get_count) {
      // Store off requested fields
      if (!empty($this->fields)) {
        $query['params']['$select'] = implode(',', $this->fields);
      }

      // Suss out offset-limit options.
      if (!empty($this->limit)) {
        $query['params']['$limit'] = $this->limit;
      }
      if (!empty($this->offset)) {
        $query['params']['$offset'] = $this->offset;
      }

      // Suss out sort fields.
      if (!empty($this->orderby)) {
        foreach ($this->orderby as $orderby) {
          $query['params']['$order'] = array(
            'orderby' => strtolower($orderby['field']),
            'ordertype' => strtolower($orderby['direction']),
          );
        }
      }
    }
    else {
      $query['params']['$offset'] = 0;
      $query['params']['$limit'] = 0;
    }

    return $query;
  }

  /**
   * Let modules modify the query just prior to finalizing it.
   */
  public function alter(&$view) {
    foreach (module_implements('views_query_alter') as $module) {
      $function = $module . '_views_query_alter';
      $function($view, $this);
    }
  }

  /**
   * Builds the necessary info to execute the query.
   *
   * @param view $view
   *   The view which is executed.
   */
  public function build(&$view) {
    // Store the view in the object to be able to use it later.
    $this->view = $view;

    $view->init_pager();

    // Let the pager modify the query to add limits.
    $this->pager->query();

    $view->build_info['query'] = $this->query();
    $view->build_info['count_query'] = $this->query(TRUE);
  }

  /**
   * Executes the query and fills the associated view object with according
   * values.
   *
   * Values to set: $view->result, $view->total_rows, $view->execute_time,
   * $view->pager['current_page'].
   *
   * $view->result should contain an array of objects. The array must use a
   * numeric index starting at 0.
   *
   * @param view $view
   *   The view which is executed.
   */
  public function execute(&$view) {
    $query = $view->build_info['query'];
    $count_query = $view->build_info['count_query'];

    $start = microtime(TRUE);
    $result = array();
    $num_dataset_rows = 0;
    $table = $this->base_table;

    //dpm($query, __FUNCTION__);
    if (!empty($query['params']['$where']['namefirst']) ||
        !empty($query['params']['$where']['namelast']) ||
        !empty($query['params']['$where']['agency'])) {
      // Let the pager modify the query to add limits.
      $this->pager->pre_execute($query);

      // Build query request and execute it
      $args = $query['params']['$where'];
      if (!empty($query['params']['$order'])) {
        $args += $query['params']['$order'];
      }
      $args['offset'] = !empty($query['params']['$offset']) ? $query['params']['$offset'] : 0;
      $args['next'] = !empty($query['params']['$limit']) ? $query['params']['$limit'] : 250;

      $req_url = url('http://uat.empdirws.nc.gov/index.php', array('query' => $args));
      $resp = drupal_http_request($req_url);
      //dpm($resp, __FUNCTION__);

      // Process response into Views rows
      if (200 == $resp->code) {
        $resp_data = json_decode($resp->data);
        if (NULL !== $resp_data) {
          //dpm($resp_data, __FUNCTION__);
          $num_dataset_rows = $resp_data->totalrecords;
          unset($resp_data->totalrecords);
          foreach ($resp_data as $pkid => $emp_info) {
            $emp_info->pkEmployee = $pkid;
            $result[] = $emp_info;
          }
        }
      }
    }

    // Store off values from query in View.
    $view->result = $result;
    $view->total_rows = count($result);
    $this->pager->post_execute($view->result);

    // Execute count query for pager if necessary.
    if ($this->pager->use_count_query()) {
      $this->pager->total_items = $num_dataset_rows;
      $view->total_rows = $this->pager->get_total_items();
      $this->pager->update_page_info();
    }

    // Wrap up query.
    $view->execute_time = microtime(TRUE) - $start;
  }

  /***************************************************************************
   * REQUIRED methods for a Views query plugin leveraging base handlers
   **************************************************************************/

  /**
   * Add field to the query
   */
  public function add_field($table, $field, $required = FALSE) {
    $this->fields[$field] = $field;
    return $field;
  }

  /**
   * Copied from views_plugin_query_default, called by filter handlers
   */
  public function add_where($group, $field, $value = NULL, $operator = NULL) {
    // Ensure all variants of 0 are actually 0. Thus '', 0 and NULL are all
    // the default group.
    if (empty($group)) {
      $group = 0;
    }

    // Check for a group.
    if (!isset($this->where[$group])) {
      $this->set_where_group('AND', $group);
    }

    $field_comps = explode('.', $field);
    $clean_field = array_pop($field_comps);
    $this->where[$group]['conditions'][] = array(
      'field' => $clean_field,
      'value' => $value,
      'operator' => $operator,
    );
  }

  /**
   * Ripped straight out of views_plugin_query_default
   */
  public function add_where_expression($group, $snippet, $args = array()) {
    // Ensure all variants of 0 are actually 0. Thus '', 0 and NULL are all
    // the default group.
    if (empty($group)) {
      $group = 0;
    }

    // Check for a group.
    if (!isset($this->where[$group])) {
      $this->set_where_group('AND', $group);
    }

    $this->where[$group]['conditions'][] = array(
      'field' => $snippet,
      'value' => $args,
      'operator' => 'formula',
    );
  }

  /**
   * Copied from views_plugin_query_default, modified for our simplified case, called by sort handlers
   */
  public function add_orderby($table, $field, $order = 'ASC', $alias = '', $params = array()) {
    // Only fill out this aliasing if there is a table;
    // otherwise we assume it is a formula.
    if (!$alias && $table) {
      $as = $field;
    }
    else {
      $as = $alias;
    }

    if ($field) {
      $as = $this->add_field($table, $field, $as, $params);
    }

    $this->orderby[] = array(
      'field' => $as,
      'direction' => strtoupper($order)
    );
  }

  /**
   * Remove all fields that may have been added; primarily used for summary
   * mode where we're changing the query because we didn't get data we needed.
   */
  public function clear_fields() {
    $this->fields = array();
  }

  /**
   * Dummy placeholder method to satisfy Views core handlers
   */
  public function ensure_table($table) {
    return $table;
  }

}
