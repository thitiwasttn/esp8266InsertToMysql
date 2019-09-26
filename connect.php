<?php

class Database
{
    function getConn()
    {
        $server = "localhost";
        $username = "root";
        $password = "";
        $database = "iot";
        $mysqli = new mysqli($server, $username, $password, $database);
        return $mysqli;
    }
}

?>
