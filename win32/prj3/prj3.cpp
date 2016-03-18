// prj3.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	// TODO: Place code here.
	int ret = MessageBox(NULL,TEXT("你是好人吗？"),TEXT("Question"),MB_YESNO|MB_ICONQUESTION);
	if(IDYES==ret)
	{
		int ret2 = MessageBox(NULL,TEXT("一看就不像是个好人！"),TEXT("Action"),MB_OK|MB_ICONEXCLAMATION);
		if(IDOK==ret2)
		{
			MessageBox(NULL,TEXT("开始格式化C盘！呵呵"),TEXT("Action"),MB_ICONEXCLAMATION);
		}
	}

	else	
	{
		int ret3 = MessageBox(NULL,TEXT("尝试把你变为好人？"),TEXT("Action"),MB_RETRYCANCEL|MB_ICONQUESTION);
		if(IDRETRY==ret3)
		{
			MessageBox(NULL,TEXT("尝试失败！"),TEXT("Action"),MB_OK|MB_ICONWARNING);
		}
	}

	return 0;
}



