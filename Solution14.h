#pragma once
#include"L.h"
//14. Longest Common Prefix
//Easy
//Topics
//Companies
//Write a function to find the longest common prefix string amongst an array of strings.
//
//If there is no common prefix, return an empty string "".
//
//
//
//Example 1:
//
//Input: strs = ["flower", "flow", "flight"]
//Output : "fl"
//Example 2 :
//
//	Input : strs = ["dog", "racecar", "car"]
//	Output : ""
//	Explanation : There is no common prefix among the input strings.
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";
        for (int i = 0; i < strs[0].size(); i++) {
            if (longestis(strs, strs[0][i], i)) {
                result += strs[0][i];
            }
            else {
                return result;
            }
        }
        return result;
    }
    bool longestis(vector<string>& strs, char check, int local) {
        for (int i = 1; i < strs.size(); i++) {
            if (check != strs[i][local]) {
                return false;
            }
        }
        return true;
    }
};