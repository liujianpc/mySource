#include <windows.h>

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	/* TODO: Place code here.*/
 	int ans=MessageBox(NULL,TEXT("���Ƿ�����ʮ���꣡"),TEXT("����"),MB_YESNOCANCEL | MB_ICONQUESTION);
	 if(ans==IDYES){
 		MessageBox(NULL,TEXT("����Կ�AƬ�ˣ�"),TEXT("�ش�"),MB_OK);
 	} 
 	else {
	 	MessageBox(NULL,TEXT("δ�������겻׼��AƬ"),TEXT("�ش�"),MB_OK | MB_ICONINFORMATION);
	 }
 	

	return 0;
}
