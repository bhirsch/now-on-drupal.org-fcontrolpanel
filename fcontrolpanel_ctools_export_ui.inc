<?php

$plugin = array(
  // The name of the table as found in the schema in hook_install. This
  // must be an exportable type with the 'export' section defined.
  'schema' => 'example',

  // The access permission to use. If not provided it will default to
  // 'administer site configuration'
  'access' => 'administer example',

  // You can actually define large chunks of the menu system here. Nothing
  // is required here. If you leave out the values, the prefix will default
  // to admin/build and the item will default to the plugin name.
  'menu' => array(
    'menu prefix' => 'admin/build',
    'menu item' => 'example',
    // Title of the top level menu. Note this should not be translated,
    // as the menu system will translate it.
    'menu title' => 'Example', 
    // Description of the top level menu, which is usually needed for
    // menu items in an administration list. Will be translated
    // by the menu system.
    'menu description' => 'Administer site example objects.',
  ),

  // These are required to provide proper strings for referring to the
  // actual type of exportable. "proper" means it will appear at the
  // beginning of a sentence.
  'title singular' => t('example'),
  'title singular proper' => t('Example'),
  'title plural' => t('examples'),
  'title plural proper' => t('Examples'),

  This will provide you with a form for editing the properties on your
  // exportable, with validate and submit handler.
  //
  // The item being edited will be in $form_state['item'].
  //
  // The submit handler is only responsible for moving data from
  // $form_state['values'] to $form_state['item'].
  //
  // All callbacks will accept &$form and &$form_state as arguments.
  'form' => array(
    'settings' => 'example_ctools_export_ui_form',
    'validate' => 'example_ctools_export_ui_form_validate',
    'submit' => 'example_ctools_export_ui_form_submit',
  ),
);
