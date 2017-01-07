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

#include <time.h>
#include <iostream>
#include <set>

static int const kNumberOfBombs = 10;

Positions generateBombsPositions(int maxWidth, int maxHeight);

int generateRandomNumberSmallerThan(int max)
{
    return rand() % max;
}

Board::Board(int width, int height)
{
    this->width = width;
    this->height = height;

    initTilesMap(width, height);
    addBombsToTilesMapAtPositions(generateBombsPositions(width, height));
}

Board::~Board()
{
    tilesMap.clear();
};

void Board::initTilesMap(int width, int height)
{
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            Position p;
            p.x = i;
            p.y = j;
            ValueTile *tile = new ValueTile();

            tilesMap[p] = tile;
        }
    }
}

void Board::addBombsToTilesMapAtPositions(Positions bombsPositions)
{
    for (Position &position : bombsPositions) {
        BombTile *bombTile = new BombTile();
        tilesMap[position] = bombTile;
        incrementValuesForAllTilesAtPositions(adjacentPositionsForPosition(position));
    }
}

void Board::incrementValuesForAllTilesAtPositions(Positions positions)
{
    for (Position &position : positions) {
        Tile *tile = tilesMap[position];
        if (isTileBomb(tile)) { continue; }

        ValueTile *valueTile = dynamic_cast<ValueTile *>(tile);
        valueTile->value++;
    }
}

Positions generateBombsPositions(int maxWidth, int maxHeight)
{
    set<Position> bombsPositions;

    srand((unsigned int)time(NULL));
    do {
        Position p;
        int x = generateRandomNumberSmallerThan(maxWidth);
        int y = generateRandomNumberSmallerThan(maxHeight);
        p.x = x;
        p.y = y;
        bombsPositions.insert(p);
    } while (bombsPositions.size() < kNumberOfBombs);

    return Positions(bombsPositions.begin(), bombsPositions.end());
}

bool Board::isTileBomb(Tile *tile)
{
    return (typeid(*tile) == typeid(BombTile));
}

void Board::openPositionAndNeighbours(Position position)
{
    Tile *tile = tilesMap[position];
    tile->isUncovered = true;

    for (auto &i : adjacentPositionsForPosition(position)) {
        openPositionAndNeighbours(i);
    }
}

Positions Board::adjacentPositionsForPosition(Position position)
{
    Positions adjacentPositions;
    int startPointX = max(position.x - 1, 0);
    int startPointY = max(position.y - 1, 0);
    int endPointX = min(position.x + 2, width - 1);
    int endPointY = min(position.y + 2, height - 1);

    for (int x = startPointX; x < endPointX; x++) {
        for (int y = startPointY; y < endPointY; y++) {
            bool isPositionRedundant = (x == position.x && y == position.y);
            if (isPositionRedundant) { continue; }

            Position p;
            p.x = x;
            p.y = y;
            adjacentPositions.push_back(p);
        }
    }

    return adjacentPositions;
}
