<?php
//Diana Rios  


require './Service.php';

$service = new Service();

if ($_SERVER["REQUEST_METHOD"] == "POST"){
    $result = $service->updateItem(); 
    echo $result;
}
?>

<!DOCTYPE html>
<html>
<head>
<title> Update Item </title>
    </head>
    <body>
        <form method="post">
        <fieldset>
            <legend> Update Item</legend>

            <input type="text" name="Iname" placeholder="Old Name"></br>

            <input type="text" name="NewName" placeholder="New Name" ></br>

            <input id="button" type="submit" name="submit">
        </fieldset>
        <!-- <?= htmlspecialchars($result); ?> -->
    </body>

</html>