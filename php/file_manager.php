<?php
	$path_dir ='./';//设定当前路径
	$url =$_SERVER['REQUEST_URI'];//获取当前url
	//$path_dir = $path_dir.$_GET['dir'];
	if(isset($_GET['dir']))//判断是否是有dir项
	{
		$path_dir = $path_dir.'/'.$_GET['dir'];//如果有dir项，则说明是目录跳转，需要改变目录，进行目录（路径）的拼接
	}
	else
	{
		$url = $url.'?dir=.';//如果没有dir项，则设为当前目录，兼容第一目录跳转
	}
	
	//$path_dir = isset($_GET('dir')) ? "./".$path_dir : './';
	$path = opendir($path_dir);//打开目录
	
	if($path == false)
	{
		echo '打开出错';
		exit;
	}
	$list  = array();//初始化一个空数组
	while($item = readdir($path))
	{
		//此处也可以用scandir($path)代替
		$list[] = $item;//目录中的内容置于空数组中
	}
	//print_r($list);//打印出来，有两个隐藏文件.和..
	closedir($path);//关闭目录
	
	
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
	"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">

<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="zh-CN">
	<head>
		<title>Untitled Page</title>
		<meta http-equiv="Content-type" content="text/html"; charset="UTF-8" />
		<meta name="description" content="everedit" />
		<style type="text/css" media="screen" id="test">
			td{border: 2px solid red;}
		</style>
		
	</head>
	<body>
		<h1>文件管理系统</h1>
		<table>
		
			
			<tr>
				<td>序号</td>
				<td>文件名</td>
				<td>操作</td>
			</tr>
			<?php
				foreach( $list as $k => $v )
				{
			?>
			<tr>
				<td><?php
					echo $k;
				?>
				</td>
				<td><?php
					echo $v;
				?>
				</td>
				<td><?php
					if ( is_dir($path_dir.'/'.$v) )//重要，需要加入($path_dir.'/'，否则不支持第三层文件夹的正确访问(显示的是查看，而不是浏览)
					{
						//echo '<a href="http://localhost/myphp/file_manager.php?dir=',$v,'">浏览</a>';//代表电脑上的路径
						echo '<a href="',$url.'/'.$v,'">浏览</a>';//代表apache服务器上的路径,带了php文件的链接地址是需要调用php的，而为带php的路径是文件路径//浏览文件夹的超级链接，形式为php?dir=./xx/xx/xx/xx/xx这种形式后面的$v是一个目录，整个访问目录需要拼接
					}
					else
					{
						//echo '<a href="http://localhost/myphp/file_manager.php?dir=',$_GET['dir'],$v,'">查看</a>';
						echo '<a href="',$path_dir.'/',$v,'">查看</a>';
						# code...查看文件路径。。。。非url超级链接。注意路径的拼接
					}
					

				
				?>
				</td>
				<?php
				}
				?>
				
			</tr>
		</table>
	</body>
</html>