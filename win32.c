#include <windows.h>

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	/* TODO: Place code here.*/
 	int ans=MessageBox(NULL,TEXT("你是好人吗？"),TEXT("质问"),MB_YESNOCANCEL | MB_ICONQUESTION);
	 if(ans==IDYES){
 		int ans2=MessageBox(NULL,TEXT("我看你就不是一个好人！"),TEXT("回答"),MB_OK | MB_ICONINFORMATION);
		if(ans2==IDOK){
			MessageBox(NULL,TEXT("开始格式化C盘！"),TEXT("处理"),MB_OK);
		}
 	} 
 	else {
	 	MessageBox(NULL,TEXT("重试或取消变成一个好人！"),TEXT("选择"),MB_RETRYCANCEL | MB_ICONINFORMATION);
	 }
 	

	return 0;
}
