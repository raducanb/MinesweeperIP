//
//  main.cpp
//  MinesweeperIP
//
//  Created by Bogdan Raducan on 14/12/2016.
//  Copyright © 2016 Bogdan Raducan. All rights reserved.
//

#include <iostream>

#include "Game/Menu/MainMenu.hpp"
#include "Game/Game.hpp"
#include "Utils.cpp"

using namespace std;

MenuOption optionFromMenu(MainMenu menu);
void mainMenuLoop();

int main(int argc, const char * argv[])
{
    cout << "Minesweeper!" << endl;

    mainMenuLoop();
    
    return 0;
}

void newGame(int width, int height, int numberOfBombs)
{
    Board *b = new Board(width, height, numberOfBombs);
    Game g = Game(b);
    g.startGame();
}

void inputForNewGame()
{
    cout << "Initializare harta\n";
    int width = Utils::inputNumber("Introdu nr de coloane", Utils::verifyNumberMinZero);
    int height = Utils::inputNumber("Introdu nr de linii", Utils::verifyNumberMinZero);
    int numberOfBombs = Utils::inputNumber("Introdu nr de bombe", Utils::verifyNumberMinZero);
    if (0.6 * width * height < numberOfBombs) {
        cout << "Numarul de bombe trebuie sa fie mai mic decat 60% din numarul total de tile-uri\n";
        inputForNewGame();
        return;
    }
    newGame(width, height, numberOfBombs);
}

void startGameWithMenuMode(MenuOption option)
{
    switch (option) {
        case MenuOptionStartCustomGame:
            inputForNewGame();
            break;
        case MenuOptionStartEasyGame:
            newGame(8, 8, 10);
            break;
        case MenuOptionStartMediumGame:
            newGame(16, 16, 40);
            break;
        case MenuOptionStartHardGame:
            newGame(16, 30, 99);
            break;
        case MenuOptionQuit:
            // do nothing;
            break;
    }
}

void mainMenuLoop()
{
    MainMenu mainMenu;
    MenuOption option = optionFromMenu(mainMenu);
    if (option == MenuOptionQuit) { return; }
    startGameWithMenuMode(option);
    mainMenuLoop();
}

MenuOption inputMenuOptionForMenu(MainMenu menu)
{
    int input = Utils::inputNumber("Introdu o opțiune din meniu", menu.isOptionValid);

    return (MenuOption)input;
}

MenuOption optionFromMenu(MainMenu menu)
{
    cout << "\n" << menu.displayString() << "\n";
    return inputMenuOptionForMenu(menu);
}
