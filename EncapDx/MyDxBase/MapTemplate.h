/*
��ͼģ����
*/
#pragma once

#include <iostream>
#include <d3d9.h>
#include <d3dx9.h>
#include <list>

#define DEFAULT_MAP_TRANSCOLOR D3DCOLOR_XRGB(255,255,255)

using namespace std;

#define DEFAULT_TILE_WIDTH 32
#define DEFAULT_TILE_HEIGHT 32

//��ͨ��������Ԫ
typedef struct obGridNode {
	bool ob_goUp;
	bool ob_goDown;
	bool ob_goLeft;
	bool ob_goRight;
}OB_NODE;

class MapTemplate {
public:

	/**
	������
	param:	d3ddev d3d�豸
			tileWidth ͼ���
			tileHeight ͼ���
			imageFile ͼ���ļ���
			columns ͼ������
			rows ͼ������
			obinfoArray ����ͨ����Ϣ����
			transcolor ͸��ɫ
	*/
	MapTemplate(LPDIRECT3DDEVICE9 d3ddev,
				string imageFile,
				int columns, int rows,
				OB_NODE* obinfoArray,
				D3DCOLOR transcolor);	

	~MapTemplate();

	/**
	��ͼ����Ϣ����ͼ��
	param:	x ����xλ��
			y ����yλ��
			tileNum ���Ƶ�ͼ������
			spriteobj ���ƾ���
	*/
	void DrawTile(int x, int y, int tileNum, LPD3DXSPRITE spriteobj);

	/*getter & setter*/
	int getTileWidth();

	int getTileHeight();

private:

	//d3d�豸
	LPDIRECT3DDEVICE9 d3ddev;

	//ͼ������
	int columns;
	//ͼ��������
	int rows;
	//ͼ���
	int tileWidth;
	//ͼ���
	int tileHeight;
	//ͼ���ļ���
	string imageFile;
	//ͼ������
	int tileNum;
	//͸��ɫ
	D3DCOLOR transcolor;

	//����ͨ����Ϣ����
	OB_NODE* obinfoArray = NULL;

	//ͼ�����
	LPDIRECT3DTEXTURE9 texture;
	//����ͼ�����
	void LoadTexture();
	//�ͷ�ͼ�����
	void ReleaseTexture();

};

