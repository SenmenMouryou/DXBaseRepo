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

	//��ʾ����λ������
	int x = center.x;
	int y = center.y;
	//ͼ����
	int tileWidth = mapTemplate->getTileWidth();
	int tileHeight = mapTemplate->getTileHeight();	
	//��Ļ���ͼ����
	int screenTilesW = SCREENW / tileWidth;
	//��Ļ�߷�ͼ����
	int screenTilesH = SCREENH / tileHeight;
	//��ʼ����λ������
	MAP_COORD startCoord;
	//�����ʼ���겻�������
	if (x - screenTilesW / 2 >= 1) {
		startCoord.x = x - screenTilesW / 2 - 1;
	}
	//�������
	else {
		startCoord.x = 0;
	}
	//�����ʼ���겻�����϶�
	if (y - screenTilesH / 2 >= 1) {
		startCoord.y = y - screenTilesH / 2 - 1;
	}
	//�����϶�
	else {
		startCoord.y = 0;
	}

	//��ʼ����ֹ���Ƶ�ͼ������
	int startTileNum = width * startCoord.y + startCoord.x;
	int endTileNum = startTileNum + (screenTilesW * screenTilesH) - 1;

	for (int i = startTileNum; i < mapDataLen && i<endTileNum; i++) {
		//��ǰ����ͼ�������
		MAP_COORD thisTile = { i % width, i / width };

		int destx = SCREENW / 2 - tileWidth / 2 + (thisTile.x - center.x) * tileWidth;
		int desty = SCREENH / 2 - tileHeight / 2 + (thisTile.y - center.y) * tileHeight;
		mapTemplate->DrawTile(destx, desty, mapData[i], spriteobj);
	}
}

