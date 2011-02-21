<?php
/**
 * @file fcontrolpanel.page.inc
 *  Build control panel page.
 */

/**
 * Callback for path admin/fcontrolpanel.
 */
function fcontrolpanel_page($form, &$form_state) {
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
        if (user_access($perm) && !property_exists($fcontrol, 'disabled')) {
        //if (user_access($perm) && ! $fcontrol->disabled) {
          $txt = t($fcontrol->title);
          $path = $fcontrol->path;
          $query = _fcontrolpanel_query($fcontrol);
          $link = ($query) ? l($txt, $path, array('query' => $query)) : l($txt, $path);
          $form[$package_name][$fcontrol->name] = array(
            '#type' => 'item',
            '#title' => $link,
            '#value' => t($fcontrol->description),
            '#weight' => $fcontrol->weight,
            '#title_display' => 'invisible',
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
function theme_fcontrolpanel_fcontrol($variables) {
  $element = $variables['element'];
  $path = drupal_get_path('module', 'fcontrolpanel');
  drupal_add_css("$path/fcontrolpanel.css");

  // @TODO call drupal_render() here? 
  // e.g. see system_date_time_settings here:
  //   http://api.drupal.org/api/drupal/modules--system--system.api.php/function/hook_theme/7
  //   Implementation here: 
  //   system.admin.inc line 2029, theme_system_date_time_settings($variables)
  $output = '';
  $output .= '<div class="fcontrol-title">' . $element['#title'] . '</div>';
  $output .= '<div class="fcontrol-description">' . $element['#value'] . '</div>';
  $output = '<div class="fcontrol">' . $output . '</div>';
  return $output;
}
