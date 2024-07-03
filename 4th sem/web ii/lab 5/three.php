<?php
// Initialize variables to store user input
$username = '';
$password = '';

// Check if the form is submitted
if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    // Retrieve user input from the form
    $username = $_POST['username'];
    $password = $_POST['password'];

    // Check if the provided username and password match the expected values
    if ($username === 'SuperUser' && $password === 'California') {
        $message = 'Authentication successful. Welcome, SuperUser!';
    } else {
        $message = 'Authentication failed. Please check your username and password.';
    }
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Login Form</title>
</head>
<body>

    <h2>Login Form</h2>

    <?php
    // Display authentication result message if available
    if (isset($message)) {
        echo '<p>' . $message . '</p>';
    }
    ?>

    <form method="post" action="<?php echo htmlspecialchars($_SERVER['PHP_SELF']); ?>">
        <label for="username">Username:</label>
        <input type="text" id="username" name="username" value="<?php echo htmlspecialchars($username); ?>" required>
        <br>

        <label for="password">Password:</label>
        <input type="password" id="password" name="password" required>
        <br>

        <input type="submit" value="Login">
    </form>

</body>
</html>
