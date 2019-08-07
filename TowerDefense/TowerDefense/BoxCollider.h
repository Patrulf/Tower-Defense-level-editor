#pragma once

struct Box {
	float x;
	float y;
	float w;
	float h;
	Box(float p_x, float p_y, float p_w, float p_h) :
		x(p_x),
		y(p_y),
		w(p_w),
		h(p_h) {};
};

class BoxCollider
{
public:
	BoxCollider(Box p_collider);
	BoxCollider(float p_x, float p_y, float p_w, float p_h);
	~BoxCollider();

	Box& GetCollider();
	float GetLeft();
	float GetRight();
	float GetTop();
	float GetBottom();

	void UpdateCollider(Box p_collider);
	void UpdateCollider(float p_x, float p_y, float p_w, float p_h);

private:
	Box collider;
};

