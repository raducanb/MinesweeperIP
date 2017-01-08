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
    this->tilesMap.clear();
};

void Board::initTilesMap(int width, int height)
{
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            Position p;
            p.x = i;
            p.y = j;
            ValueTile *tile = new ValueTile();

            this->tilesMap[p] = tile;
        }
    }
}

void Board::addBombsToTilesMapAtPositions(Positions bombsPositions)
{
    for (Position &position : bombsPositions) {
        BombTile *bombTile = new BombTile();
        this->tilesMap[position] = bombTile;
        incrementValuesForAllTilesAtPositions(adjacentPositionsForPosition(position));
    }
}

string stringForUncoveredTile(Tile *tile)
{
    if (Board::isTileBomb(tile)) {
        return "B";
    } else {
        ValueTile *valueTile = dynamic_cast<ValueTile *>(tile);
        return to_string(valueTile->value);
    }
}

string stringForTile(Tile *tile, bool forceUncover)
{
    if (tile->isUncovered || forceUncover) {
        return stringForUncoveredTile(tile);
    } else if (tile->isFlagged) {
        return "F";
    } else {
        return ".";
    }
}

void Board::printMap(bool forceUncover)
{
    string mapString;
    for(auto const &posAndTile : this->tilesMap) {
        string tileString = ::stringForTile(posAndTile.second, forceUncover);
        int xPos = posAndTile.first.x;
        bool isLastItemOnLine = xPos == (this->width - 1);
        tileString.append(isLastItemOnLine ? "\n" : " ");
        mapString.append(tileString);
    }
    cout << mapString << "\n";
}

void Board::incrementValuesForAllTilesAtPositions(Positions positions)
{
    for (Position &position : positions) {
        Tile *tile = this->tilesMap[position];
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
    Tile *tile = this->tilesMap[position];
    bool shouldStop = isTileBomb(tile) || tile->isUncovered;
    if (shouldStop) { return; }

    tile->isUncovered = true;

    ValueTile *valueTile = dynamic_cast<ValueTile *>(tile);
    bool shouldOpenAdjacentPositions = (valueTile->value == 0);
    if (!shouldOpenAdjacentPositions) { return; }

    for (auto &i : adjacentPositionsForPosition(position)) {
        openPositionAndNeighbours(i);
    }
}

Positions Board::adjacentPositionsForPosition(Position position)
{
    Positions adjacentPositions;
    int startPointX = max(position.x - 1, 0);
    int startPointY = max(position.y - 1, 0);
    int endPointX = min(position.x + 2, this->width);
    int endPointY = min(position.y + 2, this->height);

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
