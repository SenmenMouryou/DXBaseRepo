#include "SpritePool.h"

SpritePool::SpritePool(LPDIRECT3DDEVICE9 d3ddev) {
	this->d3ddev = d3ddev;
	InitSpriteList();
}

SpritePool::~SpritePool() {
	list<Sprite*>::iterator iter;
	for (iter = reservedSprites.begin(); iter != reservedSprites.end(); iter++) {
		delete *iter;
	}
}

Sprite* SpritePool::GetSprite(string imageFile, int x, int y, int width, int height, int columns, 
							  int totFrame, D3DCOLOR transcolor) {
	if (!reservedSprites.empty()) {
		Sprite* sprite = reservedSprites.back();
		sprite->setXY(x, y);
		sprite->setWH(width, height);
		reservedSprites.pop_back();
		sprite->initTexture(imageFile, columns, totFrame, transcolor);
		return sprite;
	}
	else {
		for (int i = 0; i < ADDED_SPRITES_A_TIME; i++) {
			Sprite* sprite = new Sprite(d3ddev);
			reservedSprites.push_back(sprite);
		}
		return GetSprite(imageFile, x, y, columns, totFrame, transcolor);
	}
}

void SpritePool::PutSprite(Sprite* sprite) {
	reservedSprites.push_back(sprite);
}

void SpritePool::InitSpriteList() {
	for (int i = 0; i < INIT_SPRITES; i+=1) {
		Sprite* sprite = new Sprite(d3ddev);
		reservedSprites.push_back(sprite);
	}
}