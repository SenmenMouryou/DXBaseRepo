/*精灵池*/
#pragma once

#include <list>
#include "Sprite.h"

class SpritePool {
public:
	SpritePool(LPDIRECT3DDEVICE9 d3ddev);
	~SpritePool();

	/**
	取得池中的精灵对象指针,初始化材质
	param:	imageFile 图像,
			columns 图像列数,
			totFrame 图像总帧数, 
			transcolor 图像透明色
	return: 初始化材质的精灵对象指针
	*/
	Sprite* GetSprite(string imageFile,
					  int x, int y,
					  int width, int height,
					  int columns = 1, int totFrame = 1,
					 D3DCOLOR transcolor = DEFAULT_TRANSCOLOR);

	/**
	放回精灵对象指针
	param: sprite 待放回精灵池的精灵对象指针 
	*/
	void PutSprite(Sprite* sprite);
	
private:
	//d3d设备
	LPDIRECT3DDEVICE9 d3ddev = NULL;
	//初始化精灵数量
	const int INIT_SPRITES = 20;
	//一次增加的精灵数量
	const int ADDED_SPRITES_A_TIME = 10;
	//精灵池
	list<Sprite*> reservedSprites;

	//初始化精灵池
	void InitSpriteList();

};

