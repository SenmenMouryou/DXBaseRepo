/**
* 地图管理器类
*/

#pragma once

#include "MapContainer.h"
#include "MapTemplateFile.h"

class MapManager {
public:
	MapManager(LPDIRECT3DDEVICE9 d3ddev);
	~MapManager();

	/**
	* 绘制当前地图
	*/
	void RendPresentMap(int SCREENW, int SCREENH);

	
	/*getter & setter*/
	void setPresentMap(MapContainer* map);

	void setPresentTemplate(MapTemplate* mapTemplate);

private:
	//d3d设备
	LPDIRECT3DDEVICE9 d3ddev;

	//精灵对象
	LPD3DXSPRITE spriteobj = NULL;

	//当前地图
	MapContainer * presentMap = NULL;
	//当前地图
	MapTemplate * presentTemplate = NULL;

	/**
	读取地图模板
	param:	filename 文件名
	return:	地图模板对象
	*/
	MapTemplate* readTempleteFromFile(string filename);

};

