#include "MapContainer.h"

MapContainer::MapContainer(MapTemplate* mapTemp) {
	center = { 0,0 };
	int data[400];
	for (int i = 0; i < 400; i++) {
		data[i] = 0;
	}
	layer1 = new MapLayer(mapTemp, data, 20, 20);

}

MapContainer::MapContainer(string mapFile) {

}

MapContainer::~MapContainer() {
	if (layer1 != NULL) {
		delete layer1;
	}
	if (layer2 != NULL) {
		delete layer2;
	}
	if (layer2 != NULL) {
		delete layer3;
	}
}

void MapContainer::RendMapLayers(LPD3DXSPRITE spriteobj, int SCREENW, int SCREENH) {
	if (layer1 != NULL) {
		layer1->RendLayer(center, spriteobj, SCREENW, SCREENH);
	}
	if (layer2 != NULL) {
		layer2->RendLayer(center, spriteobj, SCREENW, SCREENH);
	}
	if (layer3 != NULL) {
		layer3->RendLayer(center, spriteobj, SCREENW, SCREENH);
	}
}

void MapContainer::ScrollMap(int deltaX, int deltaY) {
	center.x += deltaX;
	center.y += deltaY;
}

MAP_COORD MapContainer::getCenter() {
	return center;
}

void MapContainer::setCenter(int x, int y) {
	center = { x, y };
}
