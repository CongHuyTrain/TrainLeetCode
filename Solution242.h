#pragma once
#include<unordered_map>
#include<iostream>
using namespace std;
//242. Valid Anagram
//Solved
//Easy
//Topics
//Companies
//Given two strings s and t, return true if t is an anagram of s, and false otherwise.
//
//
//
//Example 1:
//
//Input: s = "anagram", t = "nagaram"
//
//Output : true
//
//Example 2 :
//
//	Input : s = "rat", t = "car"
//
//	Output : false
// very easy, just count char and check.
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())    return false;
        unordered_map<char, int> storage;
        for (int i = 0; i < s.size(); i++) {
            storage[s[i]]++;
        }
        for (int i = 0; i < s.size(); i++) {
            if (storage[t[i]] == 0)  return false;
            storage[t[i]]--;
        }
        return true;
    }
};
// look Solution217