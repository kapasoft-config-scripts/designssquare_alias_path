<?php

function _display_basic_tapi($display){

    //the minimal of display instance

    if(isset($display->type)){
    $display_tapi = array();
    $display_tapi['name'] = $display->title;
    $display_tapi['url'] = base_path().drupal_get_path_alias('node/'.$display->nid);

    $display_tapi['details'] = array();
    $field = field_get_items('node', $display, 'field_display_description');
    $field_ins = (isset($field[0])) ? field_view_value('node', $display, 'field_display_description', $field[0]) : '';
    $display_tapi['details']['description'] = (isset($field_ins)) ? html_entity_decode(render($field_ins)) : '';
    $display_tapi['details']['link_text'] = t('Details');
    $display_tapi['details']['sharer_description'] = (isset($display_tapi['details']['description'])) ? urlencode(html_entity_decode( $display_tapi['details']['description'] , ENT_COMPAT, 'UTF-8')) : '';

    //link for social networks sharing
    $display_tapi['sharer_url'] = (isset($display_tapi['url'])) ? urlencode(html_entity_decode($display_tapi['url'], ENT_COMPAT, 'UTF-8')) : '';

    }else{
        //default to nothing
        $display_tapi = array();
        $display_tapi['name'] = 'Display Not Set';
        $display_tapi['url'] = '';

        $display_tapi['details'] = array();
        $display_tapi['details']['description'] = '';
        $display_tapi['details']['link_text'] = t('Details');
        $display_tapi['details']['sharer_description'] = '';

        //link for social networks sharing
        $display_tapi['sharer_url'] = '';
    }
    return $display_tapi;
}

function _display_complete_tapi($display){

    //all info for display instance
    $display_tapi = _display_basic_tapi($display);

    if(isset($display->type)){
    $display_tapi['seo'] = array();
    $field = field_get_items('node', $display, 'field_title_seo');
    $field_ins = field_view_value('node', $display, 'field_title_seo', $field[0]);
    $display_tapi['seo']['title'] = (isset($field[0])) ? render($field_ins) : '';
    $field = field_get_items('node', $display, 'field_description_seo');
    $field_ins = field_view_value('node', $display, 'field_description_seo', $field[0]);
    $display_tapi['seo']['description'] = (isset($field[0])) ? render($field_ins) : '';
    $field = field_get_items('node', $display, 'field_keywords_seo');
    $field_ins = field_view_value('node', $display, 'field_keywords_seo', $field[0]);
    $display_tapi['seo']['keywords'] = (isset($field[0])) ? render($field_ins) : '';

    $display_tapi['designer'] = array();
    $field = field_get_items('node', $display, 'field_designer_partnership');
    $field_ins = (isset($field[0])) ? field_view_value('node', $display, 'field_designer_partnership', $field[0]) : '';
    $display_tapi['designer']['is-partnership'] = (isset($field_ins['#title']) && $field_ins['#title'] == 'True') ? TRUE : FALSE;
    $field = field_get_items('node', $display, 'field_design_url');
    $field_ins = field_view_value('node', $display, 'field_design_url', $field[0]);
    $display_tapi['designer']['design-url'] = (isset($field[0])) ? render($field_ins) : '';

    }else{
        //display not set. default
        $display_tapi['seo'] = array();
        $display_tapi['seo']['title'] = '';
        $display_tapi['seo']['description'] = '';
        $display_tapi['seo']['keywords'] = '';

        $display_tapi['designer'] = array();
        $display_tapi['designer']['is-partnership'] =  FALSE;
        $display_tapi['designer']['design-url'] = '';

    }
    return $display_tapi;
}

