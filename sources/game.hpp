#pragma once
#include "player.hpp"
#include "card.hpp"
class Game{

    private:
        // Card deck[52] = {}; 
    public:
        Game(Player, Player);
        // ~Game();
        void playTurn();
        void printLastTurn();    
        void playAll();
        void printWiner(); // *winner
        void printLog();
        void printStats();
        // int printDeckSize();
};

namespace ariel{
//name space funcs will go here if needed
};