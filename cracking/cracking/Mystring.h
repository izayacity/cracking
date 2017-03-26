//
//  Mystring.h
//  cracking
//
//  Created by Francis Yang on 3/25/17.
//  Copyright © 2017 izayacity. All rights reserved.
//

#ifndef Mystring_h
#define Mystring_h
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class Mystring {
public:
    // Determine if a string has all unique characters.
    bool isUnique (string str) {
        if (str.empty())
            return false;
        else {
            sort (str.begin(), str.end());
            for (int i = 1; i < str.size(); i++) {
                if (str[i] == str[i - 1])
                    return false;
            }
            return true;
        }
    }
    
	void isUniqueTest () {
		vector<string> strs = {"", "abcdefg", "abcdefa"};
		if (!isUnique (strs[0]))
			cout << "Test case 1: " << strs [0] << " passed!" << endl;
		else
			cout << "Test case 1: " << strs [0] << " failed!" << endl;
		if (isUnique (strs[1]))
			cout << "Test case 2: " << strs [1] << " passed!" << endl;
		else
			cout << "Test case 2: " << strs [1] << " failed!" << endl;
		if (!isUnique (strs[2]))
			cout << "Test case 3: " << strs [2] << " passed!" << endl;
		else
			cout << "Test case 3: " << strs [2] << " failed!" << endl;
	}
};

#endif /* Mystring_h */
