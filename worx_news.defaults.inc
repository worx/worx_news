<?php

/**
 * Helper to implementation of hook_content_default_fields().
 */
function _worx_news_content_default_fields() {
  $fields = array();

  // Exported field: field_worx_news_photo
  $fields[] = array(
    'field_name' => 'field_worx_news_photo',
    'type_name' => 'news',
    'display_settings' => array(
      'weight' => '-3',
      'parent' => '',
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'worx_news_thumbnail_linked',
        'exclude' => 1,
      ),
      'full' => array(
        'format' => 'worx_news_preview_imagelink',
        'exclude' => 1,
      ),
      '4' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'filefield',
    'required' => '0',
    'multiple' => '0',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '0',
    'widget' => array(
      'file_extensions' => 'png gif jpg jpeg',
      'file_path' => 'worx_news/[site-date-yyyy]/[site-date-month]',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '',
      'max_filesize_per_node' => '',
      'max_resolution' => '0',
      'min_resolution' => '200x200',
      'alt' => '',
      'custom_alt' => 1,
      'title' => '',
      'custom_title' => 0,
      'title_type' => 'textfield',
      'default_image' => NULL,
      'use_default_image' => 0,
      'label' => 'Photo',
      'weight' => '-3',
      'description' => '',
      'type' => 'imagefield_widget',
      'module' => 'imagefield',
    ),
  );

  // Exported field: field_worx_news_tagline
  $fields[] = array(
    'field_name' => 'field_worx_news_tagline',
    'type_name' => 'news',
    'display_settings' => array(
      'weight' => '-4',
      'parent' => '',
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 1,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 1,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '1',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_worx_news_tagline][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Tagline',
      'weight' => '-4',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Translatables
  array(
    t('Photo'),
    t('Tagline'),
  );

  return $fields;
}

/**
 * Helper to implementation of hook_context_default_contexts().
 */
function _worx_news_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'news_section';
  $context->description = 'Appends the news block to news article nodes';
  $context->tag = 'block';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'news' => 'news',
      ),
      'options' => array(
        'node_form' => 0,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-news_view-block_1' => array(
          'module' => 'views',
          'delta' => 'news_view-block_1',
          'region' => 'sidebar_last',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  $translatables['news_section'] = array(
    t('Appends the news block to news article nodes'),
    t('block'),
  );

  $export['news_section'] = $context;
  return $export;
}

/**
 * Helper to implementation of hook_ctools_plugin_api().
 */
function _worx_news_ctools_plugin_api() {
  $args = func_get_args();
  $module = array_shift($args);
  $api = array_shift($args);
  if ($module == "context" && $api == "context") {
    return array("version" => 3);
  }
  else if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => 1);
  }
  else if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Helper to implementation of hook_imagecache_default_presets().
 */
function _worx_news_imagecache_default_presets() {
  $items = array(
    'worx_news_preview' => array(
      'presetname' => 'worx_news_preview',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '400',
            'height' => '400',
            'upscale' => 0,
          ),
        ),
      ),
    ),
    'worx_news_thumbnail' => array(
      'presetname' => 'worx_news_thumbnail',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '200',
            'height' => '200',
            'upscale' => 0,
          ),
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Helper to implementation of hook_default_page_manager_pages().
 */
function _worx_news_default_page_manager_pages() {
  $page = new stdClass;
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'news_add';
  $page->task = 'page';
  $page->admin_title = 'Add News Articles';
  $page->admin_description = '';
  $page->path = 'news/add_news';
  $page->access = array(
    'plugins' => array(
      '0' => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'create news content',
        ),
        'context' => 'logged-in-user',
      ),
    ),
    'logic' => 'and',
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'tab',
    'title' => 'Create News Article',
    'name' => 'navigation',
    'weight' => '1',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array();
  $page->default_handlers = array();
  $handler = new stdClass;
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_news_add_menu_context';
  $handler->task = 'page';
  $handler->subtask = 'news_add';
  $handler->handler = 'menu_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Context Admin',
    'no_blocks' => FALSE,
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'context_admin_options' => 'node_create_menu',
    'context_admin_options_items' => 'news',
  );
  $page->default_handlers[$handler->name] = $handler;
  $pages['news_add'] = $page;

  $page = new stdClass;
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'news_admin';
  $page->task = 'page';
  $page->admin_title = 'News Administration';
  $page->admin_description = '';
  $page->path = 'news/admin';
  $page->access = array(
    'plugins' => array(
      '0' => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            '0' => 4,
          ),
        ),
        'context' => 'logged-in-user',
      ),
      '1' => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'administer nodes',
        ),
        'context' => 'logged-in-user',
      ),
    ),
    'logic' => 'or',
  );
  $page->menu = array(
    'type' => 'tab',
    'title' => 'Administer',
    'name' => 'navigation',
    'weight' => '10',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array();
  $page->default_handlers = array();
  $handler = new stdClass;
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_news_admin_menu_context';
  $handler->task = 'page';
  $handler->subtask = 'news_admin';
  $handler->handler = 'menu_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Context Admin',
    'no_blocks' => FALSE,
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'context_admin_options' => 'views_bulk_menu',
    'context_admin_vbo_views_bulk_node_type' => 'news',
    'context_admin_vbo_views_bulk_published' => 'both',
  );
  $page->default_handlers[$handler->name] = $handler;
  $pages['news_admin'] = $page;

 return $pages;

}

/**
 * Helper to implementation of hook_user_default_permissions().
 */
function _worx_news_user_default_permissions() {
  $permissions = array();

  // Exported permission: create news content
  $permissions[] = array(
    'name' => 'create news content',
    'roles' => array(
      '0' => 'administrative user',
      '1' => 'news reporter',
      '2' => 'webmaster',
    ),
  );

  // Exported permission: delete any news content
  $permissions[] = array(
    'name' => 'delete any news content',
    'roles' => array(
      '0' => 'administrative user',
      '1' => 'webmaster',
    ),
  );

  // Exported permission: delete own news content
  $permissions[] = array(
    'name' => 'delete own news content',
    'roles' => array(
      '0' => 'administrative user',
      '1' => 'webmaster',
    ),
  );

  // Exported permission: edit any news content
  $permissions[] = array(
    'name' => 'edit any news content',
    'roles' => array(
      '0' => 'administrative user',
      '1' => 'webmaster',
    ),
  );

  // Exported permission: edit own news content
  $permissions[] = array(
    'name' => 'edit own news content',
    'roles' => array(
      '0' => 'administrative user',
      '1' => 'webmaster',
    ),
  );

  return $permissions;
}

/**
 * Helper to implementation of hook_strongarm().
 */
function _worx_news_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_news';
  $strongarm->value = '3';

  $export['comment_controls_news'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_news';
  $strongarm->value = '4';

  $export['comment_default_mode_news'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_news';
  $strongarm->value = '0';

  $export['comment_form_location_news'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_news';
  $strongarm->value = array(
    '0' => 'status',
  );

  $export['node_options_news'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_news_pattern';
  $strongarm->value = 'news/[title-raw]';

  $export['pathauto_node_news_pattern'] = $strongarm;
  return $export;
}
