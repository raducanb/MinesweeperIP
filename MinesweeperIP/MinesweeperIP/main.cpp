//
//  main.cpp
//  MinesweeperIP
//
//  Created by Bogdan Raducan on 14/12/2016.
//  Copyright © 2016 Bogdan Raducan. All rights reserved.
//

#include <iostream>

#include "Tile.hpp"

#include "Game.hpp"

using namespace std;

int main(int argc, const char * argv[])
{
    cout << "Minesweeper!" << endl;
    
    Game g;
    g.startGame();
    
    return 0;
}
