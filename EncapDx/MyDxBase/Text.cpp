#include "Text.h"

Text::Text(int x, int y, int width, int height,
		   LPD3DXFONT font, D3DCOLOR color,
		   string text) {
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->font = font;
	this->color = color;
	this->text = text;
}

Text::~Text() {
}

int Text::getX() {
	return x;
}

int Text::getY() {
	return y;
}

int Text::getWidth() {
	return width;
}

int Text::getHeight() {
	return height;
}

string Text::getText() {
	return text;
}

LPD3DXFONT Text::getFont() {
	return font;
}

D3DCOLOR Text::getColor() {
	return color;
}

void Text::setColor(D3DCOLOR color) {
	this->color = color;
}
