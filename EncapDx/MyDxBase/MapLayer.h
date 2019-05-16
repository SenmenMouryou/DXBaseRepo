#pragma once
/**
��ͼͼ��
*/

#include "MapTemplate.h"

//��ͼ����ṹ��
typedef struct mapGrid {
	int x;
	int y;
}MAP_GRID;

class MapLayer {
public:
	/**
	* ������
	* @param mapTemplate{MapTemplate*} ��ͼģ��
	* @param mapData{int[]} ��ͼ����
	* @param mapWidth{int} ��ͼ������
	* @param mapHeight{int} ��ͼ������
	*/
	MapLayer(MapTemplate* mapTemplate, int mapData[], int mapWidth, int mapHeight);
	~MapLayer();

	/**
	* ���ƴ˵�ͼ��
	* @param center{MAP_GRID} ���ĸ�
	* @param spriteobj{LPD3DXSPRITE} �������
	* @param SCREENW{int} ��Ļ������
	* @param SCREENH{int} ��Ļ������
	*/
	void RendLayer(MAP_GRID center, LPD3DXSPRITE spriteobj, int SCREENW, int SCREENH);

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

