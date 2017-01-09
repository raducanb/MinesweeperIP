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
#include <set>

bool isTileBomb(Tile *tile)
{
    return (typeid(*tile) == typeid(BombTile));
}

Board::Board(int width, int height, int numberOfBombs)
            : width(width), height(height), numberOfBombs(numberOfBombs)
{
    initTilesMap(width, height);
    Positions positions = MapLogic::generateBombsPositions(width, height, numberOfBombs);
    addBombsToTilesMapAtPositions(positions);
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
    return MapLogic::displayStringForMap(this->tilesMap, this->width, forceUncover);
}

void Board::incrementValuesForAllTilesAtPositions(Positions positions)
{
    for (Position &position : positions) {
        Tile *tile = this->tilesMap[position];
        tile->incrementValue();
    }
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

    openAdjacentPositionsForTileAtPosition(tile, position);
}

void Board::openAdjacentPositionsForTileAtPosition(Tile *tile, Position position)
{
    if (!tile->canOpenAdjacentPositions()) { return; }
    
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
