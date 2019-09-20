<?php

class Database
{
    function getConn()
    {
        $server = "localhost";
        $username = "root";
        $password = "";
        $database = "IOT";
        $mysqli = new mysqli($server, $username, $password, $database);
        return $mysqli;
    }
}

?>