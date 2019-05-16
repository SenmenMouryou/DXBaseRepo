#pragma once
#include "DirectXClass.h"
using namespace std;

class Window {
public:
	Window(HINSTANCE hInstance, int nCmdShow);
	~Window();

	static bool gameover;

	//ע�ᴰ��
	void RegistWndClass();
	//�������ھ��
	void InitHWnd();

	//������Ϣ
	MSG wndMsg;

	//Getter & Setter
	string GetAppTitle();
	int GetScreenW();
	int GetScreenH();
	WNDCLASSEX GetWndClass();
	HWND GetHWnd();

private:
	const string APPTITLE = "My Encapsulation Dx Test";
	const int SCREENW = 1024;
	const int SCREENH = 720;
	//������
	HINSTANCE hInstance;
	//ע�ᴰ����
	WNDCLASSEX wc;
	//���ھ��
	HWND hWnd;
	int nCmdShow;
	
};

//��Ϣ�ص�����
LRESULT WINAPI WinProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

