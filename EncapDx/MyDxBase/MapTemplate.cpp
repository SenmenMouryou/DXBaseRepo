#include "MapTemplate.h"

#include "PngJpgResoGetter.h"

MapTemplate::MapTemplate(LPDIRECT3DDEVICE9 d3ddev, 
						 string imageFile,
						 int columns, int rows,
						 OB_NODE* obinfoArray,
						 D3DCOLOR transcolor) {
	//��ȡd3d�豸
	this->d3ddev = d3ddev;
	
	//��ȡͼ��ͼ����Ϣ
	this->columns = columns;
	this->rows = rows;
 	unsigned int imageWidth, imageHeight;
	GetPicWidthHeight(imageFile.c_str(), &imageWidth, &imageHeight);

	tileWidth = imageWidth / columns;
	tileHeight = imageHeight / rows;

	this->transcolor = transcolor;

	this->imageFile = imageFile;

	//����ͼ�����
	LoadTexture();

	//�趨����ͨ������
	this->obinfoArray = new OB_NODE[columns*rows];
	for (int i = 0; i < columns*rows; i++) {
		this->obinfoArray[i] = obinfoArray[i];
	}
}

MapTemplate::~MapTemplate() {
	ReleaseTexture();
	if (obinfoArray) {
		delete obinfoArray;
	}
}

void MapTemplate::DrawTile(int x, int y, int tileNum, LPD3DXSPRITE spriteobj) {
	int scrX = tileWidth * (tileNum % columns);
	int scrY = tileHeight * (tileNum / columns);
	RECT srcRect = { scrX, scrY, scrX + tileWidth, scrY + tileHeight };
	D3DXVECTOR3 destPos((float)x, (float)y, 0);

	spriteobj->Draw(texture, &srcRect, NULL, &destPos, transcolor);
}

int MapTemplate::getTileWidth() {
	return tileWidth;
}

int MapTemplate::getTileHeight() {
	return tileHeight;
}

void MapTemplate::LoadTexture() {

	D3DXIMAGE_INFO info;
	HRESULT result = D3DXGetImageInfoFromFile(imageFile.c_str(), &info);
	if (result != D3D_OK) {
		texture = NULL;
	}
	//��λͼ�ļ���������
	result = D3DXCreateTextureFromFileEx(
		d3ddev,
		imageFile.c_str(),
		info.Width,
		info.Height,
		1,
		D3DPOOL_DEFAULT,
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		transcolor,
		&info,
		NULL,
		&texture
	);
	if (result != D3D_OK) {
		texture = NULL;
	}
}

void MapTemplate::ReleaseTexture() {
	if (texture) {
		texture->Release();
	}
}
