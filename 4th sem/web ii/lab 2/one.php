<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Web Technology Marks</title>
    <style>
        table {
            border-collapse: collapse;
            width: 50%;
            margin: 20px;
        }
        th, td {
            border: 1px solid black;
            padding: 8px;
            text-align: left;
        }
        th {
            background-color: orange;
        }
    </style>
</head>
<body>

<?php
// Array of marks for 5 students
$marks = array(85, 72, 90, 65, 78);

// Using for loop to display marks in an HTML table
echo "<h2>Using for loop:</h2>";
echo "<table>";
echo "<tr><th>Student</th><th>Marks</th></tr>";
for ($i = 0; $i < count($marks); $i++) {
    echo "<tr><td>Student " . ($i + 1) . "</td><td>" . $marks[$i] . "</td></tr>";
}
echo "</table>";

// Using foreach loop to display marks in an HTML table
echo "<h2>Using foreach loop:</h2>";
echo "<table>";
echo "<tr><th>Student</th><th>Marks</th></tr>";
foreach ($marks as $index => $value) {
    echo "<tr><td>Student " . ($index + 1) . "</td><td>" . $value . "</td></tr>";
}
echo "</table>";
?>

</body>
</html>
