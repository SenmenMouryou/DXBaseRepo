#pragma once

#include <list>
#include "MapLayer.h"

using namespace std;

class MapContainer {
public:

	/**
	�����ù�����
	*/
	MapContainer(MapTemplate* mapTemp);

	/**
	������
	param:	mapFile ��ͼ�ļ�
	*/
	MapContainer(string mapFile);

	~MapContainer();

	/**
	���Ƶ�ͼ��ͼ��
	param:	spriteobj ���Ƶľ������
			SCREENW ��Ļ��
			SCREENH ��Ļ��
	*/
	void RendMapLayers(LPD3DXSPRITE spriteobj, int SCREENW, int SCREENH);

	/**
	����ͼ
	param:	deltaX �仯��xֵ
			deltaY �仯��yֵ
	*/
	void ScrollMap(int deltaX, int deltaY);

	/*getter & setter*/

	MAP_COORD getCenter();

	void setCenter(int x, int y);

private:
	//��ͼͼ��
	MapLayer* layer1 = NULL;
	MapLayer* layer2 = NULL;
	MapLayer* layer3 = NULL;

	//������������
	MAP_COORD center = {0,0};
};

