#pragma once
#include<unordered_set>
#include"L.h"
//859. Buddy Strings
//Solved
//Easy
//Topics
//Companies
//Given two strings s and goal, return true if you can swap two letters in s so the result is equal to goal, otherwise, return false.
//
//Swapping letters is defined as taking two indices i and j(0 - indexed) such that i != j and swapping the characters at s[i] and s[j].
//
//For example, swapping at indices 0 and 2 in "abcd" results in "cbad".
//
//
//Example 1:
//
//Input: s = "ab", goal = "ba"
//Output : true
//Explanation : You can swap s[0] = 'a' and s[1] = 'b' to get "ba", which is equal to goal.
//Example 2 :
//
//    Input : s = "ab", goal = "ab"
//    Output : false
//    Explanation : The only letters you can swap are s[0] = 'a' and s[1] = 'b', which results in "ba" != goal.
//    Example 3 :
//
//    Input : s = "aa", goal = "aa"
//    Output : true
//    Explanation : You can swap s[0] = 'a' and s[1] = 'a' to get "aa", which is equal to goal.
class Solution {
public:
    bool buddyStrings(string s, string goal) {
        unordered_set<char> countChar;
        int left = 0; // storage location of character first(that character is different between s and goal) 
        int right = 0; // storage location of character second
        bool flat = false; // flat in situation that character is repeart like example 3, default is wrong
        if (s.size() != goal.size()) return false; // return false if two string is not balance
        while (left < s.size()) { // find character first, if can't find, then end loot and return s==goal and flat
            if (s[left] != goal[left]) { // check if can find, then left is static 
                right = left + 1; //right will start continue instead to find
                while (right < s.size()) {
                    if (s[right] != goal[right]) { // if find location of second character, then.
                        swap(s[left], s[right]); // swap character first and character sencond
                        return (s == goal); // return final result;
                    }
                    right++;
                }
                break; // if can find character second, then end loot and return s==goal && flat
            }
            if (countChar.count(s[left]))    flat = true; // check if have two resemble charcater
            countChar.insert(s[left]);
            left++;
        }
        return (s == goal) && flat;// why &&, because in problem must swap, so if you not swap, it will go wrong(example 2).
        // and look example 2, if you have two character that is similar, then it mean you can swap it, and check them if check if s and goal is equal.
    }
};