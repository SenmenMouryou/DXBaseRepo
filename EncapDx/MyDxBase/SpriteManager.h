/*�����������*/

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
	* ȡ�þ���
	* @param imageFile{string} ͼ��
	* @param x{int} ����xλ��
	* @param y{int} ����yλ��
	* @param columns{int} ͼ������
	* @param totFrame{int} ������֡��
	* @param transcolor{D3DCOLOR} ͼ��͸��ɫ
	return: ��ʼ�����ʵľ���ָ��
	*/
	Sprite* GetSprite(string imageFile,
					  int x, int y,
					  int width, int height,
					  int columns = 1, int totFrame = 1,
					  D3DCOLOR transcolor = DEFAULT_TRANSCOLOR);

	/**
	* �Żؾ���
	* @param sprite{Sprite*} ���Żصľ���ָ��
	*/
	void RecoverSprite(Sprite* sprite);

	/**
	* ������ײ���
	* @param spt1{Sprite*} ����1
	* @param spt2{Sprite*} ����2
	* @return �Ƿ�����ײ
	*/
	bool Collision(Sprite* spt1, Sprite* spt2);

	/**
	* ��Ⱦ����ͼ��
	*/
	void RendSprites();

	/*getter & setter*/
	LPD3DXSPRITE getSpriteobj();

private:
	//�������
	LPD3DXSPRITE spriteobj = NULL;
	//�����
	SpritePool* spritePool = NULL;
	//ʹ���еľ����б�
	list<Sprite*> usingSprites;
	//������Ⱦ��
	SpriteRender* spriteRender = NULL;

};

