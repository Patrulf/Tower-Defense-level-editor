#include "stdafx.h"
#include "Vec2.h"
#include "Math.h"

//todo, make into template. explicit instantiation,
//so only ints, float, doubles.
//also means we can hide includes in cpp.
Vec2::Vec2() :
	x{ 0.0f },
	y{ 0.0f }
{}

Vec2::Vec2(float p_x, float p_y) :
	x{p_x},
	y{p_y}
{}

Vec2::~Vec2()
{
}

Vec2& Vec2::operator= (const Vec2& p_vec) {
	x = p_vec.x;
	y = p_vec.y;
	return *this;
}

Vec2& Vec2::operator+ (const Vec2& p_vec) {
	x = x + p_vec.x;
	y = y + p_vec.y;
	return *this;
}

Vec2& Vec2::operator-(const Vec2& p_vec) {
	x = x - p_vec.x;
	y = y - p_vec.y;
	return *this;
}

Vec2& Vec2::operator*(const Vec2& p_vec) {
	x = x * p_vec.x;
	y = y * p_vec.y;
	return *this;
}

Vec2& Vec2::operator+= (const Vec2& p_vec) {
	x += p_vec.x;
	y += p_vec.y;
	return *this;
}

Vec2& Vec2::operator*= (const Vec2& p_vec) {
	x *= p_vec.x;
	y *= p_vec.y;
	return *this;
}

Vec2& Vec2::operator-= (const Vec2& p_vec) {
	x -= p_vec.x;
	y -= p_vec.y;
	return *this;
}

float Vec2::Dot(const Vec2& p_vec1,const Vec2& p_vec2) {
	return (p_vec1.x * p_vec2.x) + (p_vec1.y * p_vec2.y);
}

float Vec2::Length() {
	return sqrtf((x*x + y*y));
}

Vec2 Vec2::Normalize() {
	if (x != 0 && y != 0) {
		x = 1.0f / Length();
		y = 1.0f / Length();
	}
	return *this;
}

Vec2 Vec2::DistanceTo(const Vec2& p_vec1, const Vec2& p_vec2) {
	Vec2 dist;
	dist.x = sqrtf(p_vec1.x*p_vec1.x - p_vec2.x*p_vec2.x);
	dist.y = sqrtf(p_vec1.y*p_vec1.y - p_vec2.y*p_vec2.y);
	return dist;
}