<?php

// Define the time intervals for each traffic light state
$greenLightDuration = 50;  // seconds
$yellowLightDuration = 5;  // seconds
$redLightDuration = 50;    // seconds

// Simulate sound detection (this could be replaced with a real check)
$soundDetected = false; // Set this to true to simulate sound detection

// Function to simulate the sound detection mechanism
function isSoundDetected() {
    global $soundDetected;
    return $soundDetected;
}

// Get the current time in seconds since the Unix Epoch
$currentTime = time();

// Calculate the elapsed time in the current cycle
$elapsedTime = $currentTime % ($greenLightDuration + $yellowLightDuration + $redLightDuration);

// Check if sound is detected and override the traffic light state if true
if (isSoundDetected()) {
    $trafficLight = 'Green'; // Override to Green if sound is detected
} else {
    // Determine the traffic light state based on elapsed time
    if ($elapsedTime < $greenLightDuration) {
        $trafficLight = 'Green';
    } elseif ($elapsedTime < $greenLightDuration + $yellowLightDuration) {
        $trafficLight = 'Yellow';
    } else {
        $trafficLight = 'Red';
    }
}

// Generate the HTML for the traffic light
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Traffic Light Simulation</title>
    <style>
        body {
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
            margin: 0;
            background-color: #f0f0f0;
        }
        .traffic-light {
            width: 100px;
            height: 300px;
            background-color: #333;
            border-radius: 20px;
            display: flex;
            flex-direction: column;
            align-items: center;
            justify-content: space-around;
            padding: 10px;
        }
        .light {
            width: 80px;
            height: 80px;
            border-radius: 50%;
            background-color: #555;
            border: 5px solid #000;
        }
        .green {
            background-color: <?php echo ($trafficLight == 'Green') ? '#0f0' : '#555'; ?>;
        }
        .yellow {
            background-color: <?php echo ($trafficLight == 'Yellow') ? '#ff0' : '#555'; ?>;
        }
        .red {
            background-color: <?php echo ($trafficLight == 'Red') ? '#f00' : '#555'; ?>;
        }
    </style>
</head>
<body>
    <div class="traffic-light">
        <div class="light red"></div>
        <div class="light yellow"></div>
        <div class="light green"></div>
    </div>
</body>
</html>