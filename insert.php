<?php
session_start();
require_once("connect.php");
$db = new Database();
$con = $db->getConn();
    if(isset($_GET['value']))
    {
        $sql = "INSERT INTO data SET value = '" . $_GET['value'] . "'";
        $query = mysqli_query($con, $sql) or die('query insert : ' . mysqli_error($con));
        $result = ($query) ? "Success" : "Error";
//        echo "<h1>Add Value : " . $_GET['value'] . "   " . $result . "</h1>";
    }elseif (!isset($_GET['value']))
    {
//        echo "<h1>No input</h1>";
    }

?>
