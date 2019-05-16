#pragma once
#include "DirectXClass.h"
using namespace std;

class Window {
public:
	Window(HINSTANCE hInstance, int nCmdShow);
	~Window();

	static bool gameover;

	//注册窗口
	void RegistWndClass();
	//创建窗口句柄
	void InitHWnd();

	//窗口消息
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
	//程序句柄
	HINSTANCE hInstance;
	//注册窗口类
	WNDCLASSEX wc;
	//窗口句柄
	HWND hWnd;
	int nCmdShow;
	
};

//消息回调函数
LRESULT WINAPI WinProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

