<?php
/**
 * @file
 * labfeatures_article.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function labfeatures_article_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function labfeatures_article_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function labfeatures_article_image_default_styles() {
  $styles = array();

  // Exported image style: article-full-node.
  $styles['article-full-node'] = array(
    'name' => 'article-full-node',
    'effects' => array(
      1 => array(
        'label' => 'EPSA Image Crop',
        'help' => '',
        'effect callback' => 'epsacrop_crop_image',
        'form callback' => 'epsacrop_crop_image_form',
        'module' => 'epsacrop',
        'name' => 'epsacrop_crop',
        'data' => array(
          'width' => '310',
          'height' => '300',
          'anchor' => 'center-center',
          'jcrop_settings' => array(
            'aspect_ratio' => '',
            'bgcolor' => 'black',
            'bgopacity' => '0.6',
          ),
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: article-teaser.
  $styles['article-teaser'] = array(
    'name' => 'article-teaser',
    'effects' => array(
      2 => array(
        'label' => 'EPSA Image Crop',
        'help' => '',
        'effect callback' => 'epsacrop_crop_image',
        'form callback' => 'epsacrop_crop_image_form',
        'module' => 'epsacrop',
        'name' => 'epsacrop_crop',
        'data' => array(
          'width' => '220',
          'height' => '110',
          'anchor' => 'center-center',
          'jcrop_settings' => array(
            'aspect_ratio' => '',
            'bgcolor' => 'black',
            'bgopacity' => '0.6',
          ),
        ),
        'weight' => '1',
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function labfeatures_article_node_info() {
  $items = array(
    'article' => array(
      'name' => t('Article'),
      'base' => 'node_content',
      'description' => t('Article for the article archive on the site'),
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
  );
  return $items;
}
