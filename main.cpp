#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include <thread>

#ifdef __linux__
#include <X11/Xlib.h>
#endif

#include "headers/GameConsts.h"
#include "headers/Board.h"
#include "headers/Game.h"
#include "headers/Piece.h"
#include <memory>

int main() {
    #ifdef __linux__
    XInitThreads();
    #endif


    Game joc;
    joc.runGame();

    return 0;
}
