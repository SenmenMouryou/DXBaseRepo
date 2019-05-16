#pragma once
/**
��ͼͼ��
*/

#include "MapTemplate.h"

//��ͼ����ṹ��
typedef struct mapCoord {
	int x;
	int y;
}MAP_COORD;

class MapLayer {
public:
	/**
	������
	param:	mapTemplate ��ͼģ��
			mapData ��ͼ����
			mapDataLen ��ͼ���ݳ���
	*/
	MapLayer(MapTemplate* mapTemplate, int mapData[], int mapWidth, int mapHeight);
	~MapLayer();

	/**
	���ƴ˵�ͼ��
	*/
	void RendLayer(MAP_COORD center, LPD3DXSPRITE spriteobj, int SCREENW, int SCREENH);

private:

	//��ͼ�����곤��
	int width;
	int height;

	//��ͼģ��
	MapTemplate* mapTemplate;

	//��ͼ����
	int* mapData;
	//��ͼ���ݳ���
	int mapDataLen;

};

