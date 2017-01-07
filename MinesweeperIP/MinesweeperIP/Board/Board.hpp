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

class Board {
private:
    map<Position, Tile> tilesMap;
    vector<Position> adjacentPositionsForPosition(Position position);
public:
    bool isTileBomb(Tile *tile);
    void openPositionAndNeighbours(Position position);
};

#endif /* Board_hpp */
