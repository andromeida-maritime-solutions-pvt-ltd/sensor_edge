<?php
//print "<h2>PHP is Fun!</h2>";
//print "Hello world!<br>";
//print "I'm about to learn PHP!";
$dbhost = 'localhost:3306';
$dbuser = 'root';
$dbpass = 'DEV2522dev2522';
$dbname = 'akki';
$conn = mysqli_connect($dbhost, $dbuser, $dbpass);

if(! $conn )
{
	die('Could not connect: ' . mysqli_error());
}
//$sql = 'SELECT sl,value,time FROM devesh';
mysqli_select_db($conn,$dbname);
$retval = mysqli_query( $conn,"SELECT timestamp,ph,temp,hard FROM sensordata");

if(!$retval )
{
	die('Could not get data: ' . mysqli_error());
}

while($row = mysqli_fetch_array($retval, MYSQLI_ASSOC))
{
	$row_arr[]=$row;
echo "timestamp :{$row['timestamp']}  <br> ".
         "ph : {$row['ph']} <br> ".
         "temp : {$row['temp']} <br> ".
	"hardness : {$row['hard']} <br>".
         "--------------------------------<br>";
}

echo "Fetched data successfully\n";

$jsondata = json_encode($row_arr);
echo $jsondata;

mysqli_close($conn);

?>

//</body>
//</html>
