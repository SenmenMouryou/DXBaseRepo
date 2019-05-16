#include "MapManager.h"



MapManager::MapManager(LPDIRECT3DDEVICE9 d3ddev) {

	this->d3ddev = d3ddev;
	//初始化精灵对象
	D3DXCreateSprite(d3ddev, &spriteobj);

	//加载地图模板
	setPresentTemplate(readTempleteFromFile("rsrc/map/001-Grassland01.maptp"));

	//创建测试地图
	MapContainer* map1 = new MapContainer(presentTemplate);

	//设定当前地图
	setPresentMap(map1);
}


MapManager::~MapManager() {
	if (spriteobj) {
		spriteobj->Release();
	}
	if (presentMap) {
		delete presentMap;
	}
	if (presentTemplate) {
		delete presentTemplate;
	}
}

void MapManager::RendPresentMap(int SCREENW, int SCREENH) {
	//开始绘制
	spriteobj->Begin(D3DXSPRITE_ALPHABLEND);

	if (presentMap != NULL) {
		presentMap->RendMapLayers(spriteobj, SCREENW, SCREENH);
	}
	
	//停止绘制
	spriteobj->End();
	}

void MapManager::setPresentMap(MapContainer* map) {
	if (presentMap) {
		delete presentMap;
	}
	presentMap = map;
}

void MapManager::setPresentTemplate(MapTemplate * mapTemplate) {
	if (presentTemplate) {
		delete presentTemplate;
	}
	presentTemplate = mapTemplate;
}

MapTemplate* MapManager::readTempleteFromFile(string filename) {
	MapTemplateFile* file = new MapTemplateFile();

	if (file->readFromFile(filename)) {
		MapTemplate* mapTemplate
			= new MapTemplate(d3ddev,
							  file->getImageFile(),
							  file->getColumns(),
							  file->getRows(),
							  file->getObinfoArray(),
							  DEFAULT_MAP_TRANSCOLOR);
		delete file;
		return mapTemplate;
	}
	else {

		delete file;
		return NULL;
	}
}
