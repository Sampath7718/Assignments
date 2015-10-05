<?php
$woeid = $_GET['woeid'];
$weatherURL="http://weather.yahooapis.com/forecastrss?w=", $woeid;
header("Content-type: text/xml");
header("Content-length: " . strlen(file_get_contents($weatherURL)));
header("Cache-Control: no-cache");
readfile($WeatherURL);
?>
