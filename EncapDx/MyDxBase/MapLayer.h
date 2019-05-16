#pragma once
/**
地图图层
*/

#include "MapTemplate.h"

//地图坐标结构体
typedef struct mapCoord {
	int x;
	int y;
}MAP_COORD;

class MapLayer {
public:
	/**
	构造器
	param:	mapTemplate 地图模板
			mapData 地图数据
			mapDataLen 地图数据长度
	*/
	MapLayer(MapTemplate* mapTemplate, int mapData[], int mapWidth, int mapHeight);
	~MapLayer();

	/**
	绘制此地图层
	*/
	void RendLayer(MAP_COORD center, LPD3DXSPRITE spriteobj, int SCREENW, int SCREENH);

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

