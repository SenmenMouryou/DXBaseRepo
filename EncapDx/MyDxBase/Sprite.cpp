#include "Sprite.h"

Sprite::Sprite(LPDIRECT3DDEVICE9 d3ddev) {
	this->d3ddev = d3ddev;	
}

Sprite::~Sprite() {
	if (texture != NULL) {
		texture->Release();
		texture = NULL;
	}
}

void Sprite::initTexture(string imageFile, int columns, int totFrame, D3DCOLOR transcolor) {
	if (!LoadTexture(imageFile.c_str(), transcolor)) {
		MessageBox(0, "错误：精灵材质加载错误","Error",0);
	}
	else {
		this->columns = columns;
		this->totFrame = totFrame;
	}
}

void Sprite::Animate(int startframe, int endframe, int direction, int & starttime, int delay) {
	assert(startframe<0 || endframe > totFrame);

	if ((int)GetTickCount() > starttime + delay) {
		starttime = GetTickCount();
		frame += direction;
		if (frame > endframe) {
			frame = startframe;
		}
		if (frame < startframe) {
			frame = endframe;
		}
	}
}

void Sprite::DrawSprite(LPD3DXSPRITE spriteobj) {
	//缩放向量
	D3DXVECTOR2 scale(scaling, scaling);
	//平移向量
	D3DXVECTOR2 translate(x, y);
	//设置缩放、旋转中心
	D3DXVECTOR2 center((float)(width*scaling) / 2, (float)(height*scaling) / 2);
	//变换矩阵
	D3DXMATRIX mat;
	D3DXMatrixTransformation2D(&mat, NULL, 0, &scale, &center, rotation, &translate);

	//将变换矩阵传递给精灵对象
	spriteobj->SetTransform(&mat);
	//计算绘制帧在源图像的位置
	int fx = (frame % columns) * width;
	int fy = (frame / columns) * height;
	RECT rect = { fx, fy, fx + width, fy + height };

	//绘制精灵
	spriteobj->Draw(texture, &rect, NULL, NULL, transcolor);
}

int Sprite::getX() {
	return x;
}

int Sprite::getY() {
	return y;
}

int Sprite::getWidth() {
	return width;
}

int Sprite::getHeight() {
	return height;
}

float Sprite::getScaling() {
	return scaling;
}

void Sprite::setXY(int x, int y) {
	this->x = x;
	this->y = y;
}

void Sprite::setWH(int width, int height) {
	this->width = width;
	this->height = height;
}

void Sprite::setFrame(int frame) {
	this->frame = frame;
}

void Sprite::setRotation(float rotation) {
	this->rotation = rotation;
}

void Sprite::setScaling(float scaling) {
	this->scaling = scaling;
}

bool Sprite::LoadTexture(string imageFile, D3DCOLOR transcolor) {
	//从位图中获得宽高
	D3DXIMAGE_INFO info;
	HRESULT result = D3DXGetImageInfoFromFile(imageFile.c_str(), &info);
	if (result != D3D_OK) {
		return false;
	}
	//以位图文件创建材质
	result = D3DXCreateTextureFromFileEx(
		d3ddev,
		imageFile.c_str(),
		info.Width,
		info.Height,
		1,
		D3DPOOL_DEFAULT,
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		transcolor,
		&info,
		NULL,
		&texture
	);
	if (result != D3D_OK) {
		return false;
	}
	return true;
}
