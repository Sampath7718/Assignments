<?php #process form

if ( isset($_POST['Phone']) ) 
{
    #get all of the info that was posted and echo it
        $phone = $_POST['Phone'];
        $outputLine = "Your order is: \n" .
                                "Phone: $phone \n ";
        echo nl2br($outputLine);

} else {
	echo 'INVALID';
}
?>
