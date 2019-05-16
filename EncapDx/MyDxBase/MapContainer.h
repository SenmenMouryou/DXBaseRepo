#pragma once

#include <list>
#include "MapLayer.h"

using namespace std;

class MapContainer {
public:

	/**
	测试用构造器
	*/
	MapContainer(MapTemplate* mapTemp);

	/**
	构造器
	param:	mapFile 地图文件
	*/
	MapContainer(string mapFile);

	~MapContainer();

	/**
	绘制地图各图层
	param:	spriteobj 绘制的精灵对象
			SCREENW 屏幕宽
			SCREENH 屏幕高
	*/
	void RendMapLayers(LPD3DXSPRITE spriteobj, int SCREENW, int SCREENH);

	/**
	卷动地图
	param:	deltaX 变化的x值
			deltaY 变化的y值
	*/
	void ScrollMap(int deltaX, int deltaY);

	/*getter & setter*/

	MAP_COORD getCenter();

	void setCenter(int x, int y);

private:
	//地图图层
	MapLayer* layer1 = NULL;
	MapLayer* layer2 = NULL;
	MapLayer* layer3 = NULL;

	//绘制中心坐标
	MAP_COORD center = {0,0};
};

