<?php
/** 
 * @file
 * Provides form function for admin settings form
 */

/**
 * Form function
 */
function pharma_contact_admin_form($form, &$form_state) {

  $form['pharma_contact'] = array(
    '#title' => t('Address Details'),
    '#type' => 'fieldset',
    '#required' => TRUE,    
  );
  
  $form['pharma_contact']['pharma_contact_street'] = array(
    '#title' => t('Street - Nr'),
    '#type' => 'textfield',
    '#default_value' => variable_get('pharma_contact_street', ''),
    '#required' => TRUE,
  );
  
  $form['pharma_contact']['pharma_contact_postal_code'] = array(
    '#title' => t('Postal Code'),
    '#type' => 'textfield',
    '#default_value' => variable_get('pharma_contact_postal_code', ''),
    '#size' => 4,
    '#maxlength' => 4,
    '#required' => TRUE,
  );

  $form['pharma_contact']['pharma_contact_city'] = array(  
    '#title' => t('City'),
    '#type' => 'textfield',
    '#default_value' => variable_get('pharma_contact_city', ''),    
    '#required' => TRUE,
  );
  
  $form['pharma_contact_page'] = array(
    '#title' => t('Contact page (base - no translation)'),
    '#type' => 'select',
    '#options' => _pharma_contact_admin_get_nodes(),
    '#default_value' => variable_get('pharma_contact_page', 0),
    '#required' => TRUE,
  );
  
  return system_settings_form($form);
}


/**
 * Helper function for defining node options
 */
function _pharma_contact_admin_get_nodes() {
  $result = db_query("SELECT n.nid, n.language, nr.title FROM {node} n, {node_revision} nr WHERE n.nid = nr.nid;");
  $options = array();
  foreach ($result as $row) {
    $options[$row->nid] = $row->title . " (" . $row->language . ")";
  }
  
  return $options;
}