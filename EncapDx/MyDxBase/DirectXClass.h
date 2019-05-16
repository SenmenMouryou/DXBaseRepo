#pragma once

#include <Windows.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <sstream>
#include <iostream>
#include "DInputClass.h"
#include "SpriteManager.h"
#include "DInputClass.h"
#include "TextManager.h"
#include "MapManager.h"

using namespace std;

#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

class DirectXClass {
public:
	DirectXClass(HWND hWnd, int SCREENW, int SCREENH, bool fullScreen);
	~DirectXClass();

	/**
	* 渲染场景
	*/
	void RendScene();

	//getter&setter
	LPDIRECT3DDEVICE9 getD3ddev();

	LPDIRECT3DSURFACE9 getBackbuffer();

	DInputClass* getDInputer();
	
	SpriteManager* getSpriteManager();

	TextManager* getTextManager();

	MapManager* getMapManager();

private:
	HWND hWnd = NULL;
	int SCREENW = 0;
	int SCREENH = 0;
	bool fullScreen = false;

	//D3D变量
	LPDIRECT3D9 d3d = NULL;
	LPDIRECT3DDEVICE9 d3ddev = NULL;
	LPDIRECT3DSURFACE9 backbuffer = NULL;

	//初始化d3d
	bool Direct3D_Init();
	void Direct3D_Shutdown();

	//DX输入读取器
	DInputClass* dInputer = NULL;
	
	//精灵管理器
	SpriteManager* spriteManager = NULL;

	//文本管理器
	TextManager* textManager = NULL;

	//地图管理器
	MapManager* mapManager = NULL;

};

