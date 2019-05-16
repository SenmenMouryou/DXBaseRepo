#include "MapContainer.h"

MapContainer::MapContainer(MapTemplate* mapTemp) {
	center = { 0,0 };
	mapWidth = 20;
	mapHeight = 20;
	int data[400];
	for (int i = 0; i < 400; i++) {
		data[i] = 5;
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

MAP_GRID MapContainer::getCenter() {
	return center;
}

void MapContainer::setCenter(int x, int y) {
	if (x <= mapWidth && y <= mapHeight &&
		x >= 0 && y>=0) {
		center = { x, y };
	}
	else {
		if (x > mapWidth) {
			x = mapWidth;
		}
		else if (x < 0) {
			x = 0;
		}
		if (y > mapHeight) {
			y = mapHeight;
		}
		else if (y < 0) {
			y = 0;
		}
	}
}
