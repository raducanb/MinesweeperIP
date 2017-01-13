//
//  Game.hpp
//  MinesweeperIP
//
//  Created by Bogdan on 1/8/17.
//  Copyright © 2017 Bogdan Raducan. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include "../Board/Board.hpp"
#include "Menu/InGameMenu.hpp"

class Game {
private:
    Board *board;
    InGameMenu menu;
    void userSelectedOption(InGameMenuOption option);
    bool flagTile();
    bool openTile();
    void printMapAndForceUncover(bool forceUncover = false);
    Position inputPosition();
    void gameLoop();
    InGameMenuOption optionFromMenu();
    void startGameWithSameConfiguration();
public:
    Game(Board *board = new Board());
    void startGame();
};

#endif /* Game_hpp */
