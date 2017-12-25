//
// Created by Wadie Assal on 25-12-17.
//

#ifndef ALLANITE_DISPLAY_H
#define ALLANITE_DISPLAY_H

#include <SDL2/SDL.h>

class Render {

private:
    SDL_GLContext glContext;
    SDL_Window *window;

public:
    void createWindow(std::string name, int width, int height);
    void renderWindow();
    void closeWindow();

};

#endif //ALLANITE_DISPLAY_H
