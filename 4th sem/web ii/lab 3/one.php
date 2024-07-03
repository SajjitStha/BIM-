<!DOCTYPE html>
<html>
<head>
    <title>PHP Array Example</title>
</head>
<body>

<?php
// Create an array with the first 20 numbers
$numbers = array();
for ($i = 1; $i <= 20; $i++) {
    $numbers[] = $i;
}

// Display the array elements in an unordered list using foreach loop
echo '<ul>';
foreach ($numbers as $number) {
    echo '<li>' . $number . '</li>';
}
echo '</ul>';
?>

</body>
</html>
