#include "TextManager.h"

TextManager::TextManager(LPDIRECT3DDEVICE9 d3ddev) {
	fontManager = new FontManager(d3ddev);
	D3DXCreateSprite(d3ddev, &spriteobj);
}

TextManager::~TextManager() {
	delete fontManager;
	if (!textList.empty()) {
		list<Text*>::iterator iter;
		for (iter = textList.begin(); iter != textList.end(); iter++) {
			delete *iter;
		}
	}
	if (spriteobj) {
		spriteobj->Release();
	}
}

Text* TextManager::AddText(int x, int y, int width, int height,
						   LPD3DXFONT font, D3DCOLOR textColor,
						   string textString) {
	Text* text = new Text(x, y, width, height, font, textColor, textString);
	this->textList.push_back(text);

	return text;
}

void TextManager::DelText(Text * text) {
	textList.remove(text);

	delete text;
}

void TextManager::RendTextList() {
	//精灵对象开始渲染
	spriteobj->Begin(D3DXSPRITE_ALPHABLEND);

	list<Text*>::iterator iter;

	for (iter = textList.begin(); iter != textList.end(); iter++) {
		Text* text = *iter;
		RECT rect = { 
			text->getX(),
			text->getY(),
			text->getX() + text->getWidth(),
			text->getY() + text->getHeight()
		};
		text->getFont()->DrawText(spriteobj, text->getText().c_str(),
								  text->getText().length(), &rect,
								  DT_WORDBREAK, text->getColor());
	}

	//精灵对象停止渲染
	spriteobj->End();
}

FontManager * TextManager::getFontManager() {
	return fontManager;
}
