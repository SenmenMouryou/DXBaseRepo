/**
* ��ͼ��������
*/

#pragma once

#include "MapContainer.h"
#include "MapTemplateFile.h"

class MapManager {
public:
	MapManager(LPDIRECT3DDEVICE9 d3ddev);
	~MapManager();

	/**
	* ���Ƶ�ǰ��ͼ
	* @param SCREENW{int}
	* @param SCREENH{int}
	*/
	void RendPresentMap(int SCREENW, int SCREENH);

	
	/*getter & setter*/
	void setPresentMap(MapContainer* map);

	void setPresentTemplate(MapTemplate* mapTemplate);

private:
	//d3d�豸
	LPDIRECT3DDEVICE9 d3ddev;

	//�������
	LPD3DXSPRITE spriteobj = NULL;

	//��ǰ��ͼ
	MapContainer * presentMap = NULL;
	//��ǰ��ͼ
	MapTemplate * presentTemplate = NULL;

	/**
	* ��ȡ��ͼģ��
	* @param filename{string} �ļ���
	* @return ��ͼģ�����
	*/
	MapTemplate* readTempleteFromFile(string filename);

};

