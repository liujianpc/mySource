jQuery("a.sk-button").trigger(“click”);
setTimeout(autoclick, 1);
setInterval() 
$(document).ready(function(){
		autoclick();
	$("#bt").click(function(){
		$(".aa").slideToggle("slow");						
	})
	function autoclick(){
		$("#bt").trigger("click"); 
		$autoFun = setTimeout( autoclick, 1 ); 
	}
 })


$(“#bt”).trigger(“click”);    //让系统自动执行单击事件
setTimeout(autoclick, 1000);      //设置1秒后执行autoclick函数;
setInterval()                     //每隔指定的时间执行 一个表达式或者是函数

自动动画实例:

$(document).ready(function(){
		autoclick();
	$("#bt").click(function(){
		$(".aa").slideToggle("slow");						
	})
	function autoclick(){
		$("#bt").trigger("click");  //让系统自动执行单击事件
		$autoFun = setTimeout( autoclick, 1000 ); //设置3秒钟之后再次执行函数
	}
 })
