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

#include "../Utils.cpp"

using namespace std;

void printMenu(InGameMenu menu)
{
    cout << menu.displayString();
}

InGameMenuOption inputMenuOptionForMenu(InGameMenu menu)
{
    int input = Utils::inputNumber("Introdu o opțiune din meniu", menu.isOptionValid);

    return (InGameMenuOption)input;
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
        p.x = Utils::inputNumber("Introdu x", Utils::verifyNumberMinZero);
    } while (p.x >= this->board->width);
    do {
        p.y = Utils::inputNumber("Introdu y", Utils::verifyNumberMinZero);
    } while (p.y >= this->board->height);
    return p;
}

bool Game::flagTile()
{
    Position p = inputPosition();
    if (this->board->canToggleFlagForTileAtPosition(p)) {
        this->board->toggleFlagForTileAtPosition(p);
        return true;
    } else {
        cout << "Poziția nu poate fi marcată pentru că este selectată sau ai prea multe marcaje puse deja\n";
        return false;
    }
}

bool Game::openTile()
{
    Position p = inputPosition();

    bool isFirstMove = (this->board->numberOfUncoveredTiles == 0);
    if (isFirstMove) {
        this->board->replaceTileAtPositionIfIsBomb(p);
    }

    if(this->board->canOpenTileAtPosition(p)) {
        this->board->openTileAtPosition(p);
        return true;
    } else {
        cout << "Poziția nu poate fi selectată pentru că este marcată\n";
        return false;
    }
}

void Game::printMapAndForceUncover(bool forceUncover)
{
    cout << "\n" << this->board->mapDisplayString(forceUncover);
}

void Game::userSelectedOption(InGameMenuOption option)
{
    switch (option) {
        case MenuOptionNewGame:
            startGameWithSameConfiguration();
            break;
        case MenuOptionOpenTile: {
            bool success = openTile();
            if (!success) { break; }
            printMapAndForceUncover();
            break;
        }
        case MenuOptionFlagTile: {
            bool success = flagTile();
            if (!success) { break; }
            printMapAndForceUncover();
            break;
        }
        case MenuOptionPrintMap:
            printMapAndForceUncover();
            break;
        case MenuOptionPrintUncoveredMap:
            printMapAndForceUncover(true);
            break;
        case MenuOptionEndGame:
            cout << "\nJoc abandonat\n";
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
    cout << "\nJocul incepe\n" << endl;
    gameLoop();
}

InGameMenuOption Game::optionFromMenu()
{
    printMenu(this->menu);
    return inputMenuOptionForMenu(this->menu);
}

void Game::gameLoop()
{
    InGameMenuOption option = optionFromMenu();
    userSelectedOption(option);

    if (option == MenuOptionNewGame || option == MenuOptionEndGame) { return; }

    bool shouldCheckForEndGame = (option == MenuOptionOpenTile || option == MenuOptionFlagTile);
    if (!shouldCheckForEndGame) {
        gameLoop();
        return;
    }

    bool didWin = (this->board->numberOfCoveredTiles() == this->board->numberOfBombs
                   || this->board->numberOfFlaggedBombs == this->board->numberOfBombs);
    bool didLose = this->board->hasABombTileSelected();
    if (didWin) {
        printDidWinMessage();
    } else if (didLose) {
        printDidLoseMessage();
        this->board->uncoverAllBombs();
        printMapAndForceUncover();
    }

    if (!didWin && !didLose) {
        gameLoop();
    }
}
