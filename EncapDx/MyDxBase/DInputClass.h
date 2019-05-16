#pragma once

#include <d3d9.h>
#include <d3dx9.h>
#include <dinput.h>
#include <xinput.h>
#include <ctime>

#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "xinput.lib")

class DInputClass {
public:
	DInputClass(HWND hWnd, LPDIRECT3DDEVICE9 d3ddev);
	~DInputClass();

	void DInputUpdate();

	//返回鼠标x移动
	int Mouse_X();

	//返回鼠标y移动
	int Mouse_Y();

	//返回鼠标按键状态
	int Mouse_Button(int button);

	//返回键盘按键状态
	int Key_Down(int key);

private:
	//Direct输入对象，设备，状态
	LPDIRECTINPUT8 dinput;
	LPDIRECTINPUTDEVICE8 dimouse;
	LPDIRECTINPUTDEVICE8 dikeyboard;
	DIMOUSESTATE mouse_state;
	char keys[256];

};

