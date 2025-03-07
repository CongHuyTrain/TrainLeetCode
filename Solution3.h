#pragma once
#include"L.h"
//3. Longest Substring Without Repeating Characters
//Medium
//Given a string s, find the length of the longest
//substring without repeating characters.
//Example 1:
//Input: s = "abcabcbb"
//Output : 3
//Explanation : The answer is "abc", with the length of 3.
//Example 2 :
//    Input : s = "bbbbb"
//    Output : 1
//    Explanation : The answer is "b", with the length of 1.
//    Example 3 :
//    Input : s = "pwwkew"
//    Output : 3
//    Explanation : The answer is "wke", with the length of 3.
//    Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
//    Constraints :
//    0 <= s.length <= 5 * 104
//    s consists of English letters, digits, symbols and spaces.
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlength = 0; // int logest substring 
        for (int i = 0; i < s.size(); i++) { // a loot to find each substring can exit
            int cacul = caculLength(s, i); // call fuction, substring without repeating, length of it will return to compare.
            maxlength = max(maxlength, cacul); // compare if new substring is bigger than, them replace it.
            if (maxlength >= s.size() - i) return maxlength; // if length of substring >= length of i to end, then end loot.
        }
        return maxlength;// return answer
    }
    int caculLength(string s, int local) {
        int result = 1;
        string temp = "";
        temp = temp + s[local];
        bool flat = true;
        while (flat == true && local < s.size()-1) {
                for (int j = 0; j < temp.size(); j++) {
                    if (s[local + 1] == temp[j]) {
                        result--;
                        flat = false;
                        break;
                    }
                }
                temp = temp + s[local + 1];
                result++;
                local++;
        }
        return result;
    }
};
//code faster:
/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> m; // aqui o index sera sempre +1
        int size = 0;
        int r = 0;
        //se index atual - ultimo index que apareceu <= size, inclui!
        for (int i = 0; i < s.size(); i++)
        {
            char& c = s[i];
            if(m[c] != 0 && i - (m[c] - 1) <= size){
                size = i - (m[c] - 1);
            }
            else{
                size++;
            }
            m[c] = i + 1;
            r = max(r,size);
        }
        return r;
    }
};



/*
a b c a c b
^ ^ ^ ^ ^
(a:0)
*/