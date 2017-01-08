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
    PrintMap = 1,
    OpenTile = 2,
    FlagTile = 3,
    NewGame = 4
};

class Menu {
public:
    string displayString();
};

#endif /* Menu_hpp */
