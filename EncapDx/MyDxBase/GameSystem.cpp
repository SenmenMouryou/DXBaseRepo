#include "GameSystem.h"

GameSystem::GameSystem(HWND hWnd) {
	directXPack = new DirectXClass(hWnd, SCREENW, SCREENH, fullScreen);

	dInputer = directXPack->getDInputer();

	GameInit();
}

GameSystem::~GameSystem() {
	GameEnd();

	delete directXPack;
}

void GameSystem::GameInit() {

	//初始化精灵管理器
	spriteManager = directXPack->getSpriteManager();
	//初始化文本管理器
	textManager = directXPack->getTextManager();
	//初始化地图管理器
	mapManager = directXPack->getMapManager();

	//测试精灵
	sprite1 = spriteManager->GetSprite("assets/bucket.png", 0, 0, 128, 128);

}

void GameSystem::GameLoop(HWND hWnd) {

	//检查D3D设备可用
	if (!directXPack->getD3ddev()) {
		MessageBox(hWnd, "错误：d3d设备未正常运行", "Error", 0);
		return;
	}
	//处理按键
	HandleKeyboardInput();
	
	if (btnDown) {
		sprite1->setXY(sprite1->getX(), sprite1->getY() + 1);
	}
	if (btnUp) {
		sprite1->setXY(sprite1->getX(), sprite1->getY() - 1);
	}
	if (btnRight) {
		sprite1->setXY(sprite1->getX() + 1, sprite1->getY());
	}
	if (btnLeft) {
		sprite1->setXY(sprite1->getX() - 1, sprite1->getY());
	}

	//渲染场景
	directXPack->RendScene();
}

void GameSystem::GameEnd() {
	spriteManager->PutSprite(sprite1);
	
}

bool GameSystem::getBtnUp() {
	return btnUp;
}

bool GameSystem::getBtnDown() {
	return btnDown;
}

bool GameSystem::getBtnLeft() {
	return btnLeft;
}

bool GameSystem::getBtnRight() {
	return btnRight;
}

bool GameSystem::getBtn_1() {
	return btn_1;
}

bool GameSystem::getBtn_2() {
	return btn_2;
}

bool GameSystem::getBtn_3() {
	return btn_3;
}

void GameSystem::HandleKeyboardInput() {
	dInputer->DInputUpdate();
	//UP
	if (dInputer->Key_Down(BTN_UP)) {
		btnUp = true;
	}
	else {
		btnUp = false;
	}
	//DOWN
	if (dInputer->Key_Down(BTN_DOWN)) {
		btnDown = true;
	}
	else {
		btnDown = false;
	}
	//LEFT
	if (dInputer->Key_Down(BTN_LEFT)) {
		btnLeft = true;
	}
	else {
		btnLeft = false;
	}
	//RIGHT
	if (dInputer->Key_Down(BTN_RIGHT)) {
		btnRight = true;
	}
	else {
		btnRight = false;
	}
	//按钮1
	if (dInputer->Key_Down(BTN_1)) {
		btn_1 = true;
	}
	else {
		btn_1= false;
	}
	//按钮2
	if (dInputer->Key_Down(BTN_2)) {
		btn_2 = true;
	}
	else {
		btn_2= false;
	}
	//按钮3
	if (dInputer->Key_Down(BTN_3)) {
		btn_3 = true;
	}
	else {
		btn_3= false;
	}

}
