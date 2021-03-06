#ifndef _GAME_H
#define _GAME_H

#include <iostream>
#include <vector>

#include "SDL.h"
#include "SDL_image.h"

class ColliderComponent;

class Game {
public: 
	Game();
	~Game();

	void Init(const char * title, int xpos, int ypos, int width, int height, bool fullscreen);

	void HandleEvents();
	void Update();
	void Render();
	void Clean();

	bool Running() { return isRunning; }

	static void AddTile(int id, int x, int y);
	static SDL_Renderer *renderer;
	static SDL_Event event;
	static std::vector<ColliderComponent*> colliders;

private:
	int count = 0;
	bool isRunning;
	SDL_Window *window;
};

#endif //_GAME_H