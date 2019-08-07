#include "stdafx.h"
#include "CollisionManager.h"


CollisionManager::CollisionManager()
{
}


CollisionManager::~CollisionManager()
{
}

bool CollisionManager::Collision(BoxCollider& p_colliderOne, BoxCollider& p_colliderTwo) {
	if (p_colliderOne.GetLeft() < p_colliderTwo.GetRight() && p_colliderOne.GetRight() > p_colliderTwo.GetLeft() 
		&& p_colliderOne.GetBottom() > p_colliderTwo.GetTop() && p_colliderOne.GetTop() < p_colliderTwo.GetBottom()) {
		return true;
	}
	return false;
}

bool CollisionManager::Collision(Vec2& p_point, BoxCollider& p_boxCollider) {
	if (p_point.x < p_boxCollider.GetRight() && p_point.x > p_boxCollider.GetLeft()
		&& p_point.y > p_boxCollider.GetTop() && p_point.y < p_boxCollider.GetBottom()) {
		return true;
	}
	return false;
}
