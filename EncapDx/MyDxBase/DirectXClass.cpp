#include "DirectXClass.h"

DirectXClass::DirectXClass(HWND hWnd, int SCREENW, int SCREENH, bool fullScreen) {
	this->hWnd = hWnd;
	this->SCREENW = SCREENW;
	this->SCREENH = SCREENH;
	this->fullScreen = fullScreen;

	if (Direct3D_Init()) {
		//创建dx输入读取器
		dInputer = new DInputClass(hWnd, d3ddev);

		//创建精灵对管理器
		spriteManager = new SpriteManager(d3ddev);
		//创建字体管理器
		textManager = new TextManager(d3ddev);
		//创建地图管理器
		mapManager = new MapManager(d3ddev);
	}
	else {
		MessageBox(hWnd, "Direct3D初始化失败", "Error", 0);
	}
}

DirectXClass::~DirectXClass() {
	this->Direct3D_Shutdown();
}

void DirectXClass::RendScene() {
	//清除后缓存
	d3ddev->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
				  D3DCOLOR_XRGB(0, 0, 100), 1.0f, 0);
	d3ddev->ColorFill(backbuffer, NULL, D3DCOLOR_XRGB(0, 0, 0));

	//开始渲染
	if (d3ddev->BeginScene()) {

		//渲染地图
		mapManager->RendPresentMap(SCREENW, SCREENH);

		//渲染精灵
		spriteManager->RendSprites();

		//渲染文本
		textManager->RendTextList();

		//停止渲染
		d3ddev->EndScene();
		d3ddev->Present(NULL, NULL, NULL, NULL);
	}


}

bool DirectXClass::Direct3D_Init() {
	//初始化d3d对象
	d3d = Direct3DCreate9(D3D_SDK_VERSION);
	if (!d3d) {
		return false;
	}
	//设置d3d呈现参数
	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = (!fullScreen);
	d3dpp.SwapEffect = D3DSWAPEFFECT_COPY;
	d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
	d3dpp.BackBufferCount = 1;
	d3dpp.BackBufferWidth = SCREENW;
	d3dpp.BackBufferHeight = SCREENH;
	d3dpp.hDeviceWindow = hWnd;
	//创建D3D设备
	d3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd,
					  D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &d3ddev);
	if (!d3ddev) {
		return false;
	}
	//取得后缓存指针
	d3ddev->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &backbuffer);

	return true;
}

void DirectXClass::Direct3D_Shutdown() {
	if (dInputer != NULL) {
		delete dInputer;
	}
	if (spriteManager != NULL) {
		delete spriteManager;
	}
	if (textManager != NULL) {
		delete textManager;
	}
	if (mapManager != NULL) {
		delete mapManager;
	}
	if (d3ddev) {
		d3ddev->Release();
		d3ddev = NULL;
	}
	if (d3d) {
		d3d->Release();
		d3d = NULL;
	}
}

LPDIRECT3DDEVICE9 DirectXClass::getD3ddev() {
	return this->d3ddev;
}

LPDIRECT3DSURFACE9 DirectXClass::getBackbuffer() {
	return backbuffer;
}

DInputClass * DirectXClass::getDInputer() {
	return dInputer;
}

SpriteManager* DirectXClass::getSpriteManager() {
	return spriteManager;
}

TextManager* DirectXClass::getTextManager() {
	return textManager;
}

MapManager * DirectXClass::getMapManager() {
	return mapManager;
}

