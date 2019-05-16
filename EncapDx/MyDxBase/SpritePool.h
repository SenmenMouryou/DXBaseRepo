/*�����*/
#pragma once

#include <list>
#include "Sprite.h"

class SpritePool {
public:
	SpritePool(LPDIRECT3DDEVICE9 d3ddev);
	~SpritePool();

	/**
	ȡ�ó��еľ������ָ��,��ʼ������
	param:	imageFile ͼ��,
			columns ͼ������,
			totFrame ͼ����֡��, 
			transcolor ͼ��͸��ɫ
	return: ��ʼ�����ʵľ������ָ��
	*/
	Sprite* GetSprite(string imageFile,
					  int x, int y,
					  int width, int height,
					  int columns = 1, int totFrame = 1,
					 D3DCOLOR transcolor = DEFAULT_TRANSCOLOR);

	/**
	�Żؾ������ָ��
	param: sprite ���Żؾ���صľ������ָ�� 
	*/
	void PutSprite(Sprite* sprite);
	
private:
	//d3d�豸
	LPDIRECT3DDEVICE9 d3ddev = NULL;
	//��ʼ����������
	const int INIT_SPRITES = 20;
	//һ�����ӵľ�������
	const int ADDED_SPRITES_A_TIME = 10;
	//�����
	list<Sprite*> reservedSprites;

	//��ʼ�������
	void InitSpriteList();

};

