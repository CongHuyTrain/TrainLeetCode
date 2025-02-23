#pragma once
#include<iostream>
#include<unordered_map>
using namespace std;
//383. Ransom Note
//Solved
//Easy
//Topics
//Companies
//Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.
//
//Each letter in magazine can only be used once in ransomNote.
//
//
//
//Example 1:
//
//Input: ransomNote = "a", magazine = "b"
//Output : false
//Example 2 :
//
//	Input : ransomNote = "aa", magazine = "ab"
//	Output : false
//	Example 3 :
//
//	Input : ransomNote = "aa", magazine = "aab"
//	Output : true
//
//
//	Constraints :
//
//	1 <= ransomNote.length, magazine.length <= 105
//	ransomNote and magazine consist of lowercase English letters.
//	Seen this question in a real interview before ?
//	1 / 5
class Solution {
public:
    // the purpose is return true if maga can construct to become ransom.
    // frist count how many character ( vd a is 2, b is 0) of maga by hasmap
    // and then check ransom if no longer can construct character, return false
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> magaCount;
        for (int i = 0; i < magazine.size(); i++) {
            magaCount[magazine[i]]++;
        }
        for (int i = 0; i < ransomNote.size(); i++) {
            if (magaCount[ransomNote[i]] < 1) {
                return false;
            }
            magaCount[ransomNote[i]] -= 1;
        }
        return true;
    }
};