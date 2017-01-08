//
//  Menu.cpp
//  MinesweeperIP
//
//  Created by Bogdan on 1/8/17.
//  Copyright © 2017 Bogdan Raducan. All rights reserved.
//

#include "Menu.hpp"

#include <map>
#include <string>

using namespace std;

typedef map<MenuOption, string> MenuValuesMap;

struct MenuValues {
    static MenuValuesMap create_map()
    {
        MenuValuesMap values;
        values[PrintMap] = "Printează harta";
        values[OpenTile] = "Selectează poziție";
        values[FlagTile] = "Marchează poziție";
        values[NewGame] = "Joc nou";
        return values;
    }
    static const MenuValuesMap menuValuesMap;
};

const MenuValuesMap MenuValues::menuValuesMap = MenuValues::create_map();

string Menu::displayString()
{
    string displayString;

    for (auto &menuValue : MenuValues::menuValuesMap) {
        displayString.append(to_string(menuValue.first));
        displayString.append(". ");
        displayString.append(menuValue.second);
        displayString.append(".\n");
    }

    return displayString;
}
