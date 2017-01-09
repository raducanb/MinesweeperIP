//
//  MapLogic.cpp
//  MinesweeperIP
//
//  Created by Bogdan on 1/9/17.
//  Copyright © 2017 Bogdan Raducan. All rights reserved.
//

#include <stdio.h>
#include <set>
#include <vector>
#include <cstdlib>

#include "Position.cpp"

using namespace std;

typedef vector<Position> Positions;

struct MapLogic {
    static int generateRandomNumberSmallerThan(int max)
    {
        return rand() % max;
    }

    static Positions generateBombsPositions(int maxWidth, int maxHeight, int numberOfBombs)
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
};
