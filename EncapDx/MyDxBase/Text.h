#pragma once

#include <iostream>
#include <d3dx9.h>

using namespace std;

class Text {
public:
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

