<?php

$dbhost = 'localhost:3306';
$dbuser = 'root';
$dbpass = 'amsdemo@123';
$dbname = 'data_analysis';
$conn = mysqli_connect($dbhost, $dbuser, $dbpass);
if(! $conn )
{
	die('Could not connect: ' . mysqli_error());
}
$sql = 'SELECT time,ph,turb FROM ph_turb';
mysqli_select_db($conn,$dbname);
$retval = mysqli_query( $conn,$sql);
if(!$retval )
{
	die('Could not get data: ' . mysqli_error());
}
while($row = mysqli_fetch_array($retval, MYSQLI_ASSOC))
{
	$row_arr[]=$row;
echo "timestamp :{$row['time']}  <br> ".
         "ph : {$row['ph']} <br> ".
         "turbidity : {$row['turb']} <br> ".
         "--------------------------------<br>";
}
echo "Fetched data successfully\n";
$jsondata = json_encode($row_arr);
echo $jsondata;
mysqli_close($conn);
?>

//</body>
//</html>

