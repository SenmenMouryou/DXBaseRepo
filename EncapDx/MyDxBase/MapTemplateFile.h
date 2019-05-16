/**
* ��ͼģ���ļ���
*/
#pragma once

#include <fstream>
#include "MapTemplate.h"

class MapTemplateFile {
public:
	MapTemplateFile();
	~MapTemplateFile();

	/**
	д��Ϊ�ļ�
	param:	mapFilename ��ͼ�ļ���
	return:	д��ɹ����
	*/
	bool wirteToFile(string mapFilename);

	/**
	���ļ���ȡ
	param:	mapFilename ��ͼ�ļ���
	return:	��ȡ�ɹ����
	*/
	bool readFromFile(string mapFilename);

	/*getter & setter*/
	string getImageFile();

	int getColumns();

	int getRows();

	OB_NODE* getObinfoArray();

private:
	//��ͼģ��ͼ��
	string imageFile;
	//��ͼģ������
	int columns;
	//��ͼģ������
	int rows;
	//����ͨ����Ϣ����
	OB_NODE* obinfoArray = NULL;
};

