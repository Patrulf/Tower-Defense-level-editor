#pragma once
struct Vec2
{
public:
	Vec2();
	Vec2(float p_x, float p_y);
	~Vec2();

	float Length();
	static Vec2 DistanceTo(const Vec2& p_vec1,const Vec2& p_ve2);
	Vec2 Normalize();
	
	static float Dot(const Vec2& p_vec1,const Vec2& p_vec2);

	Vec2& operator= (const Vec2& p_vec);

	Vec2& operator+(const Vec2& p_vec);
	Vec2& operator-(const Vec2& p_vec);
	Vec2& operator*(const Vec2& p_vec);

	Vec2& operator+=(const Vec2& p_vec);
	Vec2& operator-=(const Vec2& p_vec);
	Vec2& operator*=(const Vec2& p_vec);

	float x;
	float y;
};

