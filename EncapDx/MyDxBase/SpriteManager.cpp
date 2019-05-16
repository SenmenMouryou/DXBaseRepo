#include "SpriteManager.h"

SpriteManager::SpriteManager(LPDIRECT3DDEVICE9 d3ddev) {
	//初始化精灵对象
	D3DXCreateSprite(d3ddev, &spriteobj);
	//初始化精灵池
	spritePool = new SpritePool(d3ddev);
	//初始化精灵渲染器
	spriteRender = new SpriteRender(d3ddev, spriteobj, usingSprites);
}


SpriteManager::~SpriteManager() {
	//释放精灵对象
	if (spriteobj) {
		spriteobj->Release();
		spriteobj = NULL;
	}
	if (!usingSprites.empty()) {
		list<Sprite*>::iterator iter;
		for (iter = usingSprites.begin(); iter != usingSprites.end(); iter++) {
			spritePool->PutSprite(*iter);
		}
	}
	//释放精灵池
	delete spritePool;
	//释放渲染器
	delete spriteRender;
}

Sprite * SpriteManager::GetSprite(string imageFile, int x, int y, int width, int height,
								  int columns, int totFrame, D3DCOLOR transcolor) {
	Sprite* sprite = spritePool->GetSprite(imageFile, x, y, width, height, columns, totFrame, transcolor);
	usingSprites.push_back(sprite);
	return sprite;
}

void SpriteManager::PutSprite(Sprite * sprite) {
	usingSprites.remove(sprite);
	spritePool->PutSprite(sprite);
}

bool SpriteManager::Collision(Sprite * spt1, Sprite * spt2) {
	RECT rect1;
	rect1.left = (long)spt1->getX();
	rect1.top = (long)spt1->getY();
	rect1.right = (long)spt1->getX() + spt1->getWidth()*spt1->getScaling();
	rect1.bottom = (long)spt1->getY() + spt1->getHeight()*spt1->getScaling();

	RECT rect2;
	rect2.left = (long)spt2->getX();
	rect2.top = (long)spt2->getY();
	rect2.right = (long)spt2->getX() + spt2->getWidth()*spt2->getScaling();
	rect2.bottom = (long)spt2->getY() + spt2->getHeight()*spt2->getScaling();

	RECT dest;
	return IntersectRect(&dest, &rect1, &rect2);
}

void SpriteManager::RendSprites() {
	spriteRender->RendSprites();
}

LPD3DXSPRITE SpriteManager::getSpriteobj() {
	return spriteobj;
}


