#pragma once

#include <list>
#include "MapLayer.h"

using namespace std;

class MapContainer {
public:

	/**
	* �����ù�����
	*/
	MapContainer(MapTemplate* mapTemp);

	/**
	* ������
	* @param mapFile{string} ��ͼ�ļ�
	*/
	MapContainer(string mapFile);

	~MapContainer();

	/**
	* ���Ƶ�ͼ��ͼ��
	* @param spriteobj{LPD3DXSPRITE} ���Ƶľ������
	* @param SCREENW{int} ��Ļ��
	* @param SCREENH{int} ��Ļ��
	*/
	void RendMapLayers(LPD3DXSPRITE spriteobj, int SCREENW, int SCREENH);

	/**
	* ����ͼ
	* @param deltaX{int} �仯��xֵ
	* @param deltaY{int} �仯��yֵ
	*/
	void ScrollMap(int deltaX, int deltaY);

	/**
	* ��ѯ��ͼ���񲻿�ͨ����Ϣ
	* @param x{int} ��ѯ��x����
	* @param y{int} ��ѯ��y����
	* @return ����Ƿ񲻿�ͨ��
	*/
	void GridObInfo(int x, int y);

	/*getter & setter*/

	MAP_GRID getCenter();

	void setCenter(int x, int y);

private:
	//��ͼ��С
	int mapWidth;
	int mapHeight;

	//��ͼͼ��
	MapLayer* layer1 = NULL;
	MapLayer* layer2 = NULL;
	MapLayer* layer3 = NULL;
	
	//����ͨ��������
	OB_NODE* obGrid;

	//������������
	MAP_GRID center = {0,0};
};

