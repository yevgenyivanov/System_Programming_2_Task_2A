#pragma once
#include <string>


class Card{
    int value;
    std::string type;

    public:
        Card(int, std::string);
        void getCard();
};