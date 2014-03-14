<?php
/**
 * @file
 * designssquare_com_theme_bazar_structure.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function designssquare_com_theme_bazar_structure_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function designssquare_com_theme_bazar_structure_node_info() {
  $items = array(
    'checkout_complete' => array(
      'name' => t('Checkout Complete'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'contact' => array(
      'name' => t('Contact'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'page' => array(
      'name' => t('Basic page'),
      'base' => 'node_content',
      'description' => t('Use <em>basic pages</em> for your static content, such as an \'About us\' page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'product_display' => array(
      'name' => t('Product Display'),
      'base' => 'node_content',
      'description' => t('display for products'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'shop' => array(
      'name' => t('Shop'),
      'base' => 'node_content',
      'description' => t('landing page of the store'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
