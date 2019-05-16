#include "MapManager.h"



MapManager::MapManager(LPDIRECT3DDEVICE9 d3ddev) {

	this->d3ddev = d3ddev;
	//��ʼ���������
	D3DXCreateSprite(d3ddev, &spriteobj);

	//���ص�ͼģ��
	setPresentTemplate(readTempleteFromFile("rsrc/map/001-Grassland01.maptp"));

	//�������Ե�ͼ
	MapContainer* map1 = new MapContainer(presentTemplate);

	//�趨��ǰ��ͼ
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
	//��ʼ����
	spriteobj->Begin(D3DXSPRITE_ALPHABLEND);

	if (presentMap != NULL) {
		presentMap->RendMapLayers(spriteobj, SCREENW, SCREENH);
	}
	
	//ֹͣ����
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
