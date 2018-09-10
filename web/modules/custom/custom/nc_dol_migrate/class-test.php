<?php
class BaseClass {
    public function __construct($arguments) {
        print 'In BaseClass constructor<br>';
        print ($arguments . ' <- argument of baseclass<br>');
    }
}

class SubClass extends BaseClass {
    public function __construct($arguments) {
        parent::__construct($arguments);
        print 'In SubClass constructor<br>';
        print $arguments . ' <- argument of subclass<br>';
    }
}

$class = 'SubClass';
$instance = new $class('test');
echo($instance);
var_dump('test');