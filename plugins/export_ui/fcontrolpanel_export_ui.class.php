<?php
/**
 * CTools export UI extending class. Slightly customized for Context.
 *
 * Based on: context/context_ui/export_ui/context_export_ui.class.php.
 */
class fcontrolpanel_export_ui extends ctools_export_ui {
  /*
  function list_form(&$form, &$form_state) {
    parent::list_form($form, $form_state);
//    $form['top row']['submit'] = $form['bottom row']['submit'];
//    $form['top row']['reset'] = $form['bottom row']['reset'];
//    $form['bottom row']['#access'] = FALSE;
    // Invalidate the context cache.
//    context_invalidate_cache();
    return;
  }
  // */

  /*
  function list_css() {
    ctools_add_css('export-ui-list');
// TODO change to fcontrolpanel?
    drupal_add_css(drupal_get_path("module", "context_ui") ."/context_ui.css");
  }
  // */

  /*
  function list_render(&$form_state) {
// TODO change to fcontrolpanel?
    return theme('table', $this->list_table_header(), $this->rows, array('class' => 'fcontrolpanel-admin', 'id' => 'ctools-export-ui-list-items'));
  }
  // */

  /*
  function list_build_row($item, &$form_state, $operations) {
    $name = $item->name;
dsm($item);

    // Add a row for packages (feature sets, "tags" in context module).
    $tag = !empty($item->tag) ? $item->tag : t('< Untagged >');
//    $package = !empty($item->package) ? $item->tag : t('< Untagged >');
    if (!isset($this->rows[$tag])) {
      $this->rows[$tag]['data'] = array();
      $this->rows[$tag]['data'][] = array('data' => check_plain($tag), 'colspan' => 3, 'class' => 'tag');
      $this->sorts["{$tag}"] = $tag;
    }

    // Build row for each context item.
    $this->rows["{$tag}:{$name}"]['data'] = array();
    $this->rows["{$tag}:{$name}"]['class'] = !empty($item->disabled) ? 'ctools-export-ui-disabled' : 'ctools-export-ui-enabled';
    $this->rows["{$tag}:{$name}"]['data'][] = array(
      'data' => check_plain($name) . "<div class='description'>" . check_plain($item->description) . "</div>",
      'class' => 'ctools-export-ui-name'
    );
    $this->rows["{$tag}:{$name}"]['data'][] = array(
      'data' => check_plain($item->type),
      'class' => 'ctools-export-ui-storage'
    );
    $this->rows["{$tag}:{$name}"]['data'][] = array(
      'data' => theme('links', $operations, array('class' => 'links inline')),
      'class' => 'ctools-export-ui-operations'
    );

    // Sort by tag, name.
    $this->sorts["{$tag}:{$name}"] = $tag . $name;
  }
  // */
  
  /**
   * Override of edit_form_submit().
   * Don't copy values from $form_state['values'].
   */
  /*
  function edit_form_submit(&$form, &$form_state) {
    if (!empty($this->plugin['form']['submit'])) {
      $this->plugin['form']['submit']($form, $form_state);
    }
  }
  // */
}


