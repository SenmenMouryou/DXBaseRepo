#pragma once

#include <Windows.h>
#include "DirectXClass.h"
#include "MapTemplate.h"

#define KAITI24 textManager->getFontManager()->getFont_Kaiti24()
#define HEITI30 textManager->getFontManager()->getFont_Heiti30()

class GameSystem {
public:
	GameSystem(HWND hWnd);
	~GameSystem();

	//资源初始化
	void GameInit();

	//运行游戏循环
	void GameLoop(HWND hWnd);

	//释放资源
	void GameEnd();

	/*getter & setter*/
	bool getBtnUp();
	bool getBtnDown();
	bool getBtnLeft();
	bool getBtnRight();
	bool getBtn_1();
	bool getBtn_2();
	bool getBtn_3();

private:
	int SCREENW = 1024;	//屏宽默认值
	int SCREENH = 720;	//屏高默认值
	bool fullScreen = false;	//全屏默认值

	//DX工具包对象
	DirectXClass* directXPack = NULL;

	//DX输入读取
	DInputClass* dInputer = NULL;

	//精灵管理器
	SpriteManager* spriteManager = NULL;

	//文本管理器
	TextManager* textManager = NULL;

	//地图管理器
	MapManager* mapManager = NULL;

	//有效按键定义
	const int BTN_UP = DIK_UP;
	const int BTN_DOWN = DIK_DOWN;
	const int BTN_LEFT = DIK_LEFT;
	const int BTN_RIGHT = DIK_RIGHT;
	const int BTN_1 = DIK_Z;
	const int BTN_2 = DIK_X;
	const int BTN_3 = DIK_C;

	//记录按键按下状态
	bool btnUp = false;
	bool btnDown = false;
	bool btnLeft = false;
	bool btnRight = false;
	bool btn_1 = false;
	bool btn_2 = false;
	bool btn_3 = false;

	/**
	* 游戏更新函数
	*/
	void GameUpdate();

	/**
	* 渲染图像
	*/
	void GameRender();

	/**
	* 键盘输入处理
	*/
	void HandleKeyboardInput();

	//测试精灵
	Sprite* sprite1;

};

