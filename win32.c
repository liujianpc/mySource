#include <windows.h>

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	/* TODO: Place code here.*/
 	int ans=MessageBox(NULL,TEXT("���Ǻ�����"),TEXT("����"),MB_YESNOCANCEL | MB_ICONQUESTION);
	 if(ans==IDYES){
 		int ans2=MessageBox(NULL,TEXT("�ҿ���Ͳ���һ�����ˣ�"),TEXT("�ش�"),MB_OK | MB_ICONINFORMATION);
		if(ans2==IDOK){
			MessageBox(NULL,TEXT("��ʼ��ʽ��C�̣�"),TEXT("����"),MB_OK);
		}
 	} 
 	else {
	 	MessageBox(NULL,TEXT("���Ի�ȡ�����һ�����ˣ�"),TEXT("ѡ��"),MB_RETRYCANCEL | MB_ICONINFORMATION);
	 }
 	

	return 0;
}
