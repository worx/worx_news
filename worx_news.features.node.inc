<?php

/**
 * Helper to implementation of hook_node_info().
 */
function _worx_news_node_info() {
  $items = array(
    'news' => array(
      'name' => t('News'),
      'module' => 'features',
      'description' => t('Create News articles to keep your visitors up to date with all the new information you have to share with them.'),
      'has_title' => '1',
      'title_label' => t('Headline'),
      'has_body' => '1',
      'body_label' => t('Article'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}
