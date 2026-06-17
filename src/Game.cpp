#include "Game.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

 //scopeResolution::Method()
Game::Game() 
{
	std::cout << "Game Constructor Called" << std::endl;
}

Game::~Game()
{
	std::cout << "Game Destroyer Called" << std::endl;
}

void Game::Initialize()
{
	// Call SDLLib
	if (SDL_Init(SDL_INIT_EVERYTHING != 0) //requires graphical output
	{
		std::cerr << "Error: Init SDL." << std::endl;
		return;
	}


}	

void Game::Run()
{
	//
}	

void Game::processInput()
{
	//
}	


void Game::Render()
{
	//
}	

void Game::Destroy()
{
	//
}	