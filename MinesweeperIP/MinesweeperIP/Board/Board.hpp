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

using namespace std;

class Board {
private:
    map<Position, Tile> tilesMap;

    bool isTileBomb(Tile *tile);
};

#endif /* Board_hpp */
