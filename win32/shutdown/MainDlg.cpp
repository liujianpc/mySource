#include "stdafx.h"
#include <windows.h>
#include <windowsx.h>
#include "resource.h"
#include "MainDlg.h"
#include "stdlib.h"
#include "stdio.h"
#include "time.h"
#include "string.h"
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

BOOL Main_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam)
{
    return TRUE;
}

void Main_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{
    switch(id)
    {
        case IDC_OK:
		
				TCHAR strHOUR[20];
				TCHAR strMINUTES[20];
				TCHAR cmd[80] = "shutdown -s -t ";

				GetDlgItemText(hwnd,IDC_HOUR,strHOUR,sizeof(strHOUR));
				GetDlgItemText(hwnd,IDC_MINUTES,strMINUTES,sizeof(strMINUTES));

				int h = atoi(strHOUR);
				int m = atoi(strMINUTES);

				time_t nowTime;
				struct tm *timeinfo;
				time(&nowTime);
				timeinfo = localtime(&nowTime);

				int now_H = timeinfo->tm_hour;
				int now_M = timeinfo->tm_min;
				int now_S = timeinfo->tm_sec;

				if (now_H <= h)
				{
					int sec = (h - now_H)*3600 + (m - now_M) * 60;
					TCHAR str1[20];
					itoa(sec,str1,10);
					system(strcat(cmd,str1));

				}

				else
				{
					int sec = (24 + h - now_H)*3600 + (m - now_M) * 60 - now_S;
					TCHAR str1[20];
					itoa(sec,str1,10);
					system(strcat(cmd,str1));

				}
				TCHAR str2[50]="将在";
				TCHAR str3[5];
				itoa(h,str3,10);
				TCHAR str4[]=":";
				TCHAR str5[5];
				itoa(m,str5,10);
				TCHAR str6[]="关机！";
				strcat(str2,str3);
				strcat(str2,str4);
				strcat(str2,str5);
				strcat(str2,str6);
				MessageBox(hwnd,str2,TEXT("关机提示"),MB_OK);
				
				
			break;

	
    }
}

void Main_OnClose(HWND hwnd)
{
    EndDialog(hwnd, 0);
}