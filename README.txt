Control Panel 
--------------

This is an end-user oriented admin page.


Admin Module (Admin Toolbar)
----------------------------

Add this to your features module's .module file:

/**
 * Implementation of hook_enable().
 */
function myfeature_enable() {
  // update admin toolbar
  fcontrolpanel_admin_toolbar('enable');  
}

/**
 * Implementation of hook_disable().
 */
function myfeature_disable() {
  // update admin toolbar
  fcontrolpanel_admin_toolbar('disable');  
}
