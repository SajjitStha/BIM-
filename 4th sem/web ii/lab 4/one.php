<?php

class Triangle {
    private $side1;
    private $side2;
    private $side3;

    public function __construct($side1, $side2, $side3) {
        $this->side1 = $side1;
        $this->side2 = $side2;
        $this->side3 = $side3;
    }

    public function getPerimeter() {
        return $this->side1 + $this->side2 + $this->side3;
    }

    public function getArea() {
        // Using Heron's formula to calculate the area of the triangle
        $s = ($this->side1 + $this->side2 + $this->side3) / 2;
        return sqrt($s * ($s - $this->side1) * ($s - $this->side2) * ($s - $this->side3));
    }
}

// Example usage:
$triangle = new Triangle(3, 4, 5);
echo "Perimeter: " . $triangle->getPerimeter() . "\n";
echo "Area: " . $triangle->getArea() . "\n";
?>