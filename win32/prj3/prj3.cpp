// prj3.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	// TODO: Place code here.
	int ret = MessageBox(NULL,TEXT("���Ǻ�����"),TEXT("Question"),MB_YESNO|MB_ICONQUESTION);
	if(IDYES==ret)
	{
		int ret2 = MessageBox(NULL,TEXT("һ���Ͳ����Ǹ����ˣ�"),TEXT("Action"),MB_OK|MB_ICONEXCLAMATION);
		if(IDOK==ret2)
		{
			MessageBox(NULL,TEXT("��ʼ��ʽ��C�̣��Ǻ�"),TEXT("Action"),MB_ICONEXCLAMATION);
		}
	}

	else	
	{
		int ret3 = MessageBox(NULL,TEXT("���԰����Ϊ���ˣ�"),TEXT("Action"),MB_RETRYCANCEL|MB_ICONQUESTION);
		if(IDRETRY==ret3)
		{
			MessageBox(NULL,TEXT("����ʧ�ܣ�"),TEXT("Action"),MB_OK|MB_ICONWARNING);
		}
	}

	return 0;
}



