//
//  Board.hpp
//  MinesweeperIP
//
//  Created by Bogdan on 03/01/17.
//  Copyright © 2017 Bogdan Raducan. All rights reserved.
//

#ifndef Board_hpp
#define Board_hpp

#include "Position.cpp"
#include "Tile.hpp"

#include <map>
#include <vector>
#include <string>

using namespace std;

typedef vector<Position> Positions;

class Board {
private:
    map<Position, Tile *> tilesMap;

    void initTilesMap(int width, int height);
    void addBombsToTilesMapAtPositions(Positions bombsPositions);
    void incrementValuesForAllTilesAtPositions(Positions positions);
    void openAdjacentPositionsForTileAtPosition(Position position);
public:
    const int width;
    const int height;

    Board(int width = 5, int height = 5, int numberOfBombs = 3);
    ~Board();
    static bool isTileBomb(Tile *tile);
    void openTileAtPosition(Position position, bool isFirstTime = true);
    void toggleFlagForTileAtPosition(Position position);
    string mapDisplayString(bool forceUncover = false);
};

#endif /* Board_hpp */
