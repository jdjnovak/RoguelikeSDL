#ifndef _SPRITE_COMPONENT_H
#define _SPRITE_COMPONENT_H

#include "SDL.h"
#include "Components.h"
#include "../TextureManager.h"

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

	~SpriteComponent() {
		SDL_DestroyTexture(texture);
	}

	void Init() override {

		transform = &entity->GetComponent<TransformComponent>();

		srcRect.x = srcRect.y = 0;
		srcRect.w = transform->width;
		srcRect.h = transform->height;
	}

	void Update() override {
		destRect.x = static_cast<int>(transform->position.x);
		destRect.y = static_cast<int>(transform->position.y);
		destRect.w = transform->width * transform->scale;
		destRect.h = transform->height * transform->scale;
	}

	void Draw() override {
		TextureManager::Draw(texture, srcRect, destRect);
	}

	void SetTexture(const char *filename) {
		texture = TextureManager::LoadTexture(filename);
	}
};

#endif //_SPRITE_COMPONENT_H