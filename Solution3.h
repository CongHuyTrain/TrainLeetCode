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
            int cacul = caculLength(s, i);
            maxlength = max(maxlength, cacul);
            if (maxlength >= s.size() - i) return maxlength;
        }
        return maxlength;
    }
    int caculLength(string s, int local) {
        int result = 0;
        string temp = "";
        temp = temp + s[local];
        int i = local;
        bool flat = true;
        while (flat == true && i < s.size() - 1) {
            if (s[i] == s[i + 1]) {
                for (int j = 0; j < temp.size(); j++) {
                    if (s[i + 1] == temp[j]) {
                        result--;
                        flat = false;
                        break;
                    }
                }
                temp = temp + s[i + 1];
                result++;
            }
            i++;
        }
        return result;
    }
};