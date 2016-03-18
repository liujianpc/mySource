<?php
//时间戳和时间函数操作模块
	$t = time();
	echo $t;
	echo '<br />';
	echo date("Y-m-d h:i:s");
	echo "<br />";
	echo date("Y-m-d 星期N H:i:s",$t);
	echo "<br />";
	echo date("Y-m-d N H:i:s",0);
	echo "<br />";
	echo gmdate("Y-m-d N H:i:s",$t);echo "<br />";
	echo date("Y-m-d 星期N H:i:s",$t),'<br />';
	echo gmdate('Y-m-d 周N H:i:s',mktime(00,12,30,5,28,2015)),'<br />';
	echo date("Y-m-d 周N H:i:s",time()-24*3600),'<br />';
	echo date('Y - m -d 周 N H:i:s',strtotime('now -1 day'));

	//变量的引用
	echo '<br />';
	$var1 = 1;
	$var2 = &$var1;
	echo $var1,$var2;
	//逗号和点号的区别，作用效果一致，但过程不一样，逗号更高效
	echo "hello","liujian";//不运算，直接输出
	echo "hello"."liujian";//先运算链接两个字符串，再输出

	//
	echo '<br />';
	$str1 = "hello";
	$str2 = 'hello';
	echo $str1,$str2,'<br />';
	
	//heredoc
	
	$str3 = <<<EOF
		hello world
		bbc  liujian
					fuck you;
EOF;
//结束符必须顶格开始写。否则错误

	echo $str3;

	$v=2;
$a= <<<INTR
"abc"$v
"123"
INTR;
echo $a;


//heredoc
$name = '浅水游';
print <<<EOT

<html> 
<head> 
<meta http-equiv="Content-Type" content="text/html; charset=gb2312" /> 
<title>Untitled Document</title> 
</head> 
<body> 
<!--12321--> 
Hello,$name! 
</body> 
</html>

EOT;

//nowdoc,php5.3以下的版本不能支持nowdoc

$str2= <<<now
hello
hhh
kkkkkkk
now;
echo $str2.'<br />';

//函数的引用
function &test(){ 
    static $b=0;//申明一个静态变量 
    $b=$b+1; 
    echo $b; 
    return $b;
}
$a=test();//这条语句会输出　$b的值　为１ 
$a=5; $a=test();//这条语句会输出　$b的值　为2
$a=&test();//这条语句会输出　$b的值　为3 
$a=5; $a=test();//这条语句会输出　$b的值　为6
//字符串的引用和字符串函数函数
echo '<br />';
$str_1 = "hello,中国";
$len = strlen($str_1);
echo $len,'<br />';
$str_2 = '中国';
echo strlen($str_2),'<br />';
echo mb_strlen($str_2,'utf-8'),'<br />';
$STR_3 = 'ABCDEF';
echo strpos($STR_3,'E'),'<br />';
$str_4 = ' i fuck you';
echo str_replace('fuck','love',$str_4),'<br />';
echo str_repeat('head',4),'<br />';
$str_5 = 'hello,python,tech';
$arr = explode(',',$str_5);
print_r($arr);
echo '<br />';
echo implode('_',$arr),'<br />';

//数组
$arr = array(1,2,3);
print_r($arr);
echo '<br />';
$arr_1 = array('name'=>'liujian','age'=>'20','job'=>'student');
print_r($arr_1);
//数组的遍历
echo '<br />';
//同时打印键值对
foreach($arr_1 as $key=>$value)
{
	echo $key,'=>',$value,'<br />';
}

//只打印值
foreach($arr_1 as $value)
{
	echo $value,'<br />';
}
//
$arr_2 = array(1,2,3,4,5);
foreach($arr_2 as $value)
{
	echo $value*2,'<br />';
}

foreach($arr_2 as $value)
{
	echo $value,'<br />';
}			
foreach($arr as $value)
{
	echo $value,'<br />';
}
echo current($arr),'<br />';
echo next($arr),'<br />'; 
	//sphpinfo();
	
//数组函数
echo count($arr),'<br />';
echo count($arr_2),'<br />';
//array_key_exists()
if(array_key_exists("age",$arr_1))
{
	echo $arr_1["age"],'<br />';
}
// isset() (遇到NULL值返回false)
if(isset($arr_1['name']))
	echo $arr_1['name'],'<br />';
	
	//重点:1、数组的函数。2、字符串的函数
	

//生小羊问题.初始时，有1岁的一只羊，羊在2岁和4岁时生一小羊，5岁时死亡，问20年后一共有多少只羊
$yang = array(1,0,0,0,0);
for($i = 0;$i < 20;$i++){
	$temp = $yang[1] + $yang[3]; //第二年和第四年生出的小羊，
	array_unshift($yang,$temp);//年龄为一岁，所以压到数组的头部
	array_pop($yang);//将年纪超过5岁的羊杀死
}
echo array_sum($yang),'<br />';
print_r($yang);
echo '<br />';

//猴子围圈报数选大王问题
$hou = array(1=>1,2=>2);
print_r($hou);
echo '<br />';
$hou1 = array(1=>1,100=>100);
print_r($hou1);
echo "<br />";
echo count($hou1),'<br />';

//
set_time_limit(0);//将时间限制为0s
function monkey($m, $n) {  
    //把猴子装进数组里  
    for($i = 0; $i < $m; $i++) {  
       $monkey_array[$i] = $i + 1;  
   }  //给全部猴子编号
   		$key = 1;//数数标签
    while(count($monkey_array)>1) //当猴子数目多余1则，继续循环
    { 
    	
        foreach($monkey_array as $value) //遍历猴子数组
        {  
            if ($key % $n == 0) 
            {  
                unset($monkey_array[$key - 1]); //删除数数为m的猴子
            }
           else 
           {  
               array_push($monkey_array, $monkey_array[$key - 1]);  //将数数不为5的猴子压到数组末尾（因为是围圈报数）
               unset($monkey_array[$key - 1]);  //并将该猴子在原有位置删除
      		}
      		$key += 1;//指向下一个数组元素
       }  
   }  
   
   return $monkey_array;  
}  

echo '<br />';
print_r(monkey(88,3));
/*$arry_test  = array( 1,2,3,4,5,6 );
foreach( $arry_test as $key => $value )
{
	echo $key,'-->',$arry_test[$key],'<br />';
}
unset($arry_test[3]);//该段代码，检验了，删除数组中的某个元素，数组中其他元素的键值不会改变
array_push($arry_test,8);
foreach( $arry_test as $key => $value )
{
	echo $key,'-->',$arry_test[$key],'<br />';
}*/


?>
