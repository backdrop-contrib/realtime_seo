<?php

/**
 * @file
 */

/**
 * View handler class realtime_seo_handler_rating.
 */
class realtime_seo_handler_rating extends views_handler_field {

  /**
   * @inheritdoc
   */
  public function query() {
    $this->ensure_my_table();
  }

  /**
   * Renders the field handler.
   */
  public function render($values) {
    $output = '';

    if (user_access('use realtime seo')) {
      // Add our own CSS.
      backdrop_add_css(backdrop_get_path('module', 'realtime_seo') . '/css/realtime_seo.css');

      // Check if entity has SEO availability otherwise show a message.
      if (realtime_seo_entity_supports_realtime_seo('node', strtolower($values->node_type))) {
        // Score will be either 0 or a higher int. 0 is default.
        $score = realtime_seo_get_score($values->nid);
        // Class will represent classname for current score. Like poor or bad
        // it's used for theming purposes.
        $class = realtime_seo_score_rating($score);

        // Add Yoast score to the overview.
        $output = '<div id="realtime-overallscore" class="overallScore ' . $class . '"><div class="score_circle"></div></div>';
      }
      else {
        $output = '';
      }
    }

    return $output;
  }

}
