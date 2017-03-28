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
	
	// Answer
	bool isUniqueChars(const string &str){
		if (str.length() > 128){
			return false;
		}
		vector<bool> char_set(128);
		for (int i = 0; i < str.length(); i++){
			int val = str[i];
			if (char_set[val]){
				return false;
			}
			char_set[val] = true;
		}
		return true;
	}
	
	//Reduce space usage by a factor of 8 using bitvector. 
	//Each boolean otherwise occupies a size of 8 bits, when you use char instead
	bool isUniqueChars_bitvector(const string &str) {		
		bitset<256> bits(0);
		for(int i = 0; i < str.length(); i++) {
			int val = str[i];
			if(bits.test(val) > 0) {
				return false;
			}
			bits.set(val);
		}
		return true;
	}
	
	bool isUniqueChars_noDS(const string &str) {
		for(int i = 0; i < str.length()-1; i++) {
			for(int j = i+1; j < str.length(); j++) {
				if(str[i] == str[j]) {
					return false;
				}
			}
		}
		return true;
	}
	
	void isUniqueCharsTest () {
		vector<string> words = {"abcde", "hello", "apple", "kite", "padle"};
		for (auto word : words) {
			cout << word << string(": ") << boolalpha << isUniqueChars(word) <<endl;
		}
		cout <<endl << "Using bit vector" <<endl;
		for (auto word : words) {
			cout << word << string(": ") << boolalpha << isUniqueChars_bitvector(word) <<endl;
		}
		cout <<endl << "Using no Data Structures" <<endl;
		for (auto word : words) {
			cout << word << string(": ") << boolalpha << isUniqueChars_noDS(word) <<endl;
		}
	}
	
	// 1.2 Check if one string is a permutation of another string
	bool arePermutation (string str1, string str2) {
		if (str1.size() != str2.size())
			return false;
		
		sort (str1.begin(), str1.end());
		sort (str2.begin(), str2.end());
		
		for (int i = 0; i < str1.size(); i++) {
			if (str1[i] != str2[i])
				return false;
		}
		return true;;
	}
	
	bool arePermutation_2 (string str1, string str2) {
		if (str1.size() != str2.size())
			return false;
		
		int count[256] = {0};
		int val;
		for (int i = 0; i < str1.size(); i++) {
			val = str1[i];
			count[val]++;
		}
		
		for (int i = 0; i < str2.size(); i++) {
			val = str2[i];
			count[val]--;
			if (count[val] < 0)
				return false;
		}
		
		return true;
	}
	
	bool arePermutationTest () {
		// Test Method 1 - Using sort
		cout << "Method 1 - Using sort" << endl;
		string str1 = "testest";
		string str2 = "estxest";
		if(arePermutation(str1, str2))
			cout << str1 <<" and " << str2 << " are permutation of each other" << endl;
		else
			cout << str1 <<" and " << str2 << " are not permutation of each other" << endl;
		str1 = "hello";
		str2 = "oellh";
		if(arePermutation(str1, str2))
			cout << str1 <<" and " << str2 << " are permutation of each other" << endl;
		else
			cout << str1 <<" and " << str2 << " are not permutation of each other" << endl;
		
		//Test Method 2 - Using character count
		cout << "Method 2 - Using character count" << endl;
		str1 = "testest";
		str2 = "estxest";
		if(arePermutation_2(str1, str2))
			cout << str1 <<" and " << str2 << " are permutation of each other" << endl;
		else
			cout << str1 <<" and " << str2 << " are not permutation of each other" << endl;
		str1 = "hello";
		str2 = "oellh";
		if(arePermutation_2(str1, str2))
			cout << str1 <<" and " << str2 << " are permutation of each other" << endl;
		else
			cout << str1 <<" and " << str2 << " are not permutation of each other" << endl;
		return 0;
	}
};

#endif /* Mystring_h */
