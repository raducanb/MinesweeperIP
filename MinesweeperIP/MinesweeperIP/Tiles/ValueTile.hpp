//
//  ValueTile.hpp
//  MinesweeperIP
//
//  Created by Bogdan on 03/01/17.
//  Copyright © 2017 Bogdan Raducan. All rights reserved.
//

#ifndef ValueTile_hpp
#define ValueTile_hpp

#include "Tile.hpp"

struct ValueTile : Tile {
    int value = 0;
    virtual string displayString() {
        string a = Tile::displayString();
        return a.empty() ? to_string(this->value) : a;
    }
    virtual void incrementValue() {
        this->value++;
    }
};

#endif /* ValueTile_hpp */
