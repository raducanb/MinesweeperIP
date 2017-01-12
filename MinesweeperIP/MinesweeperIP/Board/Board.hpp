//
//  Board.hpp
//  MinesweeperIP
//
//  Created by Bogdan on 03/01/17.
//  Copyright © 2017 Bogdan Raducan. All rights reserved.
//

#ifndef Board_hpp
#define Board_hpp

#include "MapLogic.cpp"
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
    void modifyValuesForTilesAtPositions(Positions positions, bool shouldIncrement);
    void openAdjacentPositionsForTileAtPosition(Tile *, Position position);
public:
    const int width;
    const int height;
    const int numberOfBombs;
    int numberOfUncoveredTiles;

    Board(int width = 5, int height = 5, int numberOfBombs = 3);
    ~Board();
    bool canOpenTileAtPosition(Position position);
    bool canToggleFlagForTileAtPosition(Position position);
    void openTileAtPosition(Position position, bool isCalledRecursively = false);
    void toggleFlagForTileAtPosition(Position position);
    string mapDisplayString(bool forceUncover = false);
    bool hasABombTileSelected();
    int numberOfCoveredTiles();
    void uncoverAllBombs();
};

#endif /* Board_hpp */
