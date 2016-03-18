##打印99乘法表
	<?php
    	for($i = 1;$i <= 9 ;$i++)
        {
        	for($j = 0;$j <= $i;$j++)
            {
            	echo $i,"*",$j,"=",$i*$j;
            }
            echo "\n";
        }
    >
    
---
    <?php
            /*for($i = 1;$i <= 9 ;$i++)
            {
                for($j = 1;$j <= $i;$j++)
                {
                    echo $j,"*",$i,"=",$i*$j,"&nbsp;";
                    //echo ;
                }
                echo "<br/>";
            }*/
            for($i = 0;$i < 20; $i++)
                for($j = 0;$j < 33;$j++)
                {
                    $k = 100 - $i -$j;
                    if($k % 3 == 0 &&  $i*5 + $j*3 + $k/3 == 100)
                    {
                        echo "公鸡:".$i."<br/>"."母鸡：".$j."<br/>"."小鸡:".$k."<br/>";//点号和逗号效果一样，但逗号更快，因为点号是运算符，所以先运算，再打印
                    }
                    //echo '------------------------<br/>';
                }
    
            echo "liujian","jjjjjj";
            echo "liujian"."jjjjjjj";
       ?>
