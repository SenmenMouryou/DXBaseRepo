/**
* ��ͼ�ļ���
*/
#pragma once

#include <iostream>

using namespace std;

class MapFile {
public:
	MapFile();
	~MapFile();

private:
	//��ͼ��
	int mapWidth;
	//��ͼ��
	int mapHeight;
	//ģ���ļ�
	string templateFile;
	//ͼ������
	int* layerData[3];
};

