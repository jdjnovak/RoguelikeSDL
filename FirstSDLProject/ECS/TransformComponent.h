#ifndef _TRANSFORM_COMPONENT_H
#define _TRANSFORM_COMPONENT_H

#include "Components.h"
#include "../Vector2D.h"

class TransformComponent : public Component {
public:

	Vector2D position;
	Vector2D velocity;

	int speed = 3; // Temp for now

	TransformComponent() {
		position.x = 0.0f;
		position.y = 0.0f;
	}

	TransformComponent(float x, float y) {
		position.x = x;
		position.y = y;
	}

	void Init() override {
		velocity.x = 0.0f;
		velocity.y = 0.0f;
	}

	void Update() override {
		position.x += velocity.x * speed;
		position.y += velocity.y * speed;
	}
};

#endif //_TRANSFORM_COMPONENT_H
