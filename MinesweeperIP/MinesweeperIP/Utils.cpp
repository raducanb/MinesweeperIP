//
//  Utils.cpp
//  MinesweeperIP
//
//  Created by Bogdan on 1/13/17.
//  Copyright © 2017 Bogdan Raducan. All rights reserved.
//

#include <stdio.h>

#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class Utils {
public:
    static bool verifyNumberMinZero(int number)
    {
        return number >= 0;
    }

    static int inputNumber(string stringToShow, function<bool (int)> verificationFunction)
    {
        int inputOption = 0;
        string inputString;
        bool didTryOnce;

        while (true) {
            cout << stringToShow << (didTryOnce ? " validă" : "") << ": ";
            cin >> inputString;

            stringstream stream(inputString);
            if (stream >> inputOption && verificationFunction(inputOption)) { break; }
            didTryOnce = true;
        }

        return inputOption;
    }
};
