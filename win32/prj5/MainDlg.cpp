#include "stdafx.h"
#include <stdlib.h>
#include <windows.h>
#include <windowsx.h>
#include "resource.h"
#include "MainDlg.h"
#include "stdio.h"


BOOL WINAPI Main_Proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)
    {
        HANDLE_MSG(hWnd, WM_INITDIALOG, Main_OnInitDialog);
        HANDLE_MSG(hWnd, WM_COMMAND, Main_OnCommand);
		HANDLE_MSG(hWnd,WM_CLOSE, Main_OnClose);
    }

    return FALSE;
}

BOOL Main_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam)
{
    return TRUE;
}

void Main_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{
    switch(id)
    {
        case IDC_OK:

			TCHAR str1[200];
			TCHAR str2[200];
			TCHAR str3[200];
			TCHAR str4[200]="incorrect input!";
			GetDlgItemText(hwnd,IDC_EDIT1,str1,sizeof(str1));
			GetDlgItemText(hwnd,IDC_EDIT2,str2,sizeof(str2));
			if(str1[0]>=58 || str1[0]<=47)
			{
				SetDlgItemText(hwnd,IDC_EDIT4,str4);
				MessageBox(hwnd,TEXT("ÊäÈë´íÎó£¡"),TEXT("reaction"),MB_OK|MB_ICONERROR);
				return;
			}
			else
			{
				double a = atof(str1);
				double b = atof(str2);
				double c = a+b;
				
				sprintf(str3,"%lf",c);
				SetDlgItemText(hwnd,IDC_EDIT3,str3);

			}
			
			
			//MessageBox(hwnd,TEXT(""),TEXT("ÎÊºÃ"),MB_OK);
        break;
        //default:
		break;
    }
}

void Main_OnClose(HWND hwnd)
{
    EndDialog(hwnd, 0);
}