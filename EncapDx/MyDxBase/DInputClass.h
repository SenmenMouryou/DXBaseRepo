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

	//�������x�ƶ�
	int Mouse_X();

	//�������y�ƶ�
	int Mouse_Y();

	//������갴��״̬
	int Mouse_Button(int button);

	//���ؼ��̰���״̬
	int Key_Down(int key);

private:
	//Direct��������豸��״̬
	LPDIRECTINPUT8 dinput;
	LPDIRECTINPUTDEVICE8 dimouse;
	LPDIRECTINPUTDEVICE8 dikeyboard;
	DIMOUSESTATE mouse_state;
	char keys[256];

};

