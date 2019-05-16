#include "DInputClass.h"

DInputClass::DInputClass(HWND hWnd, LPDIRECT3DDEVICE9 d3ddev) {
	//初始Direct输入对象
	HRESULT result = DirectInput8Create(
		GetModuleHandle(NULL),
		DIRECTINPUT_VERSION,
		IID_IDirectInput8,
		(void**)&dinput,
		NULL
	);
	//初始化键盘
	dinput->CreateDevice(GUID_SysKeyboard, &dikeyboard, NULL);
	dikeyboard->SetDataFormat(&c_dfDIKeyboard);
	dikeyboard->SetCooperativeLevel(hWnd, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND);
	dikeyboard->Acquire();
	//初始化鼠标
	dinput->CreateDevice(GUID_SysMouse, &dimouse, NULL);
	dimouse->SetDataFormat(&c_dfDIMouse);
	dimouse->SetCooperativeLevel(hWnd, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND);
	dimouse->Acquire();
	d3ddev->ShowCursor(false);

}

DInputClass::~DInputClass() {
	if (dikeyboard) {
		dikeyboard->Unacquire();
		dikeyboard->Release();
		dikeyboard = NULL;
	}
	if (dimouse) {
		dimouse->Unacquire();
		dimouse->Release();
		dikeyboard = NULL;
	}
}

void DInputClass::DInputUpdate() {
	//更新鼠标
	dimouse->GetDeviceState(sizeof(mouse_state), (LPVOID)&mouse_state);
	//更新键盘
	dikeyboard->GetDeviceState(sizeof(keys), (LPVOID)&keys);

}

int DInputClass::Mouse_X() {
	return mouse_state.lX;
}

int DInputClass::Mouse_Y() {
	return mouse_state.lY;
}

int DInputClass::Mouse_Button(int button) {
	return mouse_state.rgbButtons[button] & 0x80;
}

int DInputClass::Key_Down(int key) {
	return (keys[key] & 0x80);
}
