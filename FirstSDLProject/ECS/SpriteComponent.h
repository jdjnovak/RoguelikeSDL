#ifndef _SPRITE_COMPONENT_H
#define _SPRITE_COMPONENT_H

#include "SDL.h"
#include "Components.h"

class SpriteComponent : public Component {
private:
	PositionComponent *position;
	SDL_Texture *texture;
	SDL_Rect srcRect, destRect;

public:
	SpriteComponent() = default;
	SpriteComponent(const char* filename) {
		texture = TextureManager::LoadTexture(filename);
	}

	void Init() override {

		if (!texture)
			SetTexture("assets/character.png"); // Default

		position = &entity->GetComponent<PositionComponent>();

		srcRect.x = srcRect.y = 0;
		srcRect.w = srcRect.h = 32;
		destRect.w = destRect.h = 64;
	}

	void Update() override {
		destRect.x = position->X();
		destRect.y = position->Y();
	}

	void Draw() override {
		TextureManager::Draw(texture, srcRect, destRect);
	}

	void SetTexture(const char *filename) {
		texture = TextureManager::LoadTexture(filename);
	}
};

#endif //_SPRITE_COMPONENT_H