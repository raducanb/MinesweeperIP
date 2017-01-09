//
//  Position.cpp
//  MinesweeperIP
//
//  Created by Bogdan on 03/01/17.
//  Copyright © 2017 Bogdan Raducan. All rights reserved.
//

#include <vector>

using namespace std;

struct Position {
    typedef vector<Position> Positions;

    int x;
    int y;

    bool operator==(const Position &o) const {
        return x == o.x && y == o.y;
    }

    bool operator<(const Position &o) const {
        return y < o.y || (y == o.y && x < o.x);
    }

    Positions adjacentPositionsForMaxXMaxY(int maxX, int maxY) {
        Positions adjacentPositions;
        int startPointX = max(this->x - 1, 0);
        int startPointY = max(this->y - 1, 0);
        int endPointX = min(this->x + 2, maxX);
        int endPointY = min(this->y + 2, maxY);

        for (int x = startPointX; x < endPointX; x++) {
            for (int y = startPointY; y < endPointY; y++) {
                bool isPositionRedundant = (x == this->x && y == this->y);
                if (isPositionRedundant) { continue; }

                Position p;
                p.x = x;
                p.y = y;
                adjacentPositions.push_back(p);
            }
        }
        
        return adjacentPositions;
    }
};

