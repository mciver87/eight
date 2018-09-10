function overflowmenu_extension() {
  $('.topical-nav').addClass('jb-overflow-disabled');
  
  // Detect overflow menu to see if items exist
  if ( $('.jb-overflowmenu-menu-secondary > li').length ) {
  	// If container has items, show it
    $('.topical-nav').overflowmenu('refresh');
    $('.topical-nav').removeClass('jb-overflow-disabled');
    $('.topical-nav').overflowmenu('refresh');
  }
  
}