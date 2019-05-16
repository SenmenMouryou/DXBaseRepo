#include "MapLayer.h"

MapLayer::MapLayer(MapTemplate * mapTemplate, int mapData[], int mapWidth, int mapHeight) {
	this->mapTemplate = mapTemplate;
	this->width = mapWidth;
	this->height = mapHeight;
	this->mapDataLen = mapWidth * mapHeight;
	this->mapData = new int[mapDataLen];
	for (int i = 0; i < mapDataLen; i++) {
		this->mapData[i] = mapData[i];
	}
}

MapLayer::~MapLayer() {
	delete mapData;
}

void MapLayer::RendLayer(MAP_COORD center, LPD3DXSPRITE spriteobj, int SCREENW, int SCREENH) {

	//显示中心位置坐标
	int x = center.x;
	int y = center.y;
	//图块宽高
	int tileWidth = mapTemplate->getTileWidth();
	int tileHeight = mapTemplate->getTileHeight();	
	//屏幕宽幅图块数
	int screenTilesW = SCREENW / tileWidth;
	//屏幕高幅图块数
	int screenTilesH = SCREENH / tileHeight;
	//起始绘制位置坐标
	MAP_COORD startCoord;
	//如果起始坐标不是最左端
	if (x - screenTilesW / 2 >= 1) {
		startCoord.x = x - screenTilesW / 2 - 1;
	}
	//是最左端
	else {
		startCoord.x = 0;
	}
	//如果起始坐标不是最上端
	if (y - screenTilesH / 2 >= 1) {
		startCoord.y = y - screenTilesH / 2 - 1;
	}
	//是最上端
	else {
		startCoord.y = 0;
	}

	//起始和终止绘制的图块索引
	int startTileNum = width * startCoord.y + startCoord.x;
	int endTileNum = startTileNum + (screenTilesW * screenTilesH) - 1;

	for (int i = startTileNum; i < mapDataLen && i<endTileNum; i++) {
		//当前绘制图块的坐标
		MAP_COORD thisTile = { i % width, i / width };

		int destx = SCREENW / 2 - tileWidth / 2 + (thisTile.x - center.x) * tileWidth;
		int desty = SCREENH / 2 - tileHeight / 2 + (thisTile.y - center.y) * tileHeight;
		mapTemplate->DrawTile(destx, desty, mapData[i], spriteobj);
	}
}

