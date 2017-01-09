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
        values[MenuOptionPrintMap] = "Printează harta";
        values[MenuOptionOpenTile] = "Selectează poziție";
        values[MenuOptionFlagTile] = "Marchează poziție";
        values[MenuOptionNewGame] = "Întrerupe joc și pornește unul nou";
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

bool Menu::isOptionValid(int option)
{
    MenuValuesMap valuesMap = MenuValues::menuValuesMap;
    return valuesMap.find((MenuOption)option) != valuesMap.end();
}
