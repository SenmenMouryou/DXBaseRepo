#pragma once

#include <list>
#include "MapLayer.h"

using namespace std;

class MapContainer {
public:

	/**
	* 测试用构造器
	*/
	MapContainer(MapTemplate* mapTemp);

	/**
	* 构造器
	* @param mapFile{string} 地图文件
	*/
	MapContainer(string mapFile);

	~MapContainer();

	/**
	* 绘制地图各图层
	* @param spriteobj{LPD3DXSPRITE} 绘制的精灵对象
	* @param SCREENW{int} 屏幕宽
	* @param SCREENH{int} 屏幕高
	*/
	void RendMapLayers(LPD3DXSPRITE spriteobj, int SCREENW, int SCREENH);

	/**
	* 卷动地图
	* @param deltaX{int} 变化的x值
	* @param deltaY{int} 变化的y值
	*/
	void ScrollMap(int deltaX, int deltaY);

	/**
	* 查询地图方格不可通行信息
	* @param x{int} 查询点x坐标
	* @param y{int} 查询点y坐标
	* @return 结点是否不可通行
	*/
	void GridObInfo(int x, int y);

	/*getter & setter*/

	MAP_GRID getCenter();

	void setCenter(int x, int y);

private:
	//地图大小
	int mapWidth;
	int mapHeight;

	//地图图层
	MapLayer* layer1 = NULL;
	MapLayer* layer2 = NULL;
	MapLayer* layer3 = NULL;
	
	//不可通行性网格
	OB_NODE* obGrid;

	//绘制中心坐标
	MAP_GRID center = {0,0};
};

