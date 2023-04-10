#include "doctest.h"
#include "./sources/game.hpp"
#include "./sources/player.hpp"
#include "./sources/card.hpp"

TEST_CASE("Player Initialization"){
    Player player1("Alice");
    Player player2("Bob");
    // player stack is 0 upon player initialization as well as cards taken before game start
    CHECK(player1.stacksize() == 0);
    CHECK(player2.stacksize() == 0);
    CHECK(player1.cardesTaken() == 0);
    CHECK(player2.cardesTaken() == 0);
}



TEST_CASE("Game Test"){
    //create players and game obj
    Player player1("Alice");
    Player player2("Bob");
    Game testgame(player1, player2);
    // CHECK(testgame.printDeckSize() == 52);//check that the deck size at the start of the game is 52
    // check that each player is dealt 26 cards
    CHECK(player1.stacksize() == 26); 
    CHECK(player2.stacksize() == 26); 
    // check that each player hasn't taken a card yet
    CHECK(player1.cardesTaken() == 0);
    CHECK(player2.cardesTaken() == 0);
    // check prints before any turn is played
    CHECK_THROWS(testgame.printLastTurn()); // check if the previous turn is not printed (because no turn was played)
    CHECK_THROWS(testgame.printLog());//check that the game log is not printed (because no turn was played)

    // check if a turn is played correctly and check prints again
    CHECK_THROWS(testgame.playTurn());
    //check that each player played a card
    CHECK(player1.stacksize() < 26);
    CHECK(player2.stacksize() < 26);
    CHECK_NOTHROW(testgame.printLastTurn());
    CHECK_NOTHROW(testgame.printLog());

    //check that a game is played until the end correctly
    CHECK_NOTHROW(testgame.playAll());
    CHECK(player1.stacksize() == 0);
    CHECK(player2.stacksize() == 0); // both players played all of their cards
    CHECK(player1.cardesTaken() + player2.cardesTaken() == 52); //all 52 cards were played
    CHECK_NOTHROW(testgame.printWiner()); // a winner exists
    //check prints are correct
    CHECK_NOTHROW(testgame.printLog()); // every game turn is printed
    CHECK_NOTHROW(testgame.printStats()); // check that each player has his stats printed correctly
    
    // stacks are empty and each player won 26 cards
    SUBCASE("Draw"){
        bool draw_condition = player1.cardesTaken() == 26 && player1.stacksize() == 0 
                                && player2.cardesTaken() == 26 && player2.stacksize() == 0 ;
        CHECK(draw_condition); 
    }
    SUBCASE("Player 1 won"){
        bool player1_win_condition = player1.cardesTaken() > player2.cardesTaken() 
                                        && player1.stacksize() == 0 && player2.stacksize() == 0;
        CHECK(player1_win_condition == 1);
    }
    SUBCASE("Player 2 won"){ // same as previous case but for player2
        bool player2_win_condition =  player2.cardesTaken() > player1.cardesTaken()
                                        && player1.stacksize() == 0 && player2.stacksize() == 0;
        CHECK(player2_win_condition == 1);
    }


}

TEST_CASE("Solo Game"){
    Player soloPlayer("Player");
    CHECK_THROWS(Game(soloPlayer, soloPlayer)); // game with one player
    
}