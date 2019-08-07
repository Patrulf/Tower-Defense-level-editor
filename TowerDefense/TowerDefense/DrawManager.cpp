#include "stdafx.h"
#include "DrawManager.h"
#include "Renderer.h"
#include "Sprite.h"

DrawManager::DrawManager(Renderer* p_renderer)
{
	_renderer = p_renderer;
}
DrawManager::~DrawManager()
{
}

void DrawManager::Draw() {
	_renderer->DrawBG();
}
void DrawManager::Present()
{
	_renderer->Present();
}

void DrawManager::DrawSprite(Sprite* p_sprite)
{
	SDL_RenderCopy(_renderer->GetRenderer(), p_sprite->GetTexture()->GetTexture(),nullptr, &p_sprite->GetRect() );
}