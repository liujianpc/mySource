#include "stdafx.h"
#include <windows.h>
#include <windowsx.h>
#include "resource.h"
#include "MainDlg.h"
#include "stdio.h"
#include "stdlib.h"
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
	HWND Combo = GetDlgItem(hwnd,IDC_COMBO1);
	ComboBox_InsertString(Combo,-1,TEXT("李一"));
	ComboBox_InsertString(Combo,-1,TEXT("王二"));
	ComboBox_InsertString(Combo,-1,TEXT("张三"));
	ComboBox_InsertString(Combo,-1,TEXT("刘四"));
	ComboBox_InsertString(Combo,-1,TEXT("陈五"));
    return TRUE;
}

void Main_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{
    switch(id)
    {
        case IDC_ADD:
			{
				HWND Combo = GetDlgItem(hwnd,IDC_COMBO1);
			//	int n = ComboBox_GetCount(Combo);
			//	TCHAR s[100] = {0};
			//	wsprintf(s,"%i",n);
		     // MessageBox(hwnd,s,TEXT("总共"),MB_OK);
				TCHAR str1[100] = {0};
				
				GetDlgItemText(hwnd,IDC_EDIT1,str1,sizeof(str1));
				
				ComboBox_InsertString(Combo,-1,str1);
				SetDlgItemText(hwnd,IDC_EDIT1,TEXT(""));

				
			}
			//MessageBox(hwnd,TEXT("欢迎访问如鹏网 www.RuPeng.com 大学生计算机学习社区"),TEXT("问好"),MB_OK);
        break;


		case IDC_DEL:
			{
				HWND Combo = GetDlgItem(hwnd,IDC_COMBO1);
				int sel = ComboBox_GetCurSel(Combo);
				ComboBox_DeleteString(Combo,sel);
				if (CB_ERR == sel)
				{
					MessageBox(hwnd,TEXT("没有选择内容！"),TEXT("反馈！"),MB_OK | MB_ICONEXCLAMATION);
				}
				
			
			}
			break;

		case IDC_CLE:
			{
				HWND Combo = GetDlgItem(hwnd,IDC_COMBO1);
				int i = 0;
			/*int n = ComboBox_GetCount(Combo);
				for (i=0;i<n;i++)
				{
					ComboBox_DeleteString(Combo,i);

				}*/
				while (ComboBox_GetCount(Combo))//用for循环有bug啊，不知怎么地
				{
					ComboBox_DeleteString(Combo,0);
				}
			
			}
			break;
			

		case IDC_FIND:
			{

				TCHAR str3[100] = {0};
				int i=0;
				TCHAR str2[100] = {0};
				HWND Combo = GetDlgItem(hwnd,IDC_COMBO1);
				GetDlgItemText(hwnd,IDC_EDIT2,str2,sizeof(str2));
				int n = ComboBox_GetCount(Combo);
				int flag = 0;
				for (i=0;i<n;i++)
				{
					ComboBox_GetLBText(Combo,i,str3);
					if (strcmp(str2,str3)==0)
					{
						flag = 1;
						ComboBox_SetCurSel(Combo,i);
						MessageBox(hwnd,str2,TEXT("已查找到"),MB_OK|MB_ICONEXCLAMATION);
						break;
					}
				
					
					
				}

				if (flag == 0)
				{
					MessageBox(hwnd,TEXT("没找到"),TEXT("反馈"),MB_OK | MB_ICONERROR);
				}

			}
			break;

        default:
		break;
    }
}

void Main_OnClose(HWND hwnd)
{
    EndDialog(hwnd, 0);
}