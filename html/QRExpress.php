<?php
	include 'phpqrcode.php';    
$value = 'http://www.cnblogs.com/txw1958/'; //二维码内容   
$errorCorrectionLevel = 'L';//容错级别   
$matrixPointSize = 6;//生成图片大小   
//生成二维码图片   
QRcode::png($value, 'qrcode.png', $errorCorrectionLevel, $matrixPointSize, 2);   

echo '<img src="helloweixin.png">';
?>