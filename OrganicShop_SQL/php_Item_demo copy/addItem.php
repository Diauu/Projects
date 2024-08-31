<?php
//Diana Rios  


require './Service.php';

$service = new Service();

if ($_SERVER["REQUEST_METHOD"] == "POST"){
    $result = $service->addItem();
    echo $result; 
}
?>

<!DOCTYPE html>
<html>
<head>
<title> Add Item </title>
    </head>
    <body>
        <form method="post"> 
        <fieldset>
            <legend> Add Item</legend>

            <input type='text' name="iId" placeholder="Item ID" ></br>

            <input type="text" name="Iname" placeholder="Item Name" ></br>

            <input type="text" name="Sprice" placeholder="Item Price" ></br>

            <input id="button" type="submit" name="submit">
        </fieldset>
        <!-- <?= htmlspecialchars($result); ?> -->
    </body>

</html>