//
// Created by Popescu Stefan on May 14, 2023.
//

#ifndef OOP_CUSTOMEXCEPTIONS_H
#define OOP_CUSTOMEXCEPTIONS_H

#include "GameConsts.h"
#include <stdexcept>
#include "CustomExceptions.h"


class game_error : public std::runtime_error{
public:
    game_error(const std::string & arg);
};

class load_error : public game_error{
public:
    load_error(const std::string & arg);
};

class rules_error : public game_error{
public:
    rules_error(const std::string & arg);
};



#endif //OOP_CUSTOMEXCEPTIONS_H
