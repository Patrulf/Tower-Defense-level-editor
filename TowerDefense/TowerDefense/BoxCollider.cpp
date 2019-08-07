#include "stdafx.h"
#include "BoxCollider.h"


BoxCollider::BoxCollider(Box p_collider) : 
	collider{p_collider}
{

}

BoxCollider::BoxCollider(float p_x, float p_y, float p_w, float p_h) :
	collider{p_x,p_y,p_w,p_h}
{

}

BoxCollider::~BoxCollider()
{
}

void BoxCollider::UpdateCollider(float p_x, float p_y, float p_w, float p_h) {
	collider.x = p_x;
	collider.y = p_y;
	collider.w = p_w;
	collider.h = p_h;
}

void BoxCollider::UpdateCollider(Box p_collider) {
	collider.x = p_collider.x;
	collider.y = p_collider.y;
	collider.w = p_collider.w;
	collider.h = p_collider.h;
}

Box& BoxCollider::GetCollider() {
	return collider;
}

float BoxCollider::GetLeft() {
	return collider.x - (collider.w * 0.5f);
}

float BoxCollider::GetRight() {
	return collider.x + (collider.w * 0.5f);
}

float BoxCollider::GetTop() {
	return collider.y - (collider.h * 0.5f);
}

float BoxCollider::GetBottom() {
	return collider.y + (collider.h * 0.5f);
}