function _product_basic_tapi($product){
    //minimal info to display product teasers
    $product_tapi = array();
    $product_tapi['img'] = array();
    $field = field_get_items('commerce_product', $product, 'field_featured_image');
    $product_tapi['img']['url'] = (isset($field[0]['uri']) && !empty($field[0]['uri'])) ? url('sites/default/files/'.file_uri_target($field[0]['uri']), array('absolute'=>true)) : base_path().path_to_theme().'/images/default-product-image.jpg';
    $product_tapi['img']['alt'] = (isset($field[0]['alt']) && !empty($field[0]['alt'])) ? $field[0]['alt'] : '';

    $product_tapi['discount']=array();
    $field = field_get_items('commerce_product', $product, 'field_is_on_sale');
    $field_ins = field_view_value('commerce_product', $product, 'field_is_on_sale', $field[0]);
    $product_tapi['discount']['is-on-sale'] = (isset($field_ins['#title']) && $field_ins['#title'] == 'True') ?  TRUE : FALSE;
    $field = field_get_items('commerce_product', $product, 'field_prior_sales_price');
    $field_ins = field_view_value('commerce_product', $product, 'field_prior_sales_price', $field[0]);
    $product_tapi['discount']['prior-sales-price'] = (isset($field_ins) ) ?  render($field_ins) : '';
    $product_tapi['discount']['sale-img-url'] = base_path().drupal_get_path('module','designssquare_com_commerce')."/images/bazar/bullets/sale.png";

    $field = field_get_items('commerce_product', $product, 'field_is_new_product');
    $field_ins = field_view_value('commerce_product', $product, 'field_is_new_product', $field[0]);
    $product_tapi['is-new-product'] = (isset($field_ins['#title']) && $field_ins['#title'] == 'True') ?  TRUE : FALSE;
    $product_tapi['new-product-img-url'] = base_path().drupal_get_path('module','designssquare_com_commerce')."/images/bazar/bullets/new.png";


    $field = field_get_items('commerce_product', $product, 'field_product_description');
    $field_ins = field_view_value('commerce_product', $product, 'field_product_description', $field[0]);
    $product_tapi['details']['description'] = (isset($field_ins)) ?  html_entity_decode(render($field_ins)) : '';
    $product_tapi['details']['description-summary'] = (isset($field[0]['summary'])) ?  html_entity_decode(render($field[0]['summary'])) : '';
//    $product_tapi['details']['url'] = base_path().drupal_get_path_alias('node/'.$display_node_id);//this has to be set outside the scope the id of node
    $product_tapi['details']['link_text'] = t('Details');
//    $product_tapi['details']['sharer_description'] = urlencode(html_entity_decode( $product_tapi['details']['description'] , ENT_COMPAT, 'UTF-8'));

    //product name
    $product_tapi['name'] = $product->title;
//    $product_tapi['url'] = base_path().drupal_get_path_alias('node/'.$display_node_id);

    $price = commerce_product_calculate_sell_price($product);
    $product_tapi['price'] = commerce_currency_format($price['amount'], $price['currency_code'], $product);
    $product_tapi['currency'] = $price['currency_code'];

    $product_tapi['wishlist']['url'] = '';
    $product_tapi['wishlist']['link_text'] = t('Wishlist');

    return $product_tapi;
}

function _add_to_cart_tapi($product){

    $display_id = (isset($product->display_id) && is_numeric($product->display_id)) ? $product->display_id : get_referencing_product_display_id($product);
    $display = (isset($display_id) && is_numeric($display_id)) ? node_load($display_id) : null;
    $add_to_cart_form = field_view_field(
        'node',
        $display,
        'field_product',
        array(
            'type' => 'commerce_cart_add_to_cart_form',
            'label' => 'hidden',
            'settings' => array(
                'show_quantity' => FALSE,
                'default_quantity' => 1,
                'combine' => TRUE,
                'show_single_product_attributes' => FALSE,
                'line_item_type' => 'product',
            ),
        )
    );

//    $add_to_cart = (isset($display)) ? render($add_to_cart_form) : null;
    $form = $add_to_cart_form[0];


    $product_tapi = array();
//    $form_name = 'commerce_cart_add_to_cart_form';
//    $form_id_input = $form_name.'_'.$product->product_id;
//    $data = array(
//        'context'=>array(
//            'display_path' => base_path().$_GET['q'],
//            'product_ids' => array($product->product_id),
//        )
//    );
//    $line_item = commerce_product_line_item_new($product,1,0,$data);
//    $form = drupal_get_form($form_name, $line_item);
    $product_tapi['action'] = $form['#action'];
//    $form['form_id']['#value'] = $form_id_input;
    $product_tapi['form_id_rendered'] = render($form['form_id']);
    $product_tapi['form_id'] = $form['#id'];
    $product_tapi['product_id'] = $product->product_id;
    $product_tapi['form_build_id'] = render($form['form_build_id']);
    $product_tapi['link_text'] = t('Add To Cart');
//    $product_tapi = array();
//    $form_name = 'commerce_cart_add_to_cart_form';
//    $form_id_input = $form_name.'_'.$product->product_id;
//    $data = array(
//        'context'=>array(
//            'display_path' => base_path().$_GET['q'],
//            'product_ids' => array($product->product_id),
//        )
//    );
//    $line_item = commerce_product_line_item_new($product,1,0,$data);
//    $form = drupal_get_form($form_name, $line_item);
//    $product_tapi['action'] = $form['#action'];
//    $form['form_id']['#value'] = $form_id_input;
//    $product_tapi['form_id_rendered'] = render($form['form_id']);
//    $product_tapi['form_id'] = str_replace('_','-',$form_id_input);
//    $product_tapi['product_id'] = $product->product_id;
//    $product_tapi['form_build_id'] = render($form['form_build_id']);
//    $product_tapi['link_text'] = t('Add To Cart');

    return $product_tapi;
}

