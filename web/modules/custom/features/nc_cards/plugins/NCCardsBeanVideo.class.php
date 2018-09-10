<?php
/**
 * @file
 * NC Cards Bean plugin.
 */

class NCCardsBeanVideo extends BeanPlugin {
  /**
   * Declare default block settings.
   */
  public function values() {
    $values = array(
      'framed' => FALSE,
    );
    return array_merge(parent::values(), $values);
  }

    /**
     * Bean form.
     */
    public function form($bean, $form, &$form_state) {
        $form['config'] = array(
            '#type' => 'fieldset',
            '#collapsible' => TRUE,
            '#title' => t('Settings'),
            '#weight' => 35,
        );
        $form['config']['framed'] = array(
            '#type' => 'checkbox',
            '#title' => t('Frame the Card'),
            '#description' => t('Add a border around the card.'),
            '#default_value' => $bean->framed,
        );
        return $form;
    }

    /**
     * View the Bean.
     */
    public function view($bean, $content, $view_mode = 'default', $langcode = NULL) {
        // Provide variables to our theme function.
        $wrapper = entity_metadata_wrapper('bean', $bean);
        if (!empty($content['bean'][$bean->delta]['field_card_image'][0])) {
            $variables['card_image'] = $content['bean'][$bean->delta]['field_card_image'][0];
        }
        $link = $wrapper->field_card_link->value(array('sanitized' => TRUE));
        if ($link) {
            $link = _nc_cards_card_link_query_fix($link);
            $url = url($link['url'], $link);
            $variables['card_link'] = nc_cards_check_url($url);
        }
        $variables['card_title'] = check_plain($link['title']);
        $date = $wrapper->field_card_date->value(array('sanitized' => TRUE));
        $keyword_array = array();
        if ($date) {
            $variables['card_date'] = date('M j, Y', $date);
            $variables['card_prop_date'] = date('Y-m-d', $date);
        }
        $keywords = $wrapper->field_card_keywords->value(array('sanitized' => TRUE));
        // Guard against 1 result.
        if (!is_object($keywords)) {
            foreach ($keywords as $keyword) {
                $keyword_array[] = check_plain($keyword->name);
            }
            $variables['card_keywords'] = implode(', ', $keyword_array);
        }
        else {
            $variables['card_keywords'] = check_plain($keywords->name);
        }
        $variables['card_framed'] = ($bean->framed) ? "framed" : "";
        $build = theme('nc_card_video', $variables);
        return $build;
    }
}
