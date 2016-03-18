<?php
	$count = $_GET['tid'];
	$i = 1;
	$fl = fopen("msg.txt","r");
	while($str = fgetcsv($fl))
	{
		if($i == $count)
		{
			echo '<h1>',$str[0],'</h1>';
			echo '<p>',$str[1],'</p>';
			echo '<p>',$str[2],'</p>';
			echo '<p>',$str[3],'</p>';
			echo '<p>',$str[4],'</p>';
			echo '<p>',$str[5],'</p>';
			echo '<p>',$str[6],'</p>';
		}
		$i = $i + 1;
	}
	fclose($fl);
?>