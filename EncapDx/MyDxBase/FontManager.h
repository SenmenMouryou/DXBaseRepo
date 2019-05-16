#pragma once

#include <iostream>
#include <sstream>
#include <d3d9.h>
#include <d3dx9.h>

using namespace std;

class FontManager {
public:
	FontManager(LPDIRECT3DDEVICE9 d3ddev);
	~FontManager();

	/*getter & setter*/
	LPD3DXFONT getFont_Kaiti24();
	LPD3DXFONT getFont_Heiti30();

private:
	LPDIRECT3DDEVICE9 d3ddev = NULL;
	//字体：楷体24
	LPD3DXFONT font_Kaiti24;
	//字体：黑体30
	LPD3DXFONT font_Heiti30;

	/**
	* 创建字体
	* @param name{string} 字体名称
	* @param size{int} 字体大小
	*/
	LPD3DXFONT MakeFont(string name, int size);


};

