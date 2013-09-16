<?php

/**
 * Implementation of hook_content_default_fields().
 */
function worx_news_content_default_fields() {
  module_load_include('inc', 'worx_news', 'worx_news.defaults');
  $args = func_get_args();
  return call_user_func_array('_worx_news_content_default_fields', $args);
}

/**
 * Implementation of hook_context_default_contexts().
 */
function worx_news_context_default_contexts() {
  module_load_include('inc', 'worx_news', 'worx_news.defaults');
  $args = func_get_args();
  return call_user_func_array('_worx_news_context_default_contexts', $args);
}

/**
 * Implementation of hook_ctools_plugin_api().
 */
function worx_news_ctools_plugin_api() {
  module_load_include('inc', 'worx_news', 'worx_news.defaults');
  $args = func_get_args();
  return call_user_func_array('_worx_news_ctools_plugin_api', $args);
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function worx_news_imagecache_default_presets() {
  module_load_include('inc', 'worx_news', 'worx_news.defaults');
  $args = func_get_args();
  return call_user_func_array('_worx_news_imagecache_default_presets', $args);
}

/**
 * Implementation of hook_node_info().
 */
function worx_news_node_info() {
  module_load_include('inc', 'worx_news', 'worx_news.features.node');
  $args = func_get_args();
  return call_user_func_array('_worx_news_node_info', $args);
}

/**
 * Implementation of hook_default_page_manager_pages().
 */
function worx_news_default_page_manager_pages() {
  module_load_include('inc', 'worx_news', 'worx_news.defaults');
  $args = func_get_args();
  return call_user_func_array('_worx_news_default_page_manager_pages', $args);
}

/**
 * Implementation of hook_user_default_permissions().
 */
function worx_news_user_default_permissions() {
  module_load_include('inc', 'worx_news', 'worx_news.defaults');
  $args = func_get_args();
  return call_user_func_array('_worx_news_user_default_permissions', $args);
}

/**
 * Implementation of hook_strongarm().
 */
function worx_news_strongarm() {
  module_load_include('inc', 'worx_news', 'worx_news.defaults');
  $args = func_get_args();
  return call_user_func_array('_worx_news_strongarm', $args);
}

/**
 * Implementation of hook_views_default_views().
 */
function worx_news_views_default_views() {
  module_load_include('inc', 'worx_news', 'worx_news.features.views');
  $args = func_get_args();
  return call_user_func_array('_worx_news_views_default_views', $args);
}
