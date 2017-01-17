//
//  InGameMenu.cpp
//  MinesweeperIP
//
//  Created by Bogdan on 1/8/17.
//  Copyright © 2017 Bogdan Raducan. All rights reserved.
//

#include "InGameMenu.hpp"

#include <map>
#include <string>

using namespace std;

typedef map<InGameMenuOption, string> MenuValuesMap;

struct InGameMenuValues {
    static MenuValuesMap create_map()
    {
        MenuValuesMap values;
        values[MenuOptionPrintMap] = "Printează harta";
        values[MenuOptionOpenTile] = "Selectează poziție";
        values[MenuOptionFlagTile] = "Marchează poziție";
        values[MenuOptionNewGame] = "Întrerupe joc și pornește unul nou";
        values[MenuOptionPrintUncoveredMap] = "Printează harta descoperită";
        values[MenuOptionEndGame] = "Incheie jocul";
        return values;
    }
    static const MenuValuesMap menuValuesMap;
};

const MenuValuesMap InGameMenuValues::menuValuesMap = InGameMenuValues::create_map();

string InGameMenu::displayString()
{
    string displayString;

    for (auto &menuValue : InGameMenuValues::menuValuesMap) {
        displayString.append(to_string(menuValue.first));
        displayString.append(". ");
        displayString.append(menuValue.second);
        displayString.append(".\n");
    }
    displayString.append("\n");

    return displayString;
}

bool InGameMenu::isOptionValid(int option)
{
    MenuValuesMap valuesMap = InGameMenuValues::menuValuesMap;
    return valuesMap.find((InGameMenuOption)option) != valuesMap.end();
}
