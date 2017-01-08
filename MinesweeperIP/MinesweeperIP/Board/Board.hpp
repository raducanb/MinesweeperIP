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

using namespace std;

typedef vector<Position> Positions;

class Board {
private:
    map<Position, Tile *> tilesMap;
    int width;
    int height;

    Positions adjacentPositionsForPosition(Position position);
    void initTilesMap(int width, int height);
    void addBombsToTilesMapAtPositions(Positions bombsPositions);
    void incrementValuesForAllTilesAtPositions(Positions positions);
public:
    Board(int width, int height);
    ~Board();
    static bool isTileBomb(Tile *tile);
    void openPositionAndNeighbours(Position position);
};

#endif /* Board_hpp */
