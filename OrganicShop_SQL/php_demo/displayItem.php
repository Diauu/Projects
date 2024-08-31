<?php

//Diana Rios  


require './Service.php';


$service = new Service();

// Initializing variables
$results = [];
$message = '';

// Check for the Iname
if (isset($_POST["name"])) {
    $search_input = $_POST['name'];

    if (!empty($search_input)) {
        $results = $service->fetchAllItems($search_input, true);

     
    } 
}

// Check for iId
if (isset($_POST["id"])) {
    $search_input = $_POST['id'];

    if (!empty($search_input)) {
        $results = $service->fetchAllItems($search_input, false);

       
    } 
}

?>

<!DOCTYPE html>
<html>
<head>
<title>Search Item</title>
    </head>
    <body>
        <form method="post"> 
            <fieldset>
            <legend>Search Item</legend>  
                <H2>ITEM Name</H2>
                <label for="name">Item Name:</label>
                <input type="text" id="name" placeholder="Item Name" name="name"> 
                <input type="submit" value="Search">
                <br><br> 
                <h2>OR<h2>
                <H2> ITEM ID</H2>
                <label for="id">Item ID:</label>
                <input type="text" id="id" placeholder="Item ID" name="id">
                <input type="submit" value="Search">
            <fieldset>
        </form>
    

    <?php
    //  message 
    if (!empty($message)) {
        echo "<p>$message</p>";
    }

    // search results Display
    if (!empty($results)) {
        echo "<h3>Results:</h3>";
        foreach ($results as $result) {
            echo "Item Name: " . $result["Iname"] . "<br>";
            echo "Item ID: " . $result["iId"] . "<br>";
            echo "Item Price:". $result["Sprice"]. "<br>";

        }
    }
    ?>
</body>
</html>

