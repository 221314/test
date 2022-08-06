<?php
#include 'config.php'

$host = "localhost";
$user = "root";
$psaaword = "root1234";
$dbname = "iot";

$con = mysqli_connect($host,$user,$password,$dbname);

if(!$con)
  die ("connetion failed : ", mysqli_connect_error());
