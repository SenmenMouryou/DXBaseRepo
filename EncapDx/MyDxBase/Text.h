#pragma once

#include <iostream>
#include <d3dx9.h>

using namespace std;

class Text {
public:
	/**
	* 构造器
	* @param x{int} 文本x位置
	* @param y{int} 文本y位置
	* @param width{int} 文本区域宽
	* @param height{int} 文本区域高
	* @param font{LPD3DXFONT} 文本字体
	* @param color{D3DCOLOR} 文本颜色
	* @param text{string} 文本字符串内容
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