function _product_complete_tapi($product, $display_node_id = Null){
    //all info to display product in its own section
    $product_tapi = _product_basic_tapi($product, $display_node_id);
    $product_tapi['img-magnified']=array();
    $field = field_get_items('commerce_product', $product, 'field_featured_image_magnified');
    $product_tapi['img-magnified']['url'] = (isset($field[0]['uri']) && !empty($field[0]['uri'])) ? url('sites/default/files/'.file_uri_target($field[0]['uri']), array('absolute'=>true)) : '';
    $product_tapi['img-magnified']['alt'] = (isset($field[0]['alt']) && !empty($field[0]['alt'])) ? $field[0]['alt'] : '';

    $product_tapi['additional_info'] = array();
    $field = field_get_items('commerce_product', $product, 'field_drupal_version');
    $field_ins = field_view_value('commerce_product', $product, 'field_drupal_version', $field[0]);
    $product_tapi['additional_info']['drupal_version'] = (isset($field_ins['#title'])) ? $field_ins['#title'] : '';

    $field = field_get_items('commerce_product', $product, 'field_mobile_support');
    $field_ins = field_view_value('commerce_product', $product, 'field_mobile_support', $field[0]);
    $product_tapi['additional_info']['mobile_support'] = (isset($field_ins['#title']) && $field_ins['#title'] == 'Responsive') ?  'Yes' : 'No';

    $field = field_get_items('commerce_product', $product, 'field_design_framework');
    $field_ins = field_view_value('commerce_product', $product, 'field_design_framework', $field[0]);
    $product_tapi['additional_info']['design_framework'] = (isset($field_ins['#title'])) ? $field_ins['#title'] : '';

    $price = commerce_product_calculate_sell_price($product);
    $product_tapi['price'] = commerce_currency_format($price['amount'], $price['currency_code'], $product);
    $product_tapi['currency'] = $price['currency_code'];

    $category_list = array();
    $field = field_get_items('commerce_product', $product, 'field_product_category');
    if($field){
        foreach($field as $key => $category_ins){
            $category = field_view_value('commerce_product', $product, 'field_product_category', $category_ins);
            $category_list[] = $category['#title'];
        }
    }
    $product_tapi['categories'] = $category_list;

    $product_tapi['demo'] = array();
    $field = field_get_items('commerce_product', $product, 'field_demo_url');
    $demo_url_rendearable = field_view_value('commerce_product', $product, 'field_demo_url', $field[0]);
    $product_tapi['demo']['url'] = (isset($field[0])) ? render($demo_url_rendearable) : '';

    $field = field_get_items('commerce_product', $product, 'field_hide_demo_header');
    $field_ins = field_view_value('commerce_product', $product, 'field_hide_demo_header', $field[0]);
        $product_tapi['demo']['hide_header'] = (isset($field['#title']) && $field['#title'] == 'True') ? TRUE : FALSE;

    return $product_tapi;
}

//prepare user related variables for the html.tpl file
function _header_tapi_user(){
    global $user;
    if($user->uid){
        //authenticated user
        $url = 'user/logout';
        $content = 'Logout';
        $profile_url = 'user';
        $profile_content = $user->name;
        $authenticated = True;
    }else{
        $url = 'user';
        $content = 'Login';
        $authenticated = False;
        $profile_url = '';
        $profile_content = '';
    }

    return array(
        'login' => array(
            'url' => $url,
            'text' => $content,
        ),
        'profile' => array(
            'url' => $profile_url,
            'text' => $profile_content,
        ),
        'is_authenticated' => $authenticated,
    );
}

