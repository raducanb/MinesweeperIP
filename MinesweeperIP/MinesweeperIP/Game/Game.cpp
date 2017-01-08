//
//  Game.cpp
//  MinesweeperIP
//
//  Created by Bogdan on 1/8/17.
//  Copyright © 2017 Bogdan Raducan. All rights reserved.
//

#include "Game.hpp"

#include <iostream>
#include <sstream>

using namespace std;

void printMenu(Menu menu)
{
    cout << menu.displayString();
    cout << "\n";
}

int inputNumber(string stringToShow, bool(*verificationFunction)(int))
{
    int inputOption = 0;
    string inputString;
    bool didTryOnce;

    while (true) {
        cout << stringToShow << (didTryOnce ? " validă" : "") << ": ";
        cin >> inputString;

        stringstream stream(inputString);
        if (stream >> inputOption && verificationFunction(inputOption)) { break; }
        didTryOnce = true;
    }

    return inputOption;
}

MenuOption inputMenuOptionForMenu(Menu menu)
{
    int input = inputNumber("Introdu o opțiune din meniu", menu.isOptionValid);

    return (MenuOption)input;
}

    while(true) {
        input = inputNumber(didTryOnce);

        if (menu.isOptionValid(input)) { break; }
        didTryOnce = true;
    }

    return (MenuOption)input;
}



void Game::userSelectedOption(MenuOption option)
{
    switch (option) {
        case MenuOptionNewGame:

            break;
        case MenuOptionOpenTile:

            break;

        case MenuOptionFlagTile:

            break;
        case MenuOptionPrintMap:
            this->board->printMap(false);
            break;
    }
}

void Game::startGame()
{
    this->board = new Board();
    printMenu(this->menu);
    MenuOption option = inputMenuOptionForMenu(this->menu);
    userSelectedOption(option);
}
