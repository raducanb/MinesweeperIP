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

Game::Game()
{
    this->board = new Board();
}

Game::Game(int boardWidth, int boardHeight)
{
    this->board = new Board(boardWidth, boardHeight);
}

void printMenu(Menu menu)
{
    cout << menu.displayString();
    cout << "\n";
}

int inputNumber(bool didTryOnce)
{
    int inputOption = 0;
    string inputString;

    while (true) {
        cout << "Introdu un număr" << (didTryOnce ? " valid" : "") << ": ";
        getline(cin, inputString);

        stringstream stream(inputString);
        if (stream >> inputOption) { break; }
        didTryOnce = true;
    }

    return inputOption;
}

MenuOption inputMenuOptionForMenu(Menu menu)
{
    int input;
    bool didTryOnce = false;
    while(true) {
        input = inputNumber(didTryOnce);

        if (menu.isOptionValid(input)) { break; }
        didTryOnce = true;
    }

    return (MenuOption)input;
}
void Game::startGame()
{
    printMenu(this->menu);
}
