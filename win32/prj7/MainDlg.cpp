#include "stdafx.h"
#include <windows.h>
#include <windowsx.h>
#include "resource.h"
#include "MainDlg.h"
#include "stdlib.h"
#include "stdio.h"
//#include "wchar.h"

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
	HWND hwndComboBox1 = GetDlgItem(hwnd,IDC_COMBO1);
	ComboBox_InsertString(hwndComboBox1,-1,TEXT("+"));
	ComboBox_InsertString(hwndComboBox1,-1,TEXT("-"));
	ComboBox_InsertString(hwndComboBox1,-1,TEXT("*"));
	ComboBox_InsertString(hwndComboBox1,-1,TEXT("/"));
    return TRUE;
}

void Main_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{
    switch(id)
    {
        case IDC_OK:
			
			{
				TCHAR str1[100]={0};
				TCHAR str2[100]={0};
				TCHAR str3[100]={0};
				GetDlgItemText(hwnd,IDC_EDIT1,str1,sizeof(str1));
				GetDlgItemText(hwnd,IDC_EDIT2,str2,sizeof(str2));
				double a=atof(str2);
				double b=atof(str1);
				double c = 0;

					
				HWND hwndComboBox1 = GetDlgItem(hwnd,IDC_COMBO1);
				int cursel = ComboBox_GetCurSel(hwndComboBox1);//获取所选的项ID

				switch(cursel)
				{
				case 0:
					c = a+b;
					sprintf(str3,"%lf",c);
					SetDlgItemText(hwnd,IDC_EDIT3,str3);
					break;

                case 1:
					c = a-b;
					sprintf(str3,"%lf",c);
					SetDlgItemText(hwnd,IDC_EDIT3,str3);
					break;

				case 2:
					c = a*b;
					sprintf(str3,"%lf",c);
					SetDlgItemText(hwnd,IDC_EDIT3,str3);
					break;

				case 3:
					c = a/b;
					sprintf(str3,"%lf",c);
					SetDlgItemText(hwnd,IDC_EDIT3,str3);
				default:
					break;
				}
				//ComboBox_DeleteString(hwndComboBox1,2);//删除项
				//ComboBox_SetCurSel(hwndComboBox1,3);//自动设定某项
				
				/*TCHAR str[100]={0};//获取所选项的值
				ComboBox_GetLBText(hwndComboBox1,1,str);
				MessageBox(hwnd,str,TEXT("反馈！"),MB_OK);

					*/
				/*if (0==cursel)
				{
					MessageBox(hwnd,TEXT("减法运算"),TEXT("问好"),MB_OK);

				}*/

			
				
			}
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