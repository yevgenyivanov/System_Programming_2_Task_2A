#pragma once
#include <string>
#include "card.hpp"


class Player{

    private:
        std::string name;
        int cardsTaken;
        int stackSize;
    public:
        Player(std::string);
        // ~Player();  
        int stacksize();
        int cardesTaken();
};