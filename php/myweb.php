<?php
	echo '<!DOCTYPE html>
<html lang="zh-cn">
<head>
<meta charset="utf-8">
<title></title>
</head>
<body>
	<form action="http://www.baidu.com" method="post">
	<p>帐号：<input type="text" name = "usrname"></p>
	<p>密码：<input type="PASSWORD" name="PASSWORD">
	</p>
	<p>性别：男<input type="radio" name="sex" value="男" checked="checked">
	女<input type="radio" name="sex" value="女">
	</p>
	<p>爱好：足球<input type="CHECKBOX" name="hobby" value="足球" checked="checked">
	篮球<input type="CHECKBOX" name="hobby" value="篮球">
	台球<input type="CHECKBOX" name="hobby" value="台球">
	</p>
	<p>
		学历：<select name="edu">
			<option value="大学" selected="selected">大学</option>
			<option value="中学">中学</option>
			<option value="小学">小学</option>
		</select>
	</p>
	<p>自我介绍:<br/><textarea name="intro" id="" cols="30" rows="10">请输入自我介绍</textarea></p>
	<p>上传头像:<input type="file" name="pic" /></p>
	<p>隐藏:你看不见<input type="hidden" name="IP" value="192.168.1.1"/></p>
	<p><input type="submit" value="提交" /></p>
	</form>
</body>
</html>

'
?>
