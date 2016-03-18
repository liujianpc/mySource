<?php
	//print_r($_POST);
	//echo $_GET['tid'];
	/*echo '<li>','<h1>',$_POST['usrname'],'</h1>',
		'</li>','<blockquote>',
		'<h3>',$_POST['sex'],'</h3>',
		'<h3>',$_POST['hobby'],'</h3>',
		'<h3>',$_POST['edu'],'</h3>',
		'<h3>',$_POST['intro'],'</h3>',
		'<h3>',$_POST['IP'],'</h3>',
		'</blockquote>';*/
	$str = $_POST['usrname'].",".$_POST['sex'].",".$_POST['hobby'].",".$_POST['edu'].",".$_POST['intro'].",".$_POST['IP']."\n";
	$file = fopen("msg.txt","a");
	fwrite($file,$str);
	fclose($file);	
	echo "×¢²áÍê³É£¡Ð»Ð»£¡";
?>