#ifndef _COLLISION_H
#define _COLLISION_H

#include "SDL.h"

class Collision {
public:
	static bool AABB(const SDL_Rect& recA, const SDL_Rect& recB);
};

#endif //_COLLISION_H