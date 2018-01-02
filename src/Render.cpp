//
// Created by Wadie Assal on 25-12-17.
//

#include <GL/glew.h>
#include <string>
#include <stdexcept>

#include "../include/Render.h"


Render::Render() : windowOpened()
{}

void Render::createWindow(std::string name, int width, int height)
{
    if (!windowOpened) {
        SDL_LogInfo(SDL_LOG_CATEGORY_RENDER, "Creating Render window");

        // OpenGL version 4
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

        window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height,
                                  SDL_WINDOW_OPENGL);
        glContext = SDL_GL_CreateContext(window);

        glewInit();
        glViewport(0, 0, width, height);

        // Print OpenGL version
        SDL_LogInfo(SDL_LOG_CATEGORY_RENDER, "%s: %s", "OpenGL Version:", glGetString(GL_VERSION));

        windowOpened = true;
    }
    else
    {
        SDL_LogInfo(SDL_LOG_CATEGORY_RENDER, "Can not open Render window in %s. Window already created.", name.c_str());
    }
}

void Render::renderWindow()
{
    if (windowOpened)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(1.0, 1.0, 1.0, 1.0);

        SDL_GL_SwapWindow(window);
    }
    else
    {
        throw std::runtime_error("Unable to render to window. Window not available.");
    }

}

void Render::closeWindow()
{
    if (windowOpened)
    {
        SDL_GL_DeleteContext(glContext);
        SDL_DestroyWindow(window);

        windowOpened = false;
    }
}

Render::~Render()
{
    closeWindow();
}

