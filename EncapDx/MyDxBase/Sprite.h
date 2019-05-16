/*精灵类,实例为虚拟的精灵对象，提供位置、材质等*/
#pragma once

#include <d3d9.h>
#include <d3dx9.h>
#include <assert.h>
#include <iostream>

using namespace std;

//默认透明度
const D3DCOLOR DEFAULT_TRANSCOLOR = D3DCOLOR_XRGB(255, 255, 255);

class Sprite {
public:

	/**使用材质的构造器
	*param: d3d设备， 图像文件名， 图像列数, 起始动画帧, 透明色
	*/
	Sprite(LPDIRECT3DDEVICE9 d3ddev);
	~Sprite();

	/**
	初始化精灵材质
	param: 图像文件, 图像列数, 图像总帧数, 图像透明度
	*/
	void initTexture(string imageFile, int columns = 1, int totFrame = 1,
					  D3DCOLOR transcolor = DEFAULT_TRANSCOLOR);

	/**
	精灵动画
	param:
	*/
	void Animate(int startframe, int endframe, int direction,
				 int &starttime, int delay);

	/**
	绘制当前变换的精灵材质图像
	param: 精灵对象
	*/
	void DrawSprite(LPD3DXSPRITE spriteobj);

	/**setter&getter*/
	int getX();

	int getY();

	int getWidth();

	int getHeight();

	float getScaling();

	void setXY(int x, int y);

	void setWH(int width, int height);

	void setFrame(int frame);

	void setRotation(float rotation);

	void setScaling(float scaling);

private:
	//d3d设备
	LPDIRECT3DDEVICE9 d3ddev = NULL;
	//位置
	int x = 0;
	int y = 0;
	//大小
	int width = 0;
	int height = 0;
	//变换：旋转
	float rotation = 0.0f;
	//变换：缩放
	float scaling = 1.0f;
	//图像列数
	int columns;
	//总动画帧数
	int totFrame = 1;
	//当前动画帧
	int frame = 0;
	//材质指针
	LPDIRECT3DTEXTURE9 texture = NULL;
	//透明色
	D3DCOLOR transcolor = DEFAULT_TRANSCOLOR;

	/**
	加载图片到材质
	param: 图像文件名, 透明色
	*/
	bool LoadTexture(string imageFile, D3DCOLOR transcolor = DEFAULT_TRANSCOLOR);

};