//prepare site related variables for the html.tpl file
//function _basic_tapi($node){
//    return array(
//        'slogan' => (!empty($node->field_slogan)) ? $node->field_slogan[LANGUAGE_NONE][0]['value'] : '',
//        'title' => (!empty($node->title)) ? $node->title : '',
//    );
//}
function _basic_tapi($node){
    $field = field_get_items('node', $node, 'field_page_slogan');
    $slogan = field_view_value('node', $node, 'field_page_slogan', $field[0]);

    return array(
        'title' => !empty($node->title) ? $node->title : '',
        'body' => !empty($node->body) ? $node->body: '',
        'slogan' => !empty($slogan) ? render($slogan) : '',
    );
}

function _simple_tapi($vars){
    return array(
        'title' => !empty($vars['title']) ? $vars['title'] : '',
        'body' => !empty($vars['body']) ? $vars['body']: '',
        'slogan' => !empty($vars['slogan']) ? $vars['slogan'] : '',
    );
}


function _checkout_tapi($node){
    $field = field_get_items('node', $node, 'field_checkout_message');
    $checkout_message = render(field_view_value('node', $node, 'field_checkout_message', $field[0]));
    $basic = _basic_tapi($node);
    $checkout_tapi = array(
        'checkout_message' =>($checkout_message) ? $checkout_message : '',
    );
    return array_merge($basic, $checkout_tapi);
}


//prepare site related variables for the html.tpl file
function _header_tapi_site(){
    $logo_path = theme_get_setting('logo');
    $path_to_home = base_path().variable_get('site_frontpage', 'node');
    $site_name = (theme_get_setting('toggle_name') ? variable_get('site_name', 'Designs <span class="title-highlight">Square</span>') : 'Designs <span class="title-highlight">Square</span>');
    $slogan = (variable_get('site_slogan')) ? variable_get('site_slogan') : 'slogan is not set';

    return array(
        'slogan' => $slogan,
        'site_name' => $site_name,
        'home_url' => $path_to_home,
        'logo_path' => $logo_path,
    );
}

function _search_tapi(){
    $form = array();
    $search_form_array = drupal_get_form('search_block_form');
    //form specific
    $form['id'] = str_replace('_','-',$search_form_array['#form_id']);
    $form['action'] = $search_form_array['#action'];

    //search key input field
    $form['search_id'] = $search_form_array['search_block_form']['#id'];
    $form['search_name'] = $search_form_array['search_block_form']['#name'];

    //submit input field
    $form['submit_name'] = 'op';
    $form['submit_id'] = 'edit-submit';

    //hidden fields
    $form['hidden_input'] = render($search_form_array['form_build_id']);
    $form['hidden_input2'] = render($search_form_array['form_id']);
    $form['hidden_input3'] = (isset($search_form_array['form_token'])) ? render($search_form_array['form_token']) : '';
    return $form;
}


function _contact_tapi(){
    $contact_tapi = array();
    require_once drupal_get_path('module', 'contact') .'/contact.pages.inc';
    $contact_form_array = drupal_get_form('contact_site_form');
    //form specific
    $contact_tapi['id'] = str_replace('_','-',$contact_form_array['#form_id']);
    $contact_tapi['action'] = $contact_form_array['#action'];

    //name input field
    $contact_tapi['name_name'] = $contact_form_array['name']['#name'];
    //subject input field
    $contact_tapi['subject_name'] = $contact_form_array['subject']['#name'];
    $contact_tapi['subject_value'] = 'From '.$_SERVER['HTTP_HOST'];
    //email input field
    $contact_tapi['email_name'] = $contact_form_array['mail']['#name'];
    //message input field
    $contact_tapi['message_name'] = $contact_form_array['message']['#name'];

    //submit input field
    $contact_tapi['submit_name'] = 'op';
    $contact_tapi['submit_id'] = 'edit-submit';

    //category_field
//    $contact_tapi['category'] = render($contact_form_array['cid']);

    //hidden fields
    $contact_tapi['hidden_input'] = render($contact_form_array['form_build_id']);
    $contact_tapi['hidden_input2'] = render($contact_form_array['form_id']);
    $contact_tapi['hidden_input3'] = (isset($contact_form_array['form_token'])) ? render($contact_form_array['form_token']) : '';
    return $contact_tapi;
}
