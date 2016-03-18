#include "stdafx.h"
#include <windows.h>
#include <windowsx.h>
#include "resource.h"
#include "MainDlg.h"

/*
Template designed by RuPeng.com. Please visit http://www.rupeng.com for more information
��������http://www.rupeng.com����ѧ�������ѧϰ�������ṩ���������Ƶѧϰ�̳̣��ṩ���Ի�һ��һѧϰָ��
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
			//MessageBox(hwnd,TEXT("��ӭ���������� www.RuPeng.com ��ѧ�������ѧϰ����"),TEXT("�ʺ�"),MB_OK);
        break;
        default:
		break;
    }
}

void Main_OnClose(HWND hwnd)
{
    EndDialog(hwnd, 0);
}