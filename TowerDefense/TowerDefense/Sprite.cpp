#include "stdafx.h"
#include "Sprite.h"


//#include <iostream>

Sprite::Sprite(Texture* p_texture,int p_x, int p_y, int p_w, int p_h) : 
	_rect{p_x,p_y,p_w,p_h}
{
	_texture = p_texture;
}

Sprite::~Sprite()
{
}

/*Sprite::Sprite(Sprite&& p_other) {
	std::cout << "Move constructor called!";
};*/

/*Sprite::Sprite& operator = (Sprite&& p_other) {

}*/

/*Sprite::Sprite(const Sprite& p_other) {
	_texture = new Texture()
}*/


Texture* Sprite::GetTexture() {
	return _texture;
}

SDL_Rect Sprite::GetRect() {
	return _rect;
}

void Sprite::SetRect(SDL_Rect& p_rect) {
	_rect = p_rect;
}
