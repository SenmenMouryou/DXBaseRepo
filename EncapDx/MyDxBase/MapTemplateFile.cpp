#include "MapTemplateFile.h"

MapTemplateFile::MapTemplateFile() {
}

MapTemplateFile::~MapTemplateFile() {
	if (obinfoArray) {
		delete obinfoArray;
	}
}

bool MapTemplateFile::wirteToFile(string mapFilename) {
	ofstream out(mapFilename.c_str(), ios::out | ios::binary);
	if (!out) {
		MessageBox(0, "地图写入失败！", "错误", 0);
		return false;
	}
	//写入图片文件名
	out << imageFile.c_str() << endl;
	//写入行列信息
	out.write((char*)&columns, sizeof(int));
	out.write((char*)&rows, sizeof(int));
	//写入不可通行信息数组
	out.write((char*)obinfoArray, columns*rows*sizeof(OB_NODE));
	
	out.close();

	string message = "地图文件：";
	message += mapFilename;
	message += " 写入完成";
	MessageBox(0, message.c_str(), "通知", 0);

	return true;
}

bool MapTemplateFile::readFromFile(string mapFilename) {
	ifstream in(mapFilename.c_str(), ios::in | ios::binary);
	if (!in) {
		MessageBox(0, "地图模板文件打开失败", "错误", 0);
		return false;
	}
	//读取图片文件名
	const int LEN = 256;
	char tmpStr[LEN];
	in.getline(tmpStr, LEN);
	imageFile = tmpStr;
	//读取行列信息
	in.read((char*)&columns, sizeof(int));
	in.read((char*)&rows, sizeof(int));
	//读取不可通行信息数组
	delete obinfoArray;
	obinfoArray = new OB_NODE[columns*rows];
	in.read((char*)obinfoArray, columns*rows * sizeof(OB_NODE));

	in.close();

	return true;
}

string MapTemplateFile::getImageFile() {
	return imageFile;
}

int MapTemplateFile::getColumns() {
	return columns;
}

int MapTemplateFile::getRows() {
	return rows;
}

OB_NODE* MapTemplateFile::getObinfoArray() {
	return obinfoArray;
}
