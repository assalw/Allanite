//
// Created by Wadie Assal on 25-12-17.
//

#ifndef ALLANITE_ALLANITE_H
#define ALLANITE_ALLANITE_H

#include <string>

#include "Render.h"

class Allanite
{

private:
    std::string engineName;

    int width;
    int height;

    bool gameInitialized;
    bool gameRunning;

    std::shared_ptr<Render> render;

public:
    Allanite(std::string engineName, int width, int height);

    void initGame();

    void startGameLoop();

    void stopGameLoop();

    void closeGame();

    ~Allanite();
};

#endif //ALLANITE_ALLANITE_H
