#include "Game.h"
#include <iostream>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

 //scopeResolution::Method()
Game::Game()
{
    isRunning = false;
	std::cout << "Game Constructor Called" << std::endl;
}

Game::~Game()
{
	std::cout << "Game Destroyer Called" << std::endl;
}

void Game::Initialize()
{
	// Call SDLLib
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) { //requires graphical output

		std::cerr << "Error: Init SDL." << std::endl;
		return;
	}

    //Create the Window struct and display it___________________________________
    window = SDL_CreateWindow(
                                          "J_Engine",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          800,
                                          900,
                                          SDL_WINDOW_RESIZABLE
                                          );
    if (!window)
    {
        std::cerr << "Error creating SDL Window"<< std::endl;
        return;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if(!renderer)
    {
        std::cerr << "Error Creating SDL Renderer." << std::endl;
        return;
    }

    isRunning = true;

}

void Game::Run()
{
	while(isRunning){
        processInput();
        Update();
        Render();
	}
}


void Game::processInput()
{
	SDL_Event addEvent;
	while (SDL_PollEvent(&addEvent)){
        switch(addEvent.type){
        case SDL_QUIT:
            isRunning = false;
            break;
        case SDL_KEYDOWN:
            if(addEvent.key.keysym.sym == SDLK_ESCAPE){
                isRunning = false;
            }
        }
	}
}

void Game::Update()
{
    //to do
}


void Game::Render()
{
	//Draw on screen
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	//render all game obj

	SDL_RenderPresent(renderer);
}

void Game::Destroy()
{
	//Free up rescources
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
