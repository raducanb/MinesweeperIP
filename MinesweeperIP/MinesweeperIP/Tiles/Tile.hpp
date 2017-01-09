//
//  Tile.hpp
//  MinesweeperIP
//
//  Created by Bogdan Raducan on 14/12/2016.
//  Copyright © 2016 Bogdan Raducan. All rights reserved.
//

#ifndef Tile_hpp
#define Tile_hpp

#include <string>

using namespace std;

struct Tile {
    bool isFlagged = false;
    bool isUncovered = false;
    
    virtual string displayString() {
        if (this->isFlagged) {
            return "F";
        } else if (!this->isUncovered) {
            return ".";
        }
        return "";
    };
    virtual void incrementValue() {};
};

#endif /* Tile_hpp */
