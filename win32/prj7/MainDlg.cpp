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
				int cursel = ComboBox_GetCurSel(hwndComboBox1);//��ȡ��ѡ����ID

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
				//ComboBox_DeleteString(hwndComboBox1,2);//ɾ����
				//ComboBox_SetCurSel(hwndComboBox1,3);//�Զ��趨ĳ��
				
				/*TCHAR str[100]={0};//��ȡ��ѡ���ֵ
				ComboBox_GetLBText(hwndComboBox1,1,str);
				MessageBox(hwnd,str,TEXT("������"),MB_OK);

					*/
				/*if (0==cursel)
				{
					MessageBox(hwnd,TEXT("��������"),TEXT("�ʺ�"),MB_OK);

				}*/

			
				
			}
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