/**
* 地图文件类
*/
#pragma once

#include <iostream>

using namespace std;

class MapFile {
public:
	MapFile();
	~MapFile();

private:
	//地图宽
	int mapWidth;
	//地图高
	int mapHeight;
	//模板文件
	string templateFile;
	//图块数据
	int* layerData[3];
};

