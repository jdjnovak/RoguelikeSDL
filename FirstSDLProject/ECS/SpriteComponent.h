#ifndef _SPRITE_COMPONENT_H
#define _SPRITE_COMPONENT_H

#include "SDL.h"
#include "Components.h"

class SpriteComponent : public Component {
private:
	TransformComponent *transform;
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

		transform = &entity->GetComponent<TransformComponent>();

		srcRect.x = srcRect.y = 0;
		srcRect.w = srcRect.h = 32;
		destRect.w = destRect.h = 64;
	}

	void Update() override {
		destRect.x = (int)transform->position.x;
		destRect.y = (int)transform->position.y;
	}

	void Draw() override {
		TextureManager::Draw(texture, srcRect, destRect);
	}

	void SetTexture(const char *filename) {
		texture = TextureManager::LoadTexture(filename);
	}
};

#endif //_SPRITE_COMPONENT_H