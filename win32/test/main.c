#include <windows.h>

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	/* TODO: Place code here.*/
 	int ans=MessageBox(NULL,TEXT("你是否满了十八岁！"),TEXT("质问"),MB_YESNOCANCEL | MB_ICONQUESTION);
	 if(ans==IDYES){
 		MessageBox(NULL,TEXT("你可以看A片了！"),TEXT("回答"),MB_OK);
 	} 
 	else {
	 	MessageBox(NULL,TEXT("未成年人年不准看A片"),TEXT("回答"),MB_OK | MB_ICONINFORMATION);
	 }
 	

	return 0;
}
