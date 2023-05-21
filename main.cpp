#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include <thread>

#ifdef __linux__
#include <X11/Xlib.h>
#endif

#include "headers/Game.h"
#include <memory>

int main() {

#ifdef __linux__
    XInitThreads();
#endif
    Game::getGame().runGame();

    return 0;
}
