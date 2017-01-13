//
//  MainMenu.cpp
//  MinesweeperIP
//
//  Created by Bogdan on 1/13/17.
//  Copyright © 2017 Bogdan Raducan. All rights reserved.
//

#include "MainMenu.hpp"

#include <map>
#include <string>

using namespace std;

typedef map<MenuOption, string> MenuValuesMap;

struct MenuValues {
    static MenuValuesMap create_map()
    {
        MenuValuesMap values;
        values[MenuOptionStartCustomGame] = "Joc nou personalizat";
        values[MenuOptionStartEasyGame] = "Joc nou usor";
        values[MenuOptionStartMediumGame] = "Joc nou mediu";
        values[MenuOptionStartHardGame] = "Joc nou greu";
        values[MenuOptionQuit] = "Inchide";
        return values;
    }
    static const MenuValuesMap menuValuesMap;
};

const MenuValuesMap MenuValues::menuValuesMap = MenuValues::create_map();

string MainMenu::displayString()
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

bool MainMenu::isOptionValid(int option)
{
    MenuValuesMap valuesMap = MenuValues::menuValuesMap;
    return valuesMap.find((MenuOption)option) != valuesMap.end();
}
