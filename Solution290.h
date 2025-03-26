#pragma once
#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        s += ' ';
        unordered_map<char, string> storage;
        unordered_map<string, char> storage1; // we need another hashmap because like...
        // pattern 'abba' and s 'dog dog dog dog', it is wrong, a-> dog, b-> dog?, 
        // so another map to check dog is exit a character before.
        string temp = "";
        int j = 0; // use to count and finaly check with size of pattern.
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') temp += s[i];
            else {
                if (j >= pattern.size() || (storage.find(pattern[j]) != storage.end() && storage[pattern[j]] != temp) 
                    || (storage1.find(temp) != storage1.end() && storage1[temp] != pattern[j]))    return false;
                storage[pattern[j]] = temp;
                storage1[temp] = pattern[j];
                temp = "";
                j++;
            }
        }
        return j == pattern.size() ? true : false; // vd pattern 'cana' and s 'cana', is false, and pattern 'a' and s 'a' is true.
        // so c-> cana, and ana ?, so that is wrong.
    }
};