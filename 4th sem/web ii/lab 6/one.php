<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>lab 6.1</title>
</head>
<body>
    <?php 
        $dbname = "";
        $message = "";
        $color = "red";

        if($_SERVER['REQUEST_METHOD'] === 'POST'){
            $dbname = $_POST['dbname'];
            $serverName = "localhost";
            $username = 'root';
            $password = '';

            $conn = new mysqli($serverName, $username, $password);
            if($conn->connect_error){
                $message = "Error Connecting to Database: " . $conn->connect_error;
                die();
            }         

            $createQuery = "CREATE DATABASE $dbname";
            try{
                if($conn->query($createQuery) === TRUE){
                    $message = "Database $dbname Created Succesfully";
                    $color = "green";
                }
            }
            catch(Exception $err){
                $message = "Error Creating Database: " . $err;
            }

            $conn->close();
        }
    ?>

    <form method="POST" action="<?php echo htmlspecialchars($_SERVER['PHP_SELF']); ?>">
        <label for="dbname">Database Name: </label>
        <input type="text" name="dbname" value="<?php echo $dbname; ?>" /> <br><br>

        <input type="submit" />
    </form> <br>
    <span style="color: <?php echo $color ?>;"><?php echo $message ?></span>
</body>
</html>
