<?php
whlie($row = mysql_fetch_array($res_sel))
{
  echo $row['date']," | type : ";
  echo $row['type']," | value : ";
  echo $row['val'],"<br>";
} ?>
