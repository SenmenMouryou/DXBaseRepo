/**
* 地图模板文件 写入
*/

#include "stdafx.h"

#include <iostream>
#include <fstream>

using namespace std;

//可通行性网格单元
typedef struct obGridNode {
	bool ob_goUp;
	bool ob_goDown;
	bool ob_goLeft;
	bool ob_goRight;
}OB_NODE;

int main()
{
	//地图文件名
	string mapTemplateFilename = "001-Grassland01.maptp";

	//模板图片文件名
	string templateImageFile = "assets/001-Grassland01.png";
	//行列数
	int columns = 8;
	int rows = 18;
	OB_NODE node_none = { false,false,false,false };
	OB_NODE node_all = { true,true,true,true };
	
#define n_N node_none
#define n_A node_all

	//不可通行数组
	OB_NODE obinfoArray[] = {
		n_N, n_N, n_N, n_N, n_A, n_N, n_N, n_N,
		n_N, n_N, n_N, n_N, n_A, n_N, n_N, n_N,
		n_N, n_N, n_N, n_N, n_N, n_N, n_A, n_N,
		n_N, n_N, n_N, n_N, n_N, n_A, n_A, n_A,
		n_N, n_N, n_N, n_N, n_N, n_N, n_N, n_N,
		
		n_N, n_N, n_N, n_N, n_N, n_N, n_N, n_N,
		n_N, n_N, n_N, n_N, n_N, n_N, n_N, n_N,
		n_N, n_A, n_A, n_N, n_N, n_A, n_A, n_N,
		n_N, n_A, n_A, n_N, n_N, n_A, n_A, n_N,
		n_N, n_A, n_A, n_N, n_N, n_A, n_A, n_N,

		n_A, n_A, n_A, n_A, n_A, n_N, n_N, n_N,
		n_A, n_A, n_N, n_N, n_N, n_A, n_A, n_A,
		n_A, n_A, n_A, n_A, n_A, n_N, n_A, n_N,
		n_N, n_N, n_N, n_N, n_N, n_N, n_A, n_N,
		n_A, n_A, n_A, n_A, n_A, n_A, n_A, n_N,
		n_A, n_A, n_A, n_A, n_A, n_N, n_N, n_N,
		n_A, n_A, n_A, n_A, n_A, n_N, n_N, n_N,
		n_A, n_A, n_A, n_A, n_A, n_N, n_N, n_N
	};

	string mapTemplateFilePath = "map/"+mapTemplateFilename;

	ofstream out(mapTemplateFilePath.c_str(), ios::out | ios::binary);
	if (!out) {
		cout << "地图模板文件写入失败！" << endl;
		exit(0);
	}
	//写入图片文件名
	out << templateImageFile.c_str() << endl;
	//写入行列信息
	out.write((char*)&columns, sizeof(int));
	out.write((char*)&rows, sizeof(int));
	//写入不可通行信息列表
	out.write((char*)obinfoArray, columns*rows * sizeof(OB_NODE));

	out.close();

	cout << "地图模板文件"<< mapTemplateFilename.c_str()<<"写入完成！" << endl;

	//================读取测试==================
	string readImageFile = "";
	int readColumns = 0;
	int readRows = 0;
	OB_NODE* readObinfoArray;

	ifstream in(mapTemplateFilePath.c_str(), ios::in | ios::binary);
	if (!in) {
		cout << "地图模板文件读取失败！" << endl;
		exit(0);
	}
	//读取图片文件名
	const int LEN = 256;
	char tmpStr[LEN];
	in.getline(tmpStr, LEN);
	readImageFile = tmpStr;

	//读取行列信息
	in.read((char*)&readColumns, sizeof(int));
	in.read((char*)&readRows, sizeof(int));

	if (readColumns != 0 && readRows != 0) {
		readObinfoArray = new OB_NODE[readColumns*readRows];
	}

	//读取不可通行信息列表
	in.read((char*)readObinfoArray, readColumns*readRows * sizeof(OB_NODE));

	in.close();

	cout << "imageFile: " << readImageFile.c_str() << endl;
	cout << "columns" << readColumns << endl;
	cout << "rows" << readRows << endl;

	for (int i = 0; i < 10; i++) {
		cout << readObinfoArray[i].ob_goUp << " ";
		cout << readObinfoArray[i].ob_goDown << " ";
		cout << readObinfoArray[i].ob_goLeft << " ";
		cout << readObinfoArray[i].ob_goRight << endl;
	}

	delete[] readObinfoArray;

	return 0;

}