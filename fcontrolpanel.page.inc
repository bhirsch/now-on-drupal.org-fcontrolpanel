<?php
/**
 * @file fcontrolpanel.page.inc
 *  Build control panel page.
 */

/**
 * Callback for path admin/fcontrolpanel.
 */
function fcontrolpanel_page() {
  ctools_include('export');
  $fcontrols = ctools_export_load_object('fcontrolpanel_fcontrol');

  $packages = fcontrolpanel_get_packages();

  // set up fieldsets
  foreach ($packages as $package) {
    if (!$package['disabled']) {
      $package_name = $package['package_name'];
      $package_title = $package['package_title'];
      $form[$package_name] = array(
        '#title' => t($package_title),
        '#type' => 'fieldset',
        '#collapsible' => TRUE,
        '#collapsed' => TRUE,
      ); 
      // fill fieldsets with fcontrols
      foreach ($package['fcontrols'] as $fcontrol) {
        $perm = ($fcontrol->permission) ? $fcontrol->permission : "access features control panel";
        if (user_access($perm) && ! $fcontrol->disabled) {
          $txt = t($fcontrol->title);
          $path = $fcontrol->path;
          $query = $fcontrol->query;
          $link = l($txt, $path, array('query' => $query));
          $form[$package_name][$fcontrol->name] = array(
            '#type' => 'item',
            '#title' => $link,
            '#value' => t($fcontrol->description),
            '#weight' => $fcontrol->weight,
            '#theme' => 'fcontrolpanel_fcontrol',
          );
        }
      }
    }
  }
  // TODO Video
  // TODO Instructions
  return $form; 
}

/**
 * Implementation of theme function for form elements.
 */
function theme_fcontrolpanel_fcontrol($element) {
  $path = drupal_get_path('module', 'fcontrolpanel');
  drupal_add_css("$path/fcontrolpanel.css");

  $output = '';
  $output .= '<div class="fcontrol-title">'. $element['#title'] .'</div>';
  $output .= '<div class="fcontrol-description">'. $element['#value'] .'</div>';
  $output = '<div class="fcontrol">'. $output .'</div>'; 
  return $output;
}
