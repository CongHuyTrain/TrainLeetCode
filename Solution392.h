<<<<<<< HEAD
#pragma once
#include <iostream>
#include <string>
using namespace std;
//392. Is Subsequence
//Solved
//Easy
//Topics
//Companies
//Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
//
//A subsequence of a string is a new string that is formed from the original string by deleting some(can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).
//
//
//
//Example 1:
//
//Input: s = "abc", t = "ahbgdc"
//Output : true
//Example 2 :
//
//    Input : s = "axc", t = "ahbgdc"
//    Output : false

class Solution {
public:
    // to find sub string s is exist or not in t.
    bool isSubsequence(string s, string t) {
        int j = 0;
        for (int i = 0; i < t.size(); i++) {
            if (s[j] == t[i]) { // check like s = abc t = abdc -> j = 3 is count number that constant.
                j++;
            }
        }
        if (j == s.size()) return true; // return if count j == size
        return false;

    }
=======
#pragma once
#include <iostream>
#include <string>
using namespace std;
//392. Is Subsequence
//Solved
//Easy
//Topics
//Companies
//Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
//
//A subsequence of a string is a new string that is formed from the original string by deleting some(can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).
//
//
//
//Example 1:
//
//Input: s = "abc", t = "ahbgdc"
//Output : true
//Example 2 :
//
//    Input : s = "axc", t = "ahbgdc"
//    Output : false

class Solution {
public:
    // to find sub string s is exist or not in t.
    bool isSubsequence(string s, string t) {
        int j = 0;
        for (int i = 0; i < t.size(); i++) {
            if (s[j] == t[i]) { // check like s = abc t = abdc -> j = 3 is count number that constant.
                j++;
            }
        }
        if (j == s.size()) return true; // return if count j == size
        return false;

    }
>>>>>>> ccfc2d41cc8ed0575db2cca47d1d2f8d82bb3b45
};