/*������,ʵ��Ϊ����ľ�������ṩλ�á����ʵ�*/
#pragma once

#include <d3d9.h>
#include <d3dx9.h>
#include <assert.h>
#include <iostream>

using namespace std;

//Ĭ��͸����
const D3DCOLOR DEFAULT_TRANSCOLOR = D3DCOLOR_XRGB(255, 255, 255);

class Sprite {
public:

	/**ʹ�ò��ʵĹ�����
	*param: d3d�豸�� ͼ���ļ����� ͼ������, ��ʼ����֡, ͸��ɫ
	*/
	Sprite(LPDIRECT3DDEVICE9 d3ddev);
	~Sprite();

	/**
	��ʼ���������
	param: ͼ���ļ�, ͼ������, ͼ����֡��, ͼ��͸����
	*/
	void initTexture(string imageFile, int columns = 1, int totFrame = 1,
					  D3DCOLOR transcolor = DEFAULT_TRANSCOLOR);

	/**
	���鶯��
	param:
	*/
	void Animate(int startframe, int endframe, int direction,
				 int &starttime, int delay);

	/**
	���Ƶ�ǰ�任�ľ������ͼ��
	param: �������
	*/
	void DrawSprite(LPD3DXSPRITE spriteobj);

	/**setter&getter*/
	int getX();

	int getY();

	int getWidth();

	int getHeight();

	float getScaling();

	void setXY(int x, int y);

	void setWH(int width, int height);

	void setFrame(int frame);

	void setRotation(float rotation);

	void setScaling(float scaling);

private:
	//d3d�豸
	LPDIRECT3DDEVICE9 d3ddev = NULL;
	//λ��
	int x = 0;
	int y = 0;
	//��С
	int width = 0;
	int height = 0;
	//�任����ת
	float rotation = 0.0f;
	//�任������
	float scaling = 1.0f;
	//ͼ������
	int columns;
	//�ܶ���֡��
	int totFrame = 1;
	//��ǰ����֡
	int frame = 0;
	//����ָ��
	LPDIRECT3DTEXTURE9 texture = NULL;
	//͸��ɫ
	D3DCOLOR transcolor = DEFAULT_TRANSCOLOR;

	/**
	����ͼƬ������
	param: ͼ���ļ���, ͸��ɫ
	*/
	bool LoadTexture(string imageFile, D3DCOLOR transcolor = DEFAULT_TRANSCOLOR);

};

