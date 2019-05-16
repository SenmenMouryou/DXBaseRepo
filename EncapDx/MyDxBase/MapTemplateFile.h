/**
* 地图模板文件类
*/
#pragma once

#include <fstream>
#include "MapTemplate.h"

class MapTemplateFile {
public:
	MapTemplateFile();
	~MapTemplateFile();

	/**
	* 写入为文件
	* @param mapFilename 地图文件名
	* @return 写入成功情况
	*/
	bool wirteToFile(string mapFilename);

	/**
	* 从文件读取
	* @param mapFilename 地图文件名
	* @return 读取成功情况
	*/
	bool readFromFile(string mapFilename);

	/*getter & setter*/
	string getImageFile();

	int getColumns();

	int getRows();

	OB_NODE* getObinfoArray();

private:
	//地图模板图像
	string imageFile;
	//地图模板列数
	int columns;
	//地图模板行数
	int rows;
	//不可通行信息数组
	OB_NODE* obinfoArray = NULL;
};

