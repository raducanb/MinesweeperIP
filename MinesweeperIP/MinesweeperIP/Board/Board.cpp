//
//  Board.cpp
//  MinesweeperIP
//
//  Created by Bogdan on 03/01/17.
//  Copyright © 2017 Bogdan Raducan. All rights reserved.
//

#include "Board.hpp"

#include "BombTile.hpp"
#include "ValueTile.hpp"

bool Board::isTileBomb(Tile *tile) {
    return (typeid(*tile) == typeid(BombTile));
}
