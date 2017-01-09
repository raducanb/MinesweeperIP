//
//  BombTile.hpp
//  MinesweeperIP
//
//  Created by Bogdan on 03/01/17.
//  Copyright © 2017 Bogdan Raducan. All rights reserved.
//

#ifndef BombTile_hpp
#define BombTile_hpp

#include "Tile.hpp"

struct BombTile : Tile {
    virtual string displayString(bool forceUncover) {
        string a = Tile::displayString();
        return a.empty() || forceUncover ? "B" : a;
    }
    virtual bool canOpenAdjacentPositions() {
        return false;
    }
};

#endif /* BombTile_hpp */
