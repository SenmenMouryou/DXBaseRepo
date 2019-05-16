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

	//��Դ��ʼ��
	void GameInit();

	//������Ϸѭ��
	void GameLoop(HWND hWnd);

	//�ͷ���Դ
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
	int SCREENW = 1024;	//����Ĭ��ֵ
	int SCREENH = 720;	//����Ĭ��ֵ
	bool fullScreen = false;	//ȫ��Ĭ��ֵ

	//DX���߰�����
	DirectXClass* directXPack = NULL;

	//DX�����ȡ
	DInputClass* dInputer = NULL;

	//���������
	SpriteManager* spriteManager = NULL;

	//�ı�������
	TextManager* textManager = NULL;

	//��ͼ������
	MapManager* mapManager = NULL;

	//��Ч��������
	const int BTN_UP = DIK_UP;
	const int BTN_DOWN = DIK_DOWN;
	const int BTN_LEFT = DIK_LEFT;
	const int BTN_RIGHT = DIK_RIGHT;
	const int BTN_1 = DIK_Z;
	const int BTN_2 = DIK_X;
	const int BTN_3 = DIK_C;

	//��¼��������״̬
	bool btnUp = false;
	bool btnDown = false;
	bool btnLeft = false;
	bool btnRight = false;
	bool btn_1 = false;
	bool btn_2 = false;
	bool btn_3 = false;

	/**
	* ��Ϸ���º���
	*/
	void GameUpdate();

	/**
	* ��Ⱦͼ��
	*/
	void GameRender();

	/**
	* �������봦��
	*/
	void HandleKeyboardInput();

	//���Ծ���
	Sprite* sprite1;

};

