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

int inputNumber(string stringToShow, function<bool (int)> verificationFunction)
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

static bool verifyNumberMinZero(int number)
{
    return number >= 0;
}

void printDidWinMessage()
{
    cout << "\nAi castigat!\n";
}

void printDidLoseMessage()
{
    cout << "\nAi pierdut.\n";
}

Game::Game(Board *board) : board(board) { }

Position Game::inputPosition()
{
    Position p;
    do {
        p.x = inputNumber("Introdu x", verifyNumberMinZero);
    } while (p.x >= this->board->width);
    do {
        p.y = inputNumber("Introdu y", verifyNumberMinZero);
    } while (p.y >= this->board->height);
    return p;
}

void Game::flagTile()
{
    Position p = inputPosition();
    if (this->board->canToggleFlagForTileAtPosition(p)) {
        this->board->toggleFlagForTileAtPosition(p);
    } else {
        cout << "Poziția nu poate fi marcată pentru că este selectată\n";
    }
}

void Game::openTile()
{
    Position p = inputPosition();
    if(this->board->canOpenTileAtPosition(p)) {
        this->board->openTileAtPosition(p);
    } else {
        cout << "Poziția nu poate fi selectată pentru că este marcată\n";
    }
}

void Game::printMapAndForceUncover(bool forceUncover)
{
    cout << "\n" << this->board->mapDisplayString(forceUncover) << "\n";
}

void Game::userSelectedOption(MenuOption option)
{
    switch (option) {
        case MenuOptionNewGame:
            startGameWithSameConfiguration();
            break;
        case MenuOptionOpenTile:
            openTile();
            printMapAndForceUncover();
            break;
        case MenuOptionFlagTile:
            flagTile();
            printMapAndForceUncover();
            break;
        case MenuOptionPrintMap:
            printMapAndForceUncover();
            break;
        case MenuOptionPrintUncoveredMap:
            printMapAndForceUncover(true);
            break;
        case MenuOptionEndGame:
            break;
    }
}

void Game::startGameWithSameConfiguration()
{
    this->board = new Board(this->board->width, this->board->height, this->board->numberOfBombs);
    startGame();
}

void Game::startGame()
{
    cout << "\nIncepe jocul\n";
    gameLoop();
}

MenuOption Game::optionFromMenu()
{
    printMenu(this->menu);
    return inputMenuOptionForMenu(this->menu);
}

void Game::gameLoop()
{
    MenuOption option = optionFromMenu();
    userSelectedOption(option);

    if (option == MenuOptionNewGame || option == MenuOptionEndGame) { return; }

    bool shouldCheckForEndGame = (option == MenuOptionOpenTile);
    if (!shouldCheckForEndGame) {
        gameLoop();
        return;
    }

    bool didWin = (this->board->numberOfUncoveredTiles() == this->board->numberOfBombs);
    bool didLose = this->board->hasABombTileSelected();
    if (didWin) {
        printDidWinMessage();
    } else if (didLose) {
        printDidLoseMessage();
        this->board->uncoverAllBombs();
        printMapAndForceUncover();
    }

    if (didWin || didLose) {
        startGameWithSameConfiguration();
        return;
    }

    gameLoop();
}
