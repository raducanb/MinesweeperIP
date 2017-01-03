//
//  Position.cpp
//  MinesweeperIP
//
//  Created by Bogdan on 03/01/17.
//  Copyright © 2017 Bogdan Raducan. All rights reserved.
//

struct Position {
    int x;
    int y;

    bool operator==(const Position &o) const {
        return x == o.x && y == o.y;
    }

    bool operator<(const Position &o) const {
        return x < o.x || (x == o.x && y < o.y);
    }
};
