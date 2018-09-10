<?php
/**
 * @file
 * Connects a request mechanism and parsing mechanism.
 */

/**
 * Class RequestParserConnector
 */
class RequestParserConnector {
  /**
   * Feeds.
   *
   * @var array
   */
  protected $feeds = array();

  /**
   * Options.
   *
   * @var array
   */
  protected $options = array();

  /**
   * Request.
   *
   * @var
   */
  protected $request;

  /**
   * Parser.
   *
   * @var
   */
  protected $parser;

  /**
   * Constructor.
   *
   * @param \RequestDelegateInterface $request
   *   Request.
   *
   * @param \ResponseBodyParserInterface $parser
   *   Parser.
   *
   * @param array $feeds
   *   Feeds.
   *
   * @param array $options
   *   Options.
   */
  public function __construct(
    RequestDelegateInterface $request,
    ResponseBodyParserInterface $parser,
    $feeds = array(),
    $options = array()
  ) {
    $this->setRequest($request);
    $this->setParser($parser);
    $this->setFeeds($feeds);
    $this->setOptions($options);
  }

  /**
   * Get parser.
   *
   * @return ResponseBodyParserInterface
   *   Return parser.
   */
  public function getParser() {
    return $this->parser;
  }

  /**
   * Set Parser.
   *
   * @param ResponseBodyParserInterface $parser
   *   Parser.
   *
   * @return this
   *   Return this.
   */
  public function setParser(ResponseBodyParserInterface $parser) {
    $this->parser = $parser;
    return $this;
  }

  /**
   * Get request.
   *
   * @return RequestDelegateInterface
   *   Return request.
   */
  public function getRequest() {
    return $this->request;
  }

  /**
   * Set request.
   *
   * @param RequestDelegateInterface $request
   *   Request.
   *
   * @return this
   *   Return this.
   */
  public function setRequest(RequestDelegateInterface $request) {
    $this->request = $request;
    return $this;
  }

  /**
   * Get feeds.
   *
   * @return array
   *   Return feeds.
   */
  public function getFeeds() {
    return $this->feeds;
  }

  /**
   * Set feeds.
   *
   * @param array $feeds
   *   Feeds.
   *
   * @return this
   *   Return this.
   */
  public function setFeeds($feeds) {
    $this->feeds = $feeds;
    return $this;
  }

  /**
   * Get options.
   *
   * @return array
   *   return options.
   */
  public function getOptions() {
    return $this->options;
  }

  /**
   * Set options.
   *
   * @param array $options
   *   Options.
   *
   * @return this
   *   Return this.
   */
  public function setOptions($options) {
    $this->options = $options;
    return $this;
  }

  /**
   * Get data.
   *
   * @return array
   *   Returns data.
   */
  public function getData() {

    $data = array();

    foreach ($this->getFeeds() as $key => $feed_url) {
      $results = $this->getAlerts($feed_url, $key);
      $data[] = $results;
    }

    return $data;
  }

  /**
   * Get alerts from url.
   *
   * @param string $url
   *   Url.
   *
   * @param string $key
   *   Identifies which feed the url represents.
   *
   * @return mixed
   *   Parsed alerts.
   */
  protected function getAlerts($url, $key = NULL) {
    // TODO: Add error detection/handling on the request.
    $response = $this->getRequest()->request($url)->getResponseBody();
    return $this->getParser()->parse($response, $key);
  }
}
