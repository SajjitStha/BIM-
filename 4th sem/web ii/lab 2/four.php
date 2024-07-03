<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Number Selection</title>
</head>
<body>

<form>
    <label for="numberSelect">Select a number:</label>
    <select id="numberSelect" name="numberSelect">
        <?php
        // Using a for loop to generate options for numbers 1 to 10
        for ($i = 1; $i <= 10; $i++) {
            echo "<option value=\"$i\">$i</option>";
        }
        ?>
    </select>
</form>

</body>
</html>
