//
//  Game.cpp
//  MinesweeperIP
//
//  Created by Bogdan on 1/8/17.
//  Copyright © 2017 Bogdan Raducan. All rights reserved.
//

#include "Game.hpp"

#include <iostream>

using namespace std;

Game::Game(Board board)
{
    this->board = board;
}

void printMenu(Menu menu)
{
    cout << menu.displayString();
    cout << "\n";
}

void Game::startGame()
{
    printMenu(this->menu);
}
