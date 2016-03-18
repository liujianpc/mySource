// prj2.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	// TODO: Place code here.
	int ret = MessageBox(NULL,TEXT("are you adult"),TEXT("greet!"),MB_YESNO|MB_ICONQUESTION);
	if(ret==IDYES){
			MessageBox(NULL,TEXT("you can scan the porn website!"),TEXT("action"),MB_OK);
	}

	else	MessageBox(NULL,TEXT("you can not get in,sorry!"),TEXT("action"),MB_OK);
	return 0;
}



