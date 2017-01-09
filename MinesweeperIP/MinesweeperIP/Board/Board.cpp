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
#include <cstdlib>
#include <set>

Positions generateBombsPositions(int maxWidth, int maxHeight, int numberOfBombs);

int generateRandomNumberSmallerThan(int max)
{
    return rand() % max;
}

bool isTileBomb(Tile *tile)
{
    return (typeid(*tile) == typeid(BombTile));
}

Board::Board(int width, int height, int numberOfBombs)
            : width(width), height(height), numberOfBombs(numberOfBombs)
{
    initTilesMap(width, height);
    addBombsToTilesMapAtPositions(generateBombsPositions(width, height, numberOfBombs));
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
        auto adjacentPositions = position.adjacentPositionsForMaxXMaxY(this->width, this->height);
        incrementValuesForAllTilesAtPositions(adjacentPositions);
    }
}

void Board::toggleFlagForTileAtPosition(Position position)
{
    Tile *tile = this->tilesMap[position];
    tile->isFlagged = !tile->isFlagged;
}

string Board::mapDisplayString(bool forceUncover)
{
    string mapString;
    for(auto const &posAndTile : this->tilesMap) {
        string tileString = posAndTile.second->displayString();
        int xPos = posAndTile.first.x;
        bool isLastItemOnLine = xPos == (this->width - 1);
        tileString.append(isLastItemOnLine ? "\n" : " ");
        mapString.append(tileString);
    }
    return mapString;
}

void Board::incrementValuesForAllTilesAtPositions(Positions positions)
{
    for (Position &position : positions) {
        Tile *tile = this->tilesMap[position];
        tile->incrementValue();
    }
}

Positions generateBombsPositions(int maxWidth, int maxHeight, int numberOfBombs)
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
    } while (bombsPositions.size() < numberOfBombs);

    return Positions(bombsPositions.begin(), bombsPositions.end());
}

bool Board::canOpenTileAtPosition(Position position)
{
    Tile *tile = this->tilesMap[position];
    return !tile->isFlagged;
}

bool Board::canToggleFlagForTileAtPosition(Position position)
{
    Tile *tile = this->tilesMap[position];
    return !tile->isUncovered;
}

void Board::openTileAtPosition(Position position, bool isFirstTime)
{
    Tile *tile = this->tilesMap[position];
    bool foundBombAndIsCalledRecursively = (isTileBomb(tile) && !isFirstTime);
    bool shouldStop = foundBombAndIsCalledRecursively || tile->isUncovered;
    if (shouldStop) { return; }

    tile->isUncovered = true;

    openAdjacentPositionsForTileAtPosition(position);
}

void Board::openAdjacentPositionsForTileAtPosition(Position position)
{
    ValueTile *valueTile = dynamic_cast<ValueTile *>(this->tilesMap[position]);
    if (valueTile == nullptr) { return; }

    bool shouldOpenAdjacentPositions = (valueTile->value == 0);
    if (!shouldOpenAdjacentPositions) { return; }

    for (auto &i : position.adjacentPositionsForMaxXMaxY(this->width, this->height)) {
        openTileAtPosition(i, false);
    }
}

bool Board::hasABombTileSelected()
{
    for (auto &i : this->tilesMap) {
        Tile *tile = i.second;
        if (isTileBomb(tile) && tile->isUncovered) {
            return true;
        }
    }

    return false;
}

int Board::numberOfUncoveredTiles()
{
    int uncoveredTilesNumber = 0;
    for (auto &i : this->tilesMap) {
        Tile *tile = i.second;
        if (tile->isUncovered) { continue; }
        uncoveredTilesNumber++;
    }
    return uncoveredTilesNumber;
}
