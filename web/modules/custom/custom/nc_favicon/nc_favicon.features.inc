<?php
/**
 * @file
 * nc_favicon.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function nc_favicon_image_default_styles() {
  $styles = array();

    // Exported image style: favicon16.
  $styles['favicon16'] = array(
    'label' => 'favicon16',
    'effects' => array(
      2 => array(
        'name' => 'image_resize',
        'data' => array(
          'width' => 16,
          'height' => 16,
        ),
        'weight' => 1,
      ),
    ),
  );

   // Exported image style: favicon32.
  $styles['favicon32'] = array(
    'label' => 'favicon32',
    'effects' => array(
      2 => array(
        'name' => 'image_resize',
        'data' => array(
          'width' => 32,
          'height' => 32,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: favicon48.
  $styles['favicon48'] = array(
    'label' => 'favicon48',
    'effects' => array(
      2 => array(
        'name' => 'image_resize',
        'data' => array(
          'width' => 48,
          'height' => 48,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: favicon57.
  $styles['favicon57'] = array(
    'label' => 'favicon57',
    'effects' => array(
      1 => array(
        'name' => 'image_resize',
        'data' => array(
          'width' => 57,
          'height' => 57,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: favicon60.
  $styles['favicon60'] = array(
    'label' => 'favicon60',
    'effects' => array(
      2 => array(
        'name' => 'image_resize',
        'data' => array(
          'width' => 60,
          'height' => 60,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: favicon72.
  $styles['favicon72'] = array(
    'label' => 'favicon72',
    'effects' => array(
      2 => array(
        'name' => 'image_resize',
        'data' => array(
          'width' => 72,
          'height' => 72,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: favicon76.
  $styles['favicon76'] = array(
    'label' => 'favicon76',
    'effects' => array(
      2 => array(
        'name' => 'image_resize',
        'data' => array(
          'width' => 76,
          'height' => 76,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: favicon96.
  $styles['favicon96'] = array(
    'label' => 'favicon96',
    'effects' => array(
      2 => array(
        'name' => 'image_resize',
        'data' => array(
          'width' => 96,
          'height' => 96,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: favicon114.
  $styles['favicon114'] = array(
    'label' => 'favicon114',
    'effects' => array(
      2 => array(
        'name' => 'image_resize',
        'data' => array(
          'width' => 114,
          'height' => 114,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: favicon120.
  $styles['favicon120'] = array(
    'label' => 'favicon120',
    'effects' => array(
      2 => array(
        'name' => 'image_resize',
        'data' => array(
          'width' => 120,
          'height' => 120,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: favicon144.
  $styles['favicon144'] = array(
    'label' => 'favicon144',
    'effects' => array(
      2 => array(
        'name' => 'image_resize',
        'data' => array(
          'width' => 144,
          'height' => 144,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: favicon152.
  $styles['favicon152'] = array(
    'label' => 'favicon152',
    'effects' => array(
      2 => array(
        'name' => 'image_resize',
        'data' => array(
          'width' => 152,
          'height' => 152,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: favicon60.
  $styles['favicon180'] = array(
    'label' => 'favicon180',
    'effects' => array(
      2 => array(
        'name' => 'image_resize',
        'data' => array(
          'width' => 180,
          'height' => 180,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: favicon192.
  $styles['favicon192'] = array(
    'label' => 'favicon192',
    'effects' => array(
      2 => array(
        'name' => 'image_resize',
        'data' => array(
          'width' => 192,
          'height' => 192,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
