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

void Board::openPositionAndNeighbours(Position position) {
    Tile tile = tilesMap[position];
    tile.isUncovered = true;

    for (auto &i : adjacentPositionsForPosition(position)) {
        openPositionAndNeighbours(i);
    }
}

vector<Position> adjacentPositionsForPosition(Position position) {
    vector<Position> adjacentPositions;
    for (int x = position.x - 1; x < position.x + 2; x++) {
        for (int y = position.y - 1; y < position.y + 2; y++) {
            if (x == position.x && y == position.y) { continue; }

            Position p;
            p.x = x;
            p.y = y;
            adjacentPositions.push_back(p);
        }
    }

    return adjacentPositions;
}
