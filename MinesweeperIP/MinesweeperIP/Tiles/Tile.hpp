//
//  Tile.hpp
//  MinesweeperIP
//
//  Created by Bogdan Raducan on 14/12/2016.
//  Copyright © 2016 Bogdan Raducan. All rights reserved.
//

#ifndef Tile_hpp
#define Tile_hpp

struct Tile {
public:
    bool isFlagged = false;
    bool isUncovered = false;
    virtual ~Tile() {};
};

#endif /* Tile_hpp */
