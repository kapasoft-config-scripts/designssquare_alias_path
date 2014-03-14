<?php
/**
 * @file
 * designssquare_com_theme_bazar_structure.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function designssquare_com_theme_bazar_structure_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_basic-page:basic-page
  $menu_links['main-menu_basic-page:basic-page'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'basic-page',
    'router_path' => 'basic-page',
    'link_title' => 'BASIC PAGE',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_basic-page:basic-page',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: main-menu_blog:ds-blog
  $menu_links['main-menu_blog:ds-blog'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'ds-blog',
    'router_path' => 'ds-blog',
    'link_title' => 'BLOG',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_blog:ds-blog',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: main-menu_contact:contact
  $menu_links['main-menu_contact:contact'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'contact',
    'router_path' => 'contact',
    'link_title' => 'CONTACT',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_contact:contact',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 4,
    'customized' => 1,
  );
  // Exported menu link: main-menu_store:ds-store
  $menu_links['main-menu_store:ds-store'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'ds-store',
    'router_path' => 'ds-store',
    'link_title' => 'STORE',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_store:ds-store',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -49,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('BASIC PAGE');
  t('BLOG');
  t('CONTACT');
  t('STORE');


  return $menu_links;
}
