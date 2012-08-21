<?php
/**
 * @file
 * labfeatures_article.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function labfeatures_article_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|article|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'article';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'node_link' => array(
      'weight' => '6',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'author' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'author',
    ),
    'post_date' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'ds_post_date_long',
    ),
  );
  $export['node|article|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function labfeatures_article_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|article|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'article';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'header' => array(
        0 => 'author',
        1 => 'post_date',
        2 => 'field_category',
        3 => 'field_tags',
      ),
      'left' => array(
        0 => 'field_image',
      ),
      'right' => array(
        0 => 'field_summary',
        1 => 'node_link',
      ),
    ),
    'fields' => array(
      'author' => 'header',
      'post_date' => 'header',
      'field_category' => 'header',
      'field_tags' => 'header',
      'field_image' => 'left',
      'field_summary' => 'right',
      'node_link' => 'right',
    ),
    'classes' => array(),
  );
  $export['node|article|teaser'] = $ds_layout;

  return $export;
}
