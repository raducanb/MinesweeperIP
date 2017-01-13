//
//  MainMenu.hpp
//  MinesweeperIP
//
//  Created by Bogdan on 1/13/17.
//  Copyright © 2017 Bogdan Raducan. All rights reserved.
//

#ifndef MainMenu_hpp
#define MainMenu_hpp

#include <stdio.h>

#include <string>

using namespace std;

enum MenuOption {
    MenuOptionStartCustomGame = 1,
    MenuOptionStartEasyGame,
    MenuOptionStartMediumGame,
    MenuOptionStartHardGame,
    MenuOptionQuit
};

class MainMenu {
public:
    string displayString();
    static bool isOptionValid(int option);
};
#endif /* MainMenu_hpp */
