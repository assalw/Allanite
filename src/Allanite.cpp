//
// Created by Wadie Assal on 25-12-17.
//

#include "Allanite.h"

Allanite::Allanite(std::string engineName, int width, int height) : gameRunning(), gameInitialized()
{
    this->engineName = engineName;
    this->width = width;
    this->height = height;
}

void Allanite::initGame()
{
    if (!gameInitialized)
    {
        SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "Starting Allanite");

        // Initialize SDL
        if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        {
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to initialize SDL: %s", SDL_GetError());
            exit(1);
        }

        render = std::make_shared<Render>();        // Initialize renderer

        render->createWindow(engineName.c_str(), width, height);        // Create window

        gameInitialized = true;
    }
    else
    {
        SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "Unable to execute game initialization. Game already initialized.");
    }
}

void Allanite::startGameLoop()
{
    if (gameInitialized && !gameRunning)
    {
        SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "Starting game loop");

        unsigned int lastTime = 0, currentTime;        // Initialize timer

        SDL_Event event;
        gameRunning = true;

        // Main render loop
        while (gameRunning)
        {
            while (SDL_PollEvent(&event))             // Handle SDL events
            {
                if (event.type == SDL_QUIT)
                {
                    gameRunning = false;
                    SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "Stopping game loop");
                }
            }

            currentTime = SDL_GetTicks();             // Run at 50 FPS
            if (currentTime > lastTime + 20)
            {
                render->renderWindow();
                lastTime = currentTime;
            }

            // If less then one millisecond has passed, delay by one millisecond
            currentTime = SDL_GetTicks();
            if (currentTime > lastTime + 1)
            {
                SDL_Delay(1);
            }
        }
    }
    else
    {
        SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "Unable to start game loop. Game loop already started.");
    }
}

void Allanite::stopGameLoop()
{
    if (gameRunning)
    {
        SDL_Event sdlevent;
        sdlevent.type = SDL_QUIT;

        SDL_PushEvent(&sdlevent);         // Raise game close event
    }
    else
    {
        SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "Unable to stop game loop. Game loop not running.");
    }
}

void Allanite::closeGame()
{
    if (gameRunning)
    {
        stopGameLoop();
    }

    if (gameInitialized)
    {
        SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "Stopping Allanite");

        if (render) render = nullptr;
        SDL_Quit();
    }
}

Allanite::~Allanite()
{
    closeGame();
}


