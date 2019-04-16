#include "game.h"
#include "TextureManager.h"
#include "Map.h"
#include "ECS\Components.h"
#include "Vector2D.h"
#include "Collision.h"

Map* map;
Manager manager;

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

std::vector<ColliderComponent*> Game::colliders;

auto& player(manager.AddEntity());
auto& wall(manager.AddEntity());

Game::Game() {

}

Game::~Game() {

}

void Game::Init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen) {
	int flags = 0;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		}

		isRunning = true;
	}

	map = new Map();

	Map::LoadMap("assets/p16x16.map", 16, 16);

	player.AddComponent<TransformComponent>(2);
	player.AddComponent<SpriteComponent>("assets/character.png");
	player.AddComponent<KeyboardController>();
	player.AddComponent<ColliderComponent>("player");

	wall.AddComponent<TransformComponent>(300.0f, 300.0f, 300, 20, 1);
	wall.AddComponent<SpriteComponent>("assets/dirt.png");
	wall.AddComponent<ColliderComponent>("wall");
}

void Game::HandleEvents() {
	SDL_PollEvent(&event);

	switch(event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}

void Game::Update() {
	manager.Refresh();
	manager.Update();

	// Temp
	for (auto cc : colliders) {
		Collision::AABB(player.GetComponent<ColliderComponent>(), *cc);
	}
	//std::cout << player.GetComponent<PositionComponent>().X() << ", " << player.GetComponent<PositionComponent>().Y() << std::endl;
}

void Game::Render() {
	SDL_RenderClear(renderer);
	manager.Draw();
	SDL_RenderPresent(renderer);
}

void Game::Clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game cleaned." << std::endl;
}

void Game::AddTile(int id, int x, int y) {
	auto& tile(manager.AddEntity());
	tile.AddComponent<TileComponent>(x, y, 32, 32, id);
}