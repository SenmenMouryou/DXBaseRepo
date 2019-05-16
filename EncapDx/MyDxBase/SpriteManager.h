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
	* 取得精灵
	* @param imageFile{string} 图像
	* @param x{int} 精灵x位置
	* @param y{int} 精灵y位置
	* @param columns{int} 图像列数
	* @param totFrame{int} 精灵总帧数
	* @param transcolor{D3DCOLOR} 图像透明色
	return: 初始化材质的精灵指针
	*/
	Sprite* GetSprite(string imageFile,
					  int x, int y,
					  int width, int height,
					  int columns = 1, int totFrame = 1,
					  D3DCOLOR transcolor = DEFAULT_TRANSCOLOR);

	/**
	* 放回精灵
	* @param sprite{Sprite*} 待放回的精灵指针
	*/
	void RecoverSprite(Sprite* sprite);

	/**
	* 精灵碰撞检测
	* @param spt1{Sprite*} 精灵1
	* @param spt2{Sprite*} 精灵2
	* @return 是否有碰撞
	*/
	bool Collision(Sprite* spt1, Sprite* spt2);

	/**
	* 渲染精灵图像
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

