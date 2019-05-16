#include "SpriteRender.h"

SpriteRender::SpriteRender(LPDIRECT3DDEVICE9 d3ddev,
						   LPD3DXSPRITE spriteobj, list<Sprite*> &spriteList) {
	this->d3ddev = d3ddev;
	this->spriteobj = spriteobj;
	this->spriteList = &spriteList;
}

SpriteRender::~SpriteRender() {
}

void SpriteRender::RendSprites() {
	//开始绘制
	spriteobj->Begin(D3DXSPRITE_ALPHABLEND);

	//绘制精灵
	list<Sprite*>::iterator iter;
	for (iter = spriteList->begin(); iter != spriteList->end(); iter++) {
		Sprite* sprite = *iter;
		sprite->DrawSprite(spriteobj);
	}

	//停止绘制
	spriteobj->End();
}

