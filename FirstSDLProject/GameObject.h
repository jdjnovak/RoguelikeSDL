#ifndef _GAME_OBJECT_H
#define _GAME_OBJECT_H

#include "game.h"

class GameObject {
public:
	GameObject(const char* textureSheet, int x, int y);
	~GameObject() {};

	void Update();
	void Render();

private:
	int xpos;
	int ypos;
	SDL_Texture* objectTexture;
	SDL_Rect srcRect, destRect;
};

#endif //_GAME_OBJECT_H