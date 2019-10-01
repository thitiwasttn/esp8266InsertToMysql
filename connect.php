<?php

class Database
{
    function getConn()
    {
        $server = "103.13.31.12";
        $username = "thitiwas";
        $password = "dewsfmsx123";
        $database = "iot";
        $mysqli = new mysqli($server, $username, $password, $database);
        return $mysqli;
    }
}

?>
