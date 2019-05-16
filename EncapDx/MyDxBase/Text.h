#pragma once

#include <iostream>
#include <d3dx9.h>

using namespace std;

class Text {
public:
	/**
	* ������
	* @param x{int} �ı�xλ��
	* @param y{int} �ı�yλ��
	* @param width{int} �ı������
	* @param height{int} �ı������
	* @param font{LPD3DXFONT} �ı�����
	* @param color{D3DCOLOR} �ı���ɫ
	* @param text{string} �ı��ַ�������
	*/
	Text(int x, int y, int width, int height,
		 LPD3DXFONT font, D3DCOLOR color,
		 string text);
	~Text();

	/*getter & setter*/
	int getX();

	int getY();
	
	int getWidth();
	
	int getHeight();

	string getText();

	LPD3DXFONT getFont();

	D3DCOLOR getColor();

	void setColor(D3DCOLOR color);

private:
	string text;
	int x;
	int y;
	int width;
	int height;

	LPD3DXFONT font;
	D3DCOLOR color;

};

