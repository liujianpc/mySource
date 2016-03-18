    <?php
       // header('Content-type:text/html;charset=utf-8');
        $path = './';//设置当前脚本所在的文件目录
        $url = $_SERVER['REQUEST_URI']; //url是请求访问的页面，说白了就是根目录后的路径
        if(isset($_GET['d'])){          //确定访问页面是否有传递的参数d，d是用来指定下一个跳转的目录名
    $path = $_GET['d']; //如果有，则进行遍历的目录 = 当前脚本所在目录加上要跳转的目录名
            echo $path,'<br />';
        }else {
            $url = $url.'?d=.';         //如果没有，则要进行遍历的目录 = 当前脚本所在的目录
        }

        if(is_dir($path)){              //判断给定的目录是否合法
            $fh = scandir($path);       //列出指定路径中所有文件和目录
            //print_r($fh);
        }else {
            echo $path,' 不是合法目录';
        }
    ?>
    <html>
    <head>
    </head>
    <body>
    <table border = "1px">
        <tr>
            <td>序号</td>
            <td>文件名</td>
            <td>操作</td>
        </tr>
        <?php
            foreach($fh as $k=>$v){
                echo '<tr>';
                    echo '<td>',$k,'</td>';
                    echo '<td>',$v,'</td>';
                    if(is_dir($path.'/'.$v)){
                        echo '<td><a href="',$url.'/'.$v,'">浏览目录</a></td>';
                    }else {
                        echo '<td><a href="',$path.'/'.$v,'">查看文件</a></td>';
                    }

                echo '</tr>';
            }
        ?>
    </table>
    </body>
    </html>