//
//  MenuAbstract.hpp
//  MinesweeperIP
//
//  Created by Bogdan on 1/13/17.
//  Copyright © 2017 Bogdan Raducan. All rights reserved.
//

#ifndef MenuAbstract_hpp
#define MenuAbstract_hpp

#include <stdio.h>

#include <string>

using namespace std;

class MenuAbstract {
public:
    virtual string displayString() = 0;
    virtual bool isOptionValid(int option) = 0;
};

#endif /* MenuAbstract_hpp */
