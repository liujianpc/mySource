#include "stdafx.h"
#include <windows.h>
#include <windowsx.h>
#include "resource.h"
#include "MainDlg.h"

/*
Template designed by RuPeng.com. Please visit http://www.rupeng.com for more information
如鹏网（http://www.rupeng.com）大学生计算机学习社区，提供大量免费视频学习教程，提供个性化一对一学习指导
*/
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
 void CALLBACK timeProc(HWND hwnd,UINT message,UINT iTimerID,DWORD dwTime)
 {
	SYSTEMTIME stLocal;
	GetLocalTime(&stLocal);
	TCHAR strTime[256] = {0};
	wsprintf(strTime,"%i年-%i月%i日 %i:%i:%i",stLocal.wYear,stLocal.wMonth,stLocal.wDay,stLocal.wHour,
		stLocal.wMinute,stLocal.wSecond);
	SetDlgItemText(hwnd,IDC_EDITTIME,strTime);
 }
BOOL Main_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam)
{
	SetTimer(hwnd,0,1000,timeProc);
    return TRUE;
}

void Main_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{
    switch(id)
    {
        case IDC_OK:
			MessageBox(hwnd,TEXT("欢迎访问如鹏网 www.RuPeng.com 大学生计算机学习社区"),TEXT("问好"),MB_OK);
        break;
        default:
		break;
    }
}

void Main_OnClose(HWND hwnd)
{
    EndDialog(hwnd, 0);
}