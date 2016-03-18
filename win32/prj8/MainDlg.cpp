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
	HWND Combo = GetDlgItem(hwnd,IDC_COMBO1);
	ComboBox_InsertString(Combo,-1,TEXT("��һ"));
	ComboBox_InsertString(Combo,-1,TEXT("����"));
	ComboBox_InsertString(Combo,-1,TEXT("����"));
	ComboBox_InsertString(Combo,-1,TEXT("����"));
	ComboBox_InsertString(Combo,-1,TEXT("����"));
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
		     // MessageBox(hwnd,s,TEXT("�ܹ�"),MB_OK);
				TCHAR str1[100] = {0};
				
				GetDlgItemText(hwnd,IDC_EDIT1,str1,sizeof(str1));
				
				ComboBox_InsertString(Combo,-1,str1);
				SetDlgItemText(hwnd,IDC_EDIT1,TEXT(""));

				
			}
			//MessageBox(hwnd,TEXT("��ӭ���������� www.RuPeng.com ��ѧ�������ѧϰ����"),TEXT("�ʺ�"),MB_OK);
        break;


		case IDC_DEL:
			{
				HWND Combo = GetDlgItem(hwnd,IDC_COMBO1);
				int sel = ComboBox_GetCurSel(Combo);
				ComboBox_DeleteString(Combo,sel);
				if (CB_ERR == sel)
				{
					MessageBox(hwnd,TEXT("û��ѡ�����ݣ�"),TEXT("������"),MB_OK | MB_ICONEXCLAMATION);
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
				while (ComboBox_GetCount(Combo))//��forѭ����bug������֪��ô��
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
						MessageBox(hwnd,str2,TEXT("�Ѳ��ҵ�"),MB_OK|MB_ICONEXCLAMATION);
						break;
					}
				
					
					
				}

				if (flag == 0)
				{
					MessageBox(hwnd,TEXT("û�ҵ�"),TEXT("����"),MB_OK | MB_ICONERROR);
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