#ifndef _TILE_COMPONENT_H
#define _TILE_COMPONENT_H

#include "ECS.h"
#include "TransformComponent.h"
#include "SDL.h"

class TileComponent : public Component {
public:
	TransformComponent* transform;
	SpriteComponent* sprite;

	SDL_Rect tileRect;
	int tileID;
	const char* path;

	TileComponent() = default;

	TileComponent(int x, int y, int w, int h, int id) {
		tileRect.x = x;
		tileRect.y = y;
		tileRect.w = w;
		tileRect.h = h;
		tileID = id;

		switch (tileID) {
		case 0:
			path = "assets/dirt.png";
			break;
		case 1:
			path = "assets/grass.png";
			break;
		case 2:
			path = "assets/water.png";
			break;
		default:
			break;
		}
	}

	void Init() override {
		entity->AddComponent<TransformComponent>((float)tileRect.x, (float)tileRect.y, (float)tileRect.w, (float)tileRect.h, 1);
		transform = &entity->GetComponent<TransformComponent>();

		entity->AddComponent<SpriteComponent>(path);
		sprite = &entity->GetComponent<SpriteComponent>();
	}
};

#endif //_TILE_COMPONENT_H