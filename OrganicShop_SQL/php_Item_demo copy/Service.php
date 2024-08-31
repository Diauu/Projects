<?php
//Diana Rios  


require './Database.php';
require './Item.php';

class Service {

    function fetchAllItems($identifier,$byName=true) {
		
		$dbObject = new Database();
		$dbConnection = $dbObject->getDatabaseConnection();
        //sql query
        if($byName)
        {
            $sql="SELECT * FROM Item WHERE Iname= ?";

        }
        else
        {
            $sql="SELECT *FROM Item WHERE iId= ?";

        }
        //prep and execute statement 
		$stmt = $dbConnection->prepare($sql);
		$stmt->execute([$identifier]);
        //FETCH RESULTS
		$results=$stmt->fetchAll(PDO::FETCH_ASSOC);

        return $results;
	}

    function addItem() {

        $iId=$_POST['iId'];
        $Iname =$_POST['Iname'];
        $Sprice =$_POST['Sprice'];

        $dbObject = new Database();
		$dbConnection = $dbObject->getDatabaseConnection();

        $sql = "INSERT INTO ITEM (iId,Iname,Sprice) VALUES(?,?,?)";

		$stmt = $dbConnection->prepare($sql);
        //var_dump($stmt);
        if ($stmt->execute([$iId,$Iname, $Sprice])) {
            // The primary key value will be auto-incremented by the database
        } else {
            return 'Failed';  
        }
    }

    function deleteItem() {
       if (isset($_POST['exit'])) {
            header( "Location: http://localhost/php_Item_demo/menu.php"); }
        //$iId = $_POST['iId'];
        $Iname=$_POST['Iname'];
        //$Sprice=$_POST['Sprice'];



        $dbObject = new Database();
		$dbConnection = $dbObject->getDatabaseConnection();

        //$sql = "DELETE FROM Item WHERE iId=" .$iId;
        $sql="DELETE FROM Item WHERE Iname= ?"  ;
        //$sql="DELETE FROM Item WHERE Sprice="  .$Sprice;

        $stmt = $dbConnection->prepare($sql);
        //var_dump($stmt);
        if ($stmt->execute([$Iname])) {
            // The primary key value will be auto-incremented by the database
        } else {
            return 'Failed';  
        }

        echo 'deleted item!!';
    }

    function updateItem() {
        $NewName = $_POST['NewName'];
        $Iname = $_POST['Iname'];
       

        $dbObject = new Database();
		$dbConnection = $dbObject->getDatabaseConnection();
        $sql = "UPDATE ITEM SET Iname = ? WHERE Iname = ?";

    
        $stmt = $dbConnection->prepare($sql);
        //var_dump($stmt);
        if ($stmt->execute([$NewName, $Iname])) {
            // The primary key value will be auto-incremented by the database
        } else {
            return 'Failed';  
        }
    }
}

