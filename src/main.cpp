/* 
 * Author:    Wadie Assal: 
 * Project:   Allanite: A ᵗᶦⁿʸ game engine
 * 
 */

#include <string>
#include <memory>

#include "../include/Allanite.h"

const std::string ENGINE_NAME = "Allanite";
const int WIDTH = 1024;
const int HEIGHT = 600;

std::shared_ptr<Allanite> allanite;

int main(int argc, char *argv[])
{

    allanite = std::make_shared<Allanite>(ENGINE_NAME, WIDTH, HEIGHT);
    allanite->initGame();
    allanite->startGameLoop();

    allanite = nullptr;

    exit(0);
}