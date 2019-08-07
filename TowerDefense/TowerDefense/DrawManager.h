#pragma once

class Renderer;
class Sprite;

class DrawManager
{
public:
	DrawManager(Renderer* p_renderer);
	~DrawManager();
	void Draw();
	void DrawSprite(Sprite* p_sprite);
	void Present();
private:
	Renderer* _renderer;
};

