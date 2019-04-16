#ifndef _COLLISION_H
#define _COLLISION_H

#include "SDL.h"
#include "ECS/ColliderComponent.h"

class ColliderComponent;

class Collision {
public:
	static bool AABB(const SDL_Rect& recA, const SDL_Rect& recB);
	static bool AABB(const ColliderComponent& colA, const ColliderComponent& colB);
};

#endif //_COLLISION_H