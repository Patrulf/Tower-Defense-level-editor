#include "stdafx.h"
#include "Plane.h"

Plane::Plane(Vec2 p_position, int p_width, int p_height) :
	position(p_position),
	width(p_width),
	height(p_height)
{

}


Plane::~Plane()
{
}

Vec2 Plane::GetPosition() {
	return position;
}

int Plane::GetHeight() {
	return height;
}

int Plane::GetWidth() {
	return width;
}

