<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Numbers up to 10</title>
    <style>
        table {
            border-collapse: collapse;
            width: 50%;
            margin: 20px;
        }
        th, td {
            border: 1px solid black;
            padding: 8px;
            text-align: center;
        }
        th {
            background-color: orange;
        }
    </style>
</head>
<body>

<?php
echo "<h2>Numbers up to 10 using for loop:</h2>";
echo "<table>";
echo "<tr><th>Number</th></tr>";

for ($i = 1; $i <= 10; $i++) {
    echo "<tr><td>$i</td></tr>";
}

echo "</table>";
?>

</body>
</html>


