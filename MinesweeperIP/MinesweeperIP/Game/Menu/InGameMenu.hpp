//
//  InGameMenu.hpp
//  MinesweeperIP
//
//  Created by Bogdan on 1/8/17.
//  Copyright © 2017 Bogdan Raducan. All rights reserved.
//

#ifndef Menu_hpp
#define Menu_hpp

#include <stdio.h>

#include <string>

using namespace std;

enum InGameMenuOption {
    MenuOptionPrintMap = 1,
    MenuOptionOpenTile,
    MenuOptionFlagTile,
    MenuOptionNewGame,
    MenuOptionPrintUncoveredMap,
    MenuOptionEndGame
};

class InGameMenu {
public:
    string displayString();
    static bool isOptionValid(int option);
};

#endif /* Menu_hpp */
