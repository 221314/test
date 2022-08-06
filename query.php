<?php
include 'config.php';

//date now
$pdate = date('Y-m-d H:i:s');
//data(sensor)
$ptype = $_POST['label'];
$pval = $_POST['val];

//cam_data
$plabel = $_POST['label'];
$pper = $_POST['per'];
$pacc = $_POST['acc'];

if($con){
  //query
  $query = "INSERT INTO data VALUES ('$pdate','$ptype',$pval);";
  $com_query = "INSERT INTO cam_data VALUES ('$pdate','$plabel',$pper,$acc);";
  $del_quert = "DELETE FROM cam_data WHERE date <DATE_ADD(now(), INTERVAL -1 hour);";
  
  $result = mysqli_query($con, $query);
  $cam_result = mysqli_query($con, $cam_query);
  $del_result = mysqli_query($con, $del_query);
  
  //select
  $select = "SELECT * FROM data;";
  $res_sel = mysqli_query($con, $select);
  
  $cam_select = "SELECT * FROM cam_data;";
  $cam_sel = mysqli_query($con, $cam_select);
}
else
  die("query failed : ", mysqli_connect_error());
mysqli_close($con);
