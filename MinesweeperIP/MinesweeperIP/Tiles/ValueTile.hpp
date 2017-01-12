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
    virtual string displayString(bool forceUncover) {
        string a = Tile::displayString();
        return a.empty() || forceUncover ? to_string(this->value) : a;
    }
    virtual void incrementValue() {
        this->value++;
    }
    virtual void decrementValue() {
        this->value--;
    }
    virtual bool canOpenAdjacentPositions() {
        return (this->value == 0);
    }
};

#endif /* ValueTile_hpp */
