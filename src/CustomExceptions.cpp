//
// Created by Popescu Stefan on May 14, 2023.
//

#include "../headers/CustomExceptions.h"

game_error::game_error(const std::string &arg) : runtime_error("Game error: " + arg) { }

load_error::load_error(const std::string &arg) : game_error("Couldn't load " + arg) { }

rules_error::rules_error(const std::string &arg) : game_error("Game rule violated : " + arg) { }
