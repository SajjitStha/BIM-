<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Display First Twenty Letters</title>
</head>
<body>

<?php
// Input string
$inputString = "This is a sample sentence for demonstration purposes.";

// Function to get the first twenty letters with the last word complete
function displayFirstTwentyLetters($inputString) {
    // Get the first twenty letters
    $firstTwentyLetters = substr($inputString, 0, 20);

    // Find the position of the last space within the first twenty letters
    $lastSpacePosition = strrpos($firstTwentyLetters, ' ');

    // If a space is found, trim the string to the last space position
    if ($lastSpacePosition !== false) {
        $firstTwentyLetters = substr($firstTwentyLetters, 0, $lastSpacePosition);
    }

    // Display the result
    echo "<p>$firstTwentyLetters</p>";
}

// Call the function
displayFirstTwentyLetters($inputString);
?>

</body>
</html>
