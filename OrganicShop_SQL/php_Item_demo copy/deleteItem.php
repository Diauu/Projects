<?php
//Diana Rios  


require './Service.php';

$service = new Service();

if ($_SERVER["REQUEST_METHOD"] == "POST"){
    $result = $service->deleteItem();
    
    echo $result;
}
?>

<!DOCTYPE html>
<html>
<head>
<title> Delete Item </title>
    </head>
    <body>
        <form method="post">
        <fieldset>
            <legend> Delete Item</legend>

            <input type="text" name="Iname" placeholder="Item name"></br> 

            <input id="button" type="submit" name="submit">
        </fieldset>
        <!-- <?= htmlspecialchars($result); ?> -->
    </body>

</html>