<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Sorted Class and Students Table</title>
    <style>
        table {
            border-collapse: collapse;
            width: 20%;
            margin: 20px;
        }
        th, td {
            border: 1px solid black;
            padding: 8px;
            text-align: center;
        }
    </style>
</head>
<body>
    <h2> Sorted Class and Students Table</h2>
    <table border="2">
        
            <tr>
                <th>Class</th>
                <th>Students count</th>
            </tr>
        
      
            <?php
            
            $classData = [
                '2A' => 30,
                '3A' => 35,
                '4A' => 45,
                '2B' => 40,
                '3B' => 25,
                '4B' => 30
            ];

            asort($classData);
           

            foreach( $classData as $class => $studentCount) {
                echo "<tr>";
                echo "<td>$class</td>";
                echo "<td>$studentCount</td>";
                echo "</tr>";
            }
            ?>
        
    </table>
</body>
</html>
