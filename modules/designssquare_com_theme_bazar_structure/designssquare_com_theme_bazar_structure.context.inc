<?php
/**
 * @file
 * designssquare_com_theme_bazar_structure.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function designssquare_com_theme_bazar_structure_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'basic_page';
  $context->description = 'context for basic page';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'page' => 'page',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'bazar_theme-contact_info' => array(
          'module' => 'bazar_theme',
          'delta' => 'contact_info',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'bazar_theme-contact_form' => array(
          'module' => 'bazar_theme',
          'delta' => 'contact_form',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('context for basic page');
  $export['basic_page'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'bazar_blog_category';
  $context->description = 'for posts of certain category in bazar theme';
  $context->tag = '';
  $context->conditions = array(
    'taxonomy_term' => array(
      'values' => array(
        'blog_categories' => 'blog_categories',
      ),
      'options' => array(
        'term_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-47c074359dbefd7dd2bd852146046790' => array(
          'module' => 'views',
          'delta' => '47c074359dbefd7dd2bd852146046790',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'views-d141672d1acc707b5acf2f6c585f0576' => array(
          'module' => 'views',
          'delta' => 'd141672d1acc707b5acf2f6c585f0576',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'views-6126e666f3156bf177d5a45686761c6c' => array(
          'module' => 'views',
          'delta' => '6126e666f3156bf177d5a45686761c6c',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('for posts of certain category in bazar theme');
  $export['bazar_blog_category'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'bazar_blog_entry';
  $context->description = 'context for blog entry in Bazar theme';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'blog' => 'blog',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-10',
        ),
        'bazar_theme-search_form_small' => array(
          'module' => 'bazar_theme',
          'delta' => 'search_form_small',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'views-31dad79acc6aea1fc961a835d9767e4e' => array(
          'module' => 'views',
          'delta' => '31dad79acc6aea1fc961a835d9767e4e',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'views-6126e666f3156bf177d5a45686761c6c' => array(
          'module' => 'views',
          'delta' => '6126e666f3156bf177d5a45686761c6c',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'views-d141672d1acc707b5acf2f6c585f0576' => array(
          'module' => 'views',
          'delta' => 'd141672d1acc707b5acf2f6c585f0576',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('context for blog entry in Bazar theme');
  $export['bazar_blog_entry'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'bazar_blog_posts';
  $context->description = 'context for blog posts in Bazar Theme';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'blog_posts' => 'blog_posts',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-blog_content_view-posts' => array(
          'module' => 'views',
          'delta' => 'blog_content_view-posts',
          'region' => 'content',
          'weight' => '-10',
        ),
        'bazar_theme-search_form_small' => array(
          'module' => 'bazar_theme',
          'delta' => 'search_form_small',
          'region' => 'sidebar_second',
          'weight' => '-21',
        ),
        'views-47c074359dbefd7dd2bd852146046790' => array(
          'module' => 'views',
          'delta' => '47c074359dbefd7dd2bd852146046790',
          'region' => 'sidebar_second',
          'weight' => '-20',
        ),
        'views-6126e666f3156bf177d5a45686761c6c' => array(
          'module' => 'views',
          'delta' => '6126e666f3156bf177d5a45686761c6c',
          'region' => 'sidebar_second',
          'weight' => '-19',
        ),
        'views-d141672d1acc707b5acf2f6c585f0576' => array(
          'module' => 'views',
          'delta' => 'd141672d1acc707b5acf2f6c585f0576',
          'region' => 'sidebar_second',
          'weight' => '-18',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('context for blog posts in Bazar Theme');
  $export['bazar_blog_posts'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'bazar_blog_tags';
  $context->description = 'context for blog tags in Bazar Theme';
  $context->tag = '';
  $context->conditions = array(
    'taxonomy_term' => array(
      'values' => array(
        'tags' => 'tags',
      ),
      'options' => array(
        'term_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-10',
        ),
        'bazar_theme-search_form_small' => array(
          'module' => 'bazar_theme',
          'delta' => 'search_form_small',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'views-47c074359dbefd7dd2bd852146046790' => array(
          'module' => 'views',
          'delta' => '47c074359dbefd7dd2bd852146046790',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'views-6126e666f3156bf177d5a45686761c6c' => array(
          'module' => 'views',
          'delta' => '6126e666f3156bf177d5a45686761c6c',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'views-d141672d1acc707b5acf2f6c585f0576' => array(
          'module' => 'views',
          'delta' => 'd141672d1acc707b5acf2f6c585f0576',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('context for blog tags in Bazar Theme');
  $export['bazar_blog_tags'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'bazar_post_teaser';
  $context->description = 'context for post_teaser in Bazar theme';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'blog/*' => 'blog/*',
        'blog' => 'blog',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('context for post_teaser in Bazar theme');
  $export['bazar_post_teaser'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'contact';
  $context->description = 'context for contact us page';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'contact' => 'contact',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'bazar_theme-contact_info' => array(
          'module' => 'bazar_theme',
          'delta' => 'contact_info',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'bazar_theme-contact_form_horizon' => array(
          'module' => 'bazar_theme',
          'delta' => 'contact_form_horizon',
          'region' => 'contact_horizontal',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('context for contact us page');
  $export['contact'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'display_products';
  $context->description = 'display_products';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'product_display' => 'product_display',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'designssquare_com_commerce-ds_add_to_cart' => array(
          'module' => 'designssquare_com_commerce',
          'delta' => 'ds_add_to_cart',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('display_products');
  $export['display_products'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'display_theme';
  $context->description = 'display_theme';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'template_display' => 'template_display',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'designssquare_com_commerce-ds_add_to_cart' => array(
          'module' => 'designssquare_com_commerce',
          'delta' => 'ds_add_to_cart',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('display_theme');
  $export['display_theme'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'front';
  $context->description = 'context for front page of theme Bazar';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-10',
        ),
        'bazar_theme-search_form_small' => array(
          'module' => 'bazar_theme',
          'delta' => 'search_form_small',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'views-31dad79acc6aea1fc961a835d9767e4e' => array(
          'module' => 'views',
          'delta' => '31dad79acc6aea1fc961a835d9767e4e',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'bazar_theme-contact_info' => array(
          'module' => 'bazar_theme',
          'delta' => 'contact_info',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('context for front page of theme Bazar');
  $export['front'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'shop';
  $context->description = 'shop';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'shop' => 'shop',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'bazar_theme-contact_info' => array(
          'module' => 'bazar_theme',
          'delta' => 'contact_info',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'bazar_theme-contact_form' => array(
          'module' => 'bazar_theme',
          'delta' => 'contact_form',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'views-fdd657b6a7cf006bb3d6387629d29e2a' => array(
          'module' => 'views',
          'delta' => 'fdd657b6a7cf006bb3d6387629d29e2a',
          'region' => 'shop_space',
          'weight' => '-10',
        ),
        'views-5eb1d9eaefb20601f7d938540eb91263' => array(
          'module' => 'views',
          'delta' => '5eb1d9eaefb20601f7d938540eb91263',
          'region' => 'shop_space',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('shop');
  $export['shop'] = $context;

  return $export;
}
