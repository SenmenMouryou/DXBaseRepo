#pragma once
/**
地图图层
*/

#include "MapTemplate.h"

//地图坐标结构体
typedef struct mapGrid {
	int x;
	int y;
}MAP_GRID;

class MapLayer {
public:
	/**
	* 构造器
	* @param mapTemplate{MapTemplate*} 地图模板
	* @param mapData{int[]} 地图数据
	* @param mapWidth{int} 地图宽像素
	* @param mapHeight{int} 地图高像素
	*/
	MapLayer(MapTemplate* mapTemplate, int mapData[], int mapWidth, int mapHeight);
	~MapLayer();

	/**
	* 绘制此地图层
	* @param center{MAP_GRID} 中心格
	* @param spriteobj{LPD3DXSPRITE} 精灵对象
	* @param SCREENW{int} 屏幕宽像素
	* @param SCREENH{int} 屏幕高像素
	*/
	void RendLayer(MAP_GRID center, LPD3DXSPRITE spriteobj, int SCREENW, int SCREENH);

private:

	//地图层坐标长宽
	int width;
	int height;

	//地图模板
	MapTemplate* mapTemplate;

	//地图数据
	int* mapData;
	//地图数据长度
	int mapDataLen;

};

