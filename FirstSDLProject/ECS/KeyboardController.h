#ifndef _KEYBOARD_CONTROLLER_H
#define _KEYBOARD_CONTROLLER_H

#include "../game.h"
#include "ECS.h"
#include "Components.h"

class KeyboardController : public Component {
public:
	TransformComponent* transform;
	
	void Init() override {
		transform = &entity->GetComponent<TransformComponent>();
	}

	void Update() override {
		if (Game::event.type == SDL_KEYDOWN) {

		}
	}
};

#endif //_KEYBOARD_CONTROLLER_H