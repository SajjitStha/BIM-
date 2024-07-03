<!DOCTYPE html>
<html>
<head>
    <title>Student Grades</title>
    <style>
        table {
            border-collapse: collapse;
            width: 50%;
            margin: 20px;
        }

        table, th, td {
            border: 1px solid black;
        }

        th, td {
            padding: 10px;
            text-align: left;
        }
    </style>
</head>
<body>

<?php
// Define the table data in a PHP array
$tableData = array(
    array('Name', 'English', 'WT', 'DSA'),
    array('Peter', 30, 75, 70),
    array('Ben', 90, 85, 80),
    array('Joe', 85, 70, 60)
);

// Display the table using HTML
echo '<table>';
foreach ($tableData as $row) {
    echo '<tr>';
    foreach ($row as $cell) {
        echo '<td>' . $cell . '</td>';
    }
    echo '</tr>';
}
echo '</table>';
?>

</body>
</html>
