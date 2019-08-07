#pragma once
#include "Vec2.h"

class Plane
{
public:
	Plane(Vec2 p_position, int p_width, int p_height);
	~Plane();
	Vec2 GetPosition();
	int GetWidth();
	int GetHeight();
private:
	Vec2 position;
	int width;
	int height;
};

