//
//  Game.hpp
//  MinesweeperIP
//
//  Created by Bogdan on 1/8/17.
//  Copyright © 2017 Bogdan Raducan. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>

#include "Board.hpp"
#include "Menu.hpp"

class Game {
private:
    Board *board;
    Menu menu;
public:
    Game();
    Game(int boardWidth, int boardHeight);
    void startGame();
};

#endif /* Game_hpp */
