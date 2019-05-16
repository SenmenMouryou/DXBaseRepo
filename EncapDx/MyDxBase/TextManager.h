/*
文本管理类
*/
#pragma once

#include <list>
#include <d3dx9.h>
#include "Text.h"
#include "FontManager.h"

//预设文本颜色
#define TEXT_WHITE D3DCOLOR_XRGB(255,255,255)
#define TEXT_BLACK D3DCOLOR_XRGB(0,0,0)
#define TEXT_RED D3DCOLOR_XRGB(255,0,0)

class TextManager {
public:
	TextManager(LPDIRECT3DDEVICE9 d3ddev);
	~TextManager();

	/**
	* 增加一条文本
	* @param x{int} 文本的x位置
	* @param y{int} 文本的y位置
	* @param width{int} 文本区域的宽
	* @param height{int} 文本区域的高
	* @param font{LPD3DXFONT} 文本字体
	* @param textColor{D3DCOLOR} 文本颜色
	* @param textString{string} 文本内容
	* @return 增加的文本对象指针 
	*/
	Text* AddText(int x, int y, int width, int height, 
				  LPD3DXFONT font, D3DCOLOR textColor,
				  string textString);

	/**
	* 删除一条文本
	* @param text{Text*} 需要删除的文本对象
	*/
	void DelText(Text* text);

	/**
	渲染文本列表
	*/
	void RendTextList();

	/*getter & setter*/
	FontManager* getFontManager();

private:
	list<Text*> textList;
	//字体管理器
	FontManager* fontManager = NULL;

	//字符绘制的精灵对象
	LPD3DXSPRITE spriteobj = NULL;

};

