<!-- Use regular expressions to check if the email addresses exist in the paragraph and if yes display them all in the html list. -->
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>lab 3.6</title>
</head>
<body>
    <?php
        $email = "sajjit123@gmail.com"; 
        $pattern = "/^[a-zA-Z0-9._-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,4}$/";

        if(preg_match($pattern, $email)){
            echo "Yes"."<br>".$email;
        }
        else 
            echo"Email Format Invalid";
    ?>
</body>
</html>