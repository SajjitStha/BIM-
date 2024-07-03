<?php

abstract class Shape {
    abstract public function getArea();
}

class Rectangle extends Shape {
    private $length;
    private $width;

    public function __construct($length, $width) {
        $this->length = $length;
        $this->width = $width;
    }

    public function getArea() {
        return $this->length * $this->width;
    }
}

class Circle extends Shape {
    private $radius;

    public function __construct($radius) {
        $this->radius = $radius;
    }

    public function getArea() {
        return pi() * $this->radius * $this->radius;
    }
}

class Triangle extends Shape {
    private $base;
    private $height;

    public function __construct($base, $height) {
        $this->base = $base;
        $this->height = $height;
    }

    public function getArea() {
        return 0.5 * $this->base * $this->height;
    }
}

// Example usage:
$rectangle = new Rectangle(4, 5);
echo "Area of Rectangle: " . $rectangle->getArea() ."\n";

$circle = new Circle(3);
echo "Area of Circle: " . $circle->getArea() ."\n";

$triangle = new Triangle(4, 6);
echo "Area of Triangle: " . $triangle->getArea() ."\n";

?>