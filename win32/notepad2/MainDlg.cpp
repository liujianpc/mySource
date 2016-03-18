#include "stdafx.h"
#include <windows.h>
#include <windowsx.h>
#include "resource.h"
#include "MainDlg.h"
#include "stdio.h"
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
    return TRUE;
}
		
void Main_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{
    switch(id)
    {
        case ID_OPEN:
			{
				FILE *fp = fopen("C:/1.txt","r");
				char line[256]={0};
				fgets(line,sizeof(line),fp);
				fclose(fp);
				SetDlgItemText(hwnd,IDC_EDIT1,line);
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