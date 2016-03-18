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

void CALLBACK proc(HWND hwnd,UINT message,UINT iTimerID,DWORD dwTime)
{
	SYSTEMTIME stime;
	GetLocalTime(&stime);
	TCHAR date[256] = {0};
	TCHAR ti[256] = {0};
	TCHAR week[256] = {0};
	wsprintf(date,"%i/%i/%i",stime.wYear,stime.wMonth,stime.wDay);
	wsprintf(ti,"%i:%i:%i",stime.wHour,stime.wMinute,stime.wSecond);
	wsprintf(week,"%i",stime.wDayOfWeek);
	SetDlgItemText(hwnd,IDC_DATE,date);
	SetDlgItemText(hwnd,IDC_TIME,ti);
	SetDlgItemText(hwnd,IDC_WEEK,week);
}
BOOL Main_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam)
{
	SetTimer(hwnd,0,1000,proc);
    return TRUE;
}

void Main_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{
    switch(id)
    {
        case IDC_OK:
			//MessageBox(hwnd,TEXT("欢迎访问如鹏网 www.RuPeng.com 大学生计算机学习社区"),TEXT("问好"),MB_OK);
        break;
        default:
		break;
    }
}

void Main_OnClose(HWND hwnd)
{
    EndDialog(hwnd, 0);
}