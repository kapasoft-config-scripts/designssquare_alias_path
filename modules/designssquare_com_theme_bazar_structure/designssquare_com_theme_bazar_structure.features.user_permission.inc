<?php
/**
 * @file
 * designssquare_com_theme_bazar_structure.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function designssquare_com_theme_bazar_structure_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access checkout'.
  $permissions['access checkout'] = array(
    'name' => 'access checkout',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'commerce_checkout',
  );

  // Exported permission: 'view any commerce_product entity'.
  $permissions['view any commerce_product entity'] = array(
    'name' => 'view any commerce_product entity',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'view any commerce_product entity of bundle basic_template'.
  $permissions['view any commerce_product entity of bundle basic_template'] = array(
    'name' => 'view any commerce_product entity of bundle basic_template',
    'roles' => array(
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'view any commerce_product entity of bundle product'.
  $permissions['view any commerce_product entity of bundle product'] = array(
    'name' => 'view any commerce_product entity of bundle product',
    'roles' => array(),
    'module' => 'commerce_product',
  );

  return $permissions;
}
