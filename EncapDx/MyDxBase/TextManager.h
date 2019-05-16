/*
�ı�������
*/
#pragma once

#include <list>
#include <d3dx9.h>
#include "Text.h"
#include "FontManager.h"

//Ԥ���ı���ɫ
#define TEXT_WHITE D3DCOLOR_XRGB(255,255,255)
#define TEXT_BLACK D3DCOLOR_XRGB(0,0,0)
#define TEXT_RED D3DCOLOR_XRGB(255,0,0)

class TextManager {
public:
	TextManager(LPDIRECT3DDEVICE9 d3ddev);
	~TextManager();

	/**
	* ����һ���ı�
	* @param x{int} �ı���xλ��
	* @param y{int} �ı���yλ��
	* @param width{int} �ı�����Ŀ�
	* @param height{int} �ı�����ĸ�
	* @param font{LPD3DXFONT} �ı�����
	* @param textColor{D3DCOLOR} �ı���ɫ
	* @param textString{string} �ı�����
	* @return ���ӵ��ı�����ָ�� 
	*/
	Text* AddText(int x, int y, int width, int height, 
				  LPD3DXFONT font, D3DCOLOR textColor,
				  string textString);

	/**
	* ɾ��һ���ı�
	* @param text{Text*} ��Ҫɾ�����ı�����
	*/
	void DelText(Text* text);

	/**
	��Ⱦ�ı��б�
	*/
	void RendTextList();

	/*getter & setter*/
	FontManager* getFontManager();

private:
	list<Text*> textList;
	//���������
	FontManager* fontManager = NULL;

	//�ַ����Ƶľ������
	LPD3DXSPRITE spriteobj = NULL;

};

