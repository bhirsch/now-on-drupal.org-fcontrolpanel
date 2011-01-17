<?php
/**
 * @file fcontrolpanel.page.inc
 *  Build control panel page.
 */

/**
 * Callback for path admin/fcontrolpanel.
 */
function fcontrolpanel_page() {
  $fcontrols = ctools_export_load_object('fcontrolpanel_fcontrol');

  // set up fieldsets
  foreach($fcontrols as $fcontrol) {
    $package_title = $fcontrol->package;
    $package = strtolower(preg_replace('/[^a-zA-Z0-9-]+/', '-', $package_title));
    $form[$package] = array(
      '#title' => t($package_title),
      '#type' => 'fieldset',
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    ); 
  }
  // fill field sets with fcontrols
  foreach($fcontrols as $fcontrol) {
    $package_title = $fcontrol->package;
    $package = strtolower(preg_replace('/[^a-zA-Z0-9-]+/', '-', $package_title));
    // Link
    $txt = t($fcontrol->title);
    $path = $fcontrol->path;
    $query = $fcontrol->query;
    $link = l($txt, $path, array('query' => $query));
    $form[$package][$fcontrol->name] = array(
      '#type' => 'item',
      '#title' => $link,
      '#value' => t($fcontrol->description),
    );
    // Video
    // Instructions
  }

  return $form; 
}
