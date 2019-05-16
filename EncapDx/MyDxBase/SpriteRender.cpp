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
	//��ʼ����
	spriteobj->Begin(D3DXSPRITE_ALPHABLEND);

	//���ƾ���
	list<Sprite*>::iterator iter;
	for (iter = spriteList->begin(); iter != spriteList->end(); iter++) {
		Sprite* sprite = *iter;
		sprite->DrawSprite(spriteobj);
	}

	//ֹͣ����
	spriteobj->End();
}

