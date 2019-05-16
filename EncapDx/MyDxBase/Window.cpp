#include "Window.h"
#include "GameSystem.h"

bool Window::gameover = false;

Window::Window(HINSTANCE hInstance, int nCmdShow) {
	this->hInstance = hInstance;
	this->nCmdShow = nCmdShow;
	RegistWndClass();
	InitHWnd();

	if (hWnd != 0) {
		//显示窗口
		ShowWindow(hWnd, nCmdShow);
		UpdateWindow(hWnd);

		//初始化游戏程序
		GameSystem* gameSys = new GameSystem(hWnd);

		//主消息循环
		while (!gameover) {
			if (PeekMessage(&wndMsg, NULL, 0, 0, PM_REMOVE)) {
				TranslateMessage(&wndMsg);
				DispatchMessage(&wndMsg);
			}
			//游戏循环
			gameSys->GameLoop(hWnd);
		}
		//游戏程序结束
		delete gameSys;
	}

}


Window::~Window() {
}


/**
* 注册窗口
*/
void Window::RegistWndClass() {
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = (WNDPROC)WinProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = NULL;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = "MainWindowClass";
	wc.hIconSm = NULL;
	RegisterClassEx(&wc);

}

void Window::InitHWnd() {
	hWnd = CreateWindow("MainWindowClass", APPTITLE.c_str(),
						WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
						SCREENW, SCREENH, NULL, NULL, hInstance, NULL);
}

/*
* Getter & Setter
*/
string Window::GetAppTitle() {
	return APPTITLE;
}
int Window::GetScreenW() {
	return SCREENW;
}
int Window::GetScreenH() {
	return SCREENH;
}
WNDCLASSEX Window::GetWndClass() {
	return wc;
}

HWND Window::GetHWnd() {
	return hWnd;
}

LRESULT WINAPI WinProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg) {
		case WM_DESTROY: {
			Window::gameover = true;
			PostQuitMessage(0);
			return 0;
		}
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}


