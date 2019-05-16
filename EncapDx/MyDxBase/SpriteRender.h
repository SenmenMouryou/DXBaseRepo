#pragma once

#include <d3d9.h>
#include <d3dx9.h>
#include <list>
#include "Sprite.h"

class SpriteRender {
public:
	SpriteRender(LPDIRECT3DDEVICE9 d3ddev,
				 LPD3DXSPRITE spriteobj, list<Sprite*> &spriteList);
	~SpriteRender();

	void RendSprites();

private:
	//d3d设备
	LPDIRECT3DDEVICE9 d3ddev = NULL;
	//精灵对象
	LPD3DXSPRITE spriteobj = NULL;
	//精灵列表指针
	list<Sprite*> *spriteList;

};

