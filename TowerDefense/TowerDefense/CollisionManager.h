#pragma once

#include "BoxCollider.h"
#include "Vec2.h"

class CollisionManager
{
public:
	CollisionManager();
	~CollisionManager();

	static bool Collision(BoxCollider& p_colliderOne, BoxCollider& p_colliderTwo);
	static bool Collision(Vec2& p_point, BoxCollider& p_boxCollider);
};

