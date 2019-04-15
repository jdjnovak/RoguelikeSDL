#ifndef _TEXTURE_MANAGER_H
#define _TEXTURE_MANAGER_H

#include "game.h"

class TextureManager {
public:
	static SDL_Texture* LoadTexture(const char* filename);
	static void Draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dst);
};

#endif //_TEXTURE_MANAGER_H