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
		MessageBox(0, "��ͼд��ʧ�ܣ�", "����", 0);
		return false;
	}
	//д��ͼƬ�ļ���
	out << imageFile.c_str() << endl;
	//д��������Ϣ
	out.write((char*)&columns, sizeof(int));
	out.write((char*)&rows, sizeof(int));
	//д�벻��ͨ����Ϣ����
	out.write((char*)obinfoArray, columns*rows*sizeof(OB_NODE));
	
	out.close();

	string message = "��ͼ�ļ���";
	message += mapFilename;
	message += " д�����";
	MessageBox(0, message.c_str(), "֪ͨ", 0);

	return true;
}

bool MapTemplateFile::readFromFile(string mapFilename) {
	ifstream in(mapFilename.c_str(), ios::in | ios::binary);
	if (!in) {
		MessageBox(0, "��ͼģ���ļ���ʧ��", "����", 0);
		return false;
	}
	//��ȡͼƬ�ļ���
	const int LEN = 256;
	char tmpStr[LEN];
	in.getline(tmpStr, LEN);
	imageFile = tmpStr;
	//��ȡ������Ϣ
	in.read((char*)&columns, sizeof(int));
	in.read((char*)&rows, sizeof(int));
	//��ȡ����ͨ����Ϣ����
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
