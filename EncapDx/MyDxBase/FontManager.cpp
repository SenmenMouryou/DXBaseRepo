#include "FontManager.h"

FontManager::FontManager(LPDIRECT3DDEVICE9 d3ddev) {
	this->d3ddev = d3ddev;
	font_Kaiti24 = MakeFont("¿¬Ìå", 24);
	font_Heiti30 = MakeFont("ºÚÌå", 30);
}

FontManager::~FontManager() {
	if (font_Kaiti24) {
		font_Kaiti24->Release();
	}
	if (font_Heiti30) {
		font_Heiti30->Release();
	}
}

LPD3DXFONT FontManager::getFont_Kaiti24() {
	return font_Kaiti24;
}

LPD3DXFONT FontManager::getFont_Heiti30() {
	return font_Heiti30;
}

LPD3DXFONT FontManager::MakeFont(string name, int size) {
	LPD3DXFONT font;
	D3DXFONT_DESC desc = {
		size,	//height
		0,		//width
		0,		//weight
		0,		//miplevels
		false,	//italic
		DEFAULT_CHARSET,
		OUT_TT_PRECIS,
		CLIP_DEFAULT_PRECIS,
		DEFAULT_PITCH,
		""
	};
	strcpy(desc.FaceName, name.c_str());
	D3DXCreateFontIndirect(d3ddev, &desc, &font);

	return font;
}
