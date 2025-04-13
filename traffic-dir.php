<!-- -->
<!DOCTYPE html>
<html>
<head>
    <title>Traffic Light Control</title>
    <meta http-equiv="refresh" content="5"> <!-- Auto-refresh every 5 seconds -->
    <style>
        body {
            font-family: Arial, sans-serif;
            text-align: center;
            background-color: #f4f4f4;
            margin: 50px;
        }

        h1 {
            color: #333;
        }

        .traffic-light {
            width: 100px;
            background-color: #222;
            padding: 10px;
            border-radius: 10px;
            margin: 20px auto;
            display: flex;
            flex-direction: column;
            align-items: center;
        }

        .light {
            width: 50px;
            height: 50px;
            margin: 5px;
            border-radius: 50%;
            background-color: #444;
        }

        .red { background-color: red; }
        .yellow { background-color: yellow; }
        .green { background-color: green; }

        .controls {
            margin-top: 20px;
        }

        button {
            background-color: #007BFF;
            color: white;
            border: none;
            padding: 10px 20px;
            margin: 5px;
            cursor: pointer;
            font-size: 16px;
            border-radius: 5px;
        }

        button:hover {
            background-color: #0056b3;
        }

        .current-direction {
            font-size: 18px;
            margin-top: 20px;
            font-weight: bold;
            color: #333;
        }
    </style>
</head>
<body>

<h1>Traffic Light Direction Control</h1>

<?php
$filename = 'direction.txt';
$direction = '';

// Save POST data to file if available
if ($_SERVER['REQUEST_METHOD'] == 'POST' && isset($_POST['direction'])) {
    $direction = strtoupper(trim($_POST['direction']));
    file_put_contents($filename, $direction);
} elseif (file_exists($filename)) {
    $direction = strtoupper(trim(file_get_contents($filename)));
}
?>

<div class="traffic-light">
    <div class="light <?php echo ($direction == 'NA') ? 'red' : ''; ?>"></div>
    <div class="light <?php echo ($direction == 'CAR') ? 'yellow' : ''; ?>"></div>
    <div class="light <?php echo ($direction == 'NS') ? 'green' : ''; ?>"></div>
</div>

<div class="current-direction">
    <?php
        if ($direction) {
            echo "Current Direction: <b>$direction</b>";
        } else {
            echo "No direction set.";
        }
    ?>
</div>

</body>
</html>
