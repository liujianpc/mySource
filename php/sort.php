<?php

	$i = 1;
	$fl = fopen("msg.txt","r");
	while ( $content = fgetcsv($fl) )
	{
		echo '<li><a href = "readmsg.php?tid=',$i,'">',$content[0],'</a></li>';
		$i = $i + 1;
	}
?>