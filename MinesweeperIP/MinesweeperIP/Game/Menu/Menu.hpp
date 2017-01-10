//
//  Menu.hpp
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

enum MenuOption {
    MenuOptionPrintMap = 1,
    MenuOptionOpenTile = 2,
    MenuOptionFlagTile = 3,
    MenuOptionNewGame = 4,
    MenuOptionPrintUncoveredMap = 5,
    MenuOptionEndGame
};

class Menu {
public:
    string displayString();
    static bool isOptionValid(int option);
};

#endif /* Menu_hpp */
