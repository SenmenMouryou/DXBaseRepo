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
	//���壺����24
	LPD3DXFONT font_Kaiti24;
	//���壺����30
	LPD3DXFONT font_Heiti30;

	/**
	* ��������
	* @param name{string} ��������
	* @param size{int} �����С
	*/
	LPD3DXFONT MakeFont(string name, int size);


};

