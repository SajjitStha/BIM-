<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Ordered Bill</title>
</head>
<body>

<?php
// Define item details
$items = array(
    array("Hamburger", 2, 150.99),
    array("Sandwich", 2, 100.95)
);

// Initialize variables for total amounts, service charge, and discount
$totalAmount = 0;
$serviceChargePercentage = 0.1; // 10%
$discountPercentage = 0.07; // 7%

// Display table headers
echo "<table border='1'>
        <tr>
            <th>Item</th>
            <th>Quantity</th>
            <th>Rate</th>
            <th>Total</th>
        </tr>";

// Display items and calculate totals
foreach ($items as $item) {
    $itemName = $item[0];
    $quantity = $item[1];
    $rate = $item[2];
    
    $itemTotal = $quantity * $rate;
    $totalAmount += $itemTotal;

    echo "<tr>
            <td>$itemName</td>
            <td>$quantity</td>
            <td>$rate</td>
            <td>$itemTotal</td>
        </tr>";
}

// Calculate service charge
$serviceCharge = $totalAmount * $serviceChargePercentage;
$totalAmount += $serviceCharge;

// Calculate discount
$discount = $totalAmount * $discountPercentage;
$totalAmount -= $discount;

// Display service charge and discount rows
echo "<tr>
        <td colspan='3'>Service Charge (10%)</td>
        <td>$serviceCharge</td>
    </tr>
    <tr>
        <td colspan='3'>Discount (7%)</td>
        <td>-$discount</td>
    </tr>";

// Display Grand Total
echo "<tr>
        <td colspan='3'>Grand Total</td>
        <td>$totalAmount</td>
    </tr>";

// Close the table
echo "</table>";
?>

</body>
</html>
