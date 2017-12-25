/* 
 * Author:    Wadie Assal: 
 * Project:   Allanite: A ᵗᶦⁿʸ game engine
 * 
 */

#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

#include <memory>
#include <string>

#include "Render.h"

const std::string ENGINE_NAME = "Allanite";
const int WIDTH = 800;
const int HEIGHT = 600;

std::shared_ptr<Render> render;

int main(int argc, char *argv[]) {
    SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "Starting Allanite");

    // Initialize SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to initialize SDL: %s", SDL_GetError());
        exit(1);
    }

    // Initialize renderer and create window
    render = std::make_shared<Render>();
    render->createWindow(ENGINE_NAME.c_str(), WIDTH, HEIGHT);

    // Initialize timer
    unsigned int lastTime = 0, currentTime;

    SDL_Event event;
    bool running = true;

    // Main render loop
    while (running) {

        // Handle SDL events
        while( SDL_PollEvent(&event) ) {
            if(event.type == SDL_QUIT) {
                running = false;
            }
        }

        // Run at 50 FPS
        currentTime = SDL_GetTicks();
        if (currentTime > lastTime + 20) {
            render->renderWindow();
            lastTime = currentTime;
        }

        // If less then one millisecond has passed, delay by one millisecond
        currentTime = SDL_GetTicks();
        if (currentTime > lastTime + 1) {
            SDL_Delay(1);
        }
    }

    // Cleanup and exit
    render->closeWindow();
    SDL_Quit();
    exit(0);
}