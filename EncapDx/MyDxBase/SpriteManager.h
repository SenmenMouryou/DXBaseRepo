/*精灵管理器类*/

#pragma once
#include <list>
#include "Sprite.h"
#include "SpritePool.h"
#include "SpriteRender.h"

class SpriteManager {
public:
	SpriteManager(LPDIRECT3DDEVICE9 d3ddev);
	~SpriteManager();

	/**
	取得精灵
	param:	imageFile 图像,
	columns 图像列数,
	totFrame 图像总帧数,
	transcolor 图像透明色
	return: 初始化材质的精灵指针
	*/
	Sprite* GetSprite(string imageFile,
					  int x, int y,
					  int width, int height,
					  int columns = 1, int totFrame = 1,
					  D3DCOLOR transcolor = DEFAULT_TRANSCOLOR);

	/**
	放回精灵
	param:	sprite 待放回的精灵指针
	*/
	void PutSprite(Sprite* sprite);

	/**
	精灵碰撞检测
	param:	spt1: 精灵1,
			spt2: 精灵2
	return:	是否有碰撞
	*/
	bool Collision(Sprite* spt1, Sprite* spt2);

	/**
	渲染精灵图像
	*/
	void RendSprites();

	/*getter & setter*/
	LPD3DXSPRITE getSpriteobj();

private:
	//精灵对象
	LPD3DXSPRITE spriteobj = NULL;
	//精灵池
	SpritePool* spritePool = NULL;
	//使用中的精灵列表
	list<Sprite*> usingSprites;
	//精灵渲染器
	SpriteRender* spriteRender = NULL;

};

