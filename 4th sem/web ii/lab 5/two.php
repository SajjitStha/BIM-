<?php


// Set default values
$defaultUsername = "Sajjit";
$defaultPassword = "12345";
$defaultEmail = "sajjitshrestha@gmail.com";
$defaultGender = "Male";
$defaultCountry = "Nepal";
$defaultHobbies = "Sketching";


// Check if the form is submitted
if ($_SERVER["REQUEST_METHOD"] == "POST") {
   


    $username = htmlspecialchars($_POST["username"]);
    $password = htmlspecialchars($_POST["password"]);
    $email = filter_var($_POST["email"], FILTER_VALIDATE_EMAIL);
    $gender = htmlspecialchars($_POST["gender"]);
    $country = htmlspecialchars($_POST["country"]);
    $hobbies = htmlspecialchars($_POST["hobbies"]);


    // Check if email is valid
    if (!$email) {
        die("Invalid email address");
    }


    // Display user input in a table
    echo "<h2>User Information</h2>";
    echo "<table border='1'>";
    echo "<tr><th>Field</th><th>Value</th></tr>";
    echo "<tr><td>Username</td><td>$username</td></tr>";
    echo "<tr><td>Password</td><td>$password</td></tr>";
    echo "<tr><td>Email</td><td>$email</td></tr>";
    echo "<tr><td>Gender</td><td>$gender</td></tr>";
    echo "<tr><td>Country</td><td>$country</td></tr>";
    echo "<tr><td>Hobbies</td><td>$hobbies</td></tr>";
    echo "</table>";
    exit();
}
?>


<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>User Input Form</title>
</head>
<body>
    <form action="<?php echo $_SERVER['PHP_SELF']; ?>" method="post">
        <label for="username">Username:</label>
        <input type="text" name="username" value="<?php echo isset($username) ? $username : $defaultUsername; ?>" required><br>


        <label for="password">Password:</label>
        <input type="password" name="password" value="<?php echo isset($password) ? $password : $defaultPassword; ?>" required><br>


        <label for="email">Email:</label>
        <input type="email" name="email" value="<?php echo isset($email) ? $email : $defaultEmail; ?>" required><br>


        <label for="gender">Gender:</label>
        <select name="gender" required>
            <option value="male" <?php echo (isset($gender) && $gender == "male") ? "selected" : ""; ?>>Male</option>
            <option value="female" <?php echo (isset($gender) && $gender == "female") ? "selected" : ""; ?>>Female</option>
        </select><br>


        <label for="country">Country:</label>
        <input type="text" name="country" value="<?php echo isset($country) ? $country : $defaultCountry; ?>" required><br>


        <label for="hobbies">Hobbies:</label>
        <input type="text" name="hobbies" value="<?php echo isset($hobbies) ? $hobbies : $defaultHobbies; ?>" required><br>


        <input type="submit" value="Submit">
    </form>
</body>
</html>
