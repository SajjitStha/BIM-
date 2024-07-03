<?php

class Calculator {
    public function add($num1, $num2) {
        return $num1 + $num2;
    }

    public function subtract($num1, $num2) {
        return $num1 - $num2;
    }

    public function multiply($num1, $num2) {
        return $num1 * $num2;
    }

    public function divide($num1, $num2) {
        // Check if attempting to divide by zero
        if ($num2 == 0) {
            return "Cannot divide by zero!";
        }
        
        return $num1 / $num2;
    }
}

// Example usage:
$calculator = new Calculator();

// Perform calculations
$sum = $calculator->add(5, 3);
$difference = $calculator->subtract(8, 4);
$multiplication = $calculator->multiply(2, 6);
$division = $calculator->divide(10, 2);

// Display results
echo "Sum: $sum\n";
echo "Difference: $difference\n";
echo "Multiplication: $multiplication\n";
echo "Division: $division\n";

?>
