/*
地图模板类
*/
#pragma once

#include <iostream>
#include <d3d9.h>
#include <d3dx9.h>

#define DEFAULT_MAP_TRANSCOLOR D3DCOLOR_XRGB(255,255,255)

using namespace std;

#define DEFAULT_TILE_WIDTH 32
#define DEFAULT_TILE_HEIGHT 32

//可通行性网格单元
typedef struct obGridNode {
	bool ob_goUp;
	bool ob_goDown;
	bool ob_goLeft;
	bool ob_goRight;
}OB_NODE;

class MapTemplate {
public:

	/**
	* 构造器
	* @param d3ddev d3d设备
	* @param tileWidth 图块宽
	* @param tileHeight 图块高
	* @param imageFile 图像文件名
	* @param columns 图块列数
	* @param rows 图块行数
	* @param obinfoArray 不可通行信息数组
	* @param transcolor 透明色
	*/
	MapTemplate(LPDIRECT3DDEVICE9 d3ddev,
				string imageFile,
				int columns, int rows,
				OB_NODE* obinfoArray,
				D3DCOLOR transcolor);	

	~MapTemplate();

	/**
	* 按图块信息绘制图块
	* @param x 绘制x位置
	* @param y 绘制y位置
	* @param tileNum 绘制的图块索引
	* @param spriteobj 绘制精灵
	*/
	void DrawTile(int x, int y, int tileNum, LPD3DXSPRITE spriteobj);

	/*getter & setter*/
	int getTileWidth();

	int getTileHeight();

private:

	//d3d设备
	LPDIRECT3DDEVICE9 d3ddev;

	//图块列数
	int columns;
	//图块行数数
	int rows;
	//图块宽
	int tileWidth;
	//图块高
	int tileHeight;
	//图像文件名
	string imageFile;
	//图块数量
	int tileNum;
	//透明色
	D3DCOLOR transcolor;

	//不可通行信息数组
	OB_NODE* obinfoArray = NULL;

	//图像材质
	LPDIRECT3DTEXTURE9 texture;
	//加载图像材质
	void LoadTexture();
	//释放图像材质
	void ReleaseTexture();

};

