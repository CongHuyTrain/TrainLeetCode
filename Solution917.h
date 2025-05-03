#pragma once
#include"L.h"
//917. Reverse Only Letters
//Easy
//Topics
//Companies
//Hint
//Given a string s, reverse the string according to the following rules :
//
//All the characters that are not English letters remain in the same position.
//All the English letters(lowercase or uppercase) should be reversed.
//Return s after reversing it.
//Example 1:
//
//Input: s = "ab-cd"
//Output : "dc-ba"
//Example 2 :
//
//    Input : s = "a-bC-dEf-ghIj"
//    Output : "j-Ih-gfE-dCba"
//    Example 3 :
//
//    Input : s = "Test1ng-Leet=code-Q!"
//    Output : "Qedo1ct-eeLg=ntse-T!"
//
//
//    Constraints :
//
//    1 <= s.length <= 100
//    s consists of characters with ASCII values in the range[33, 122].
//    s does not contain '\"' or '\\'.
class Solution {
public:
    string reverseOnlyLetters(string s) {
        string reverse;
        int left = 0;
        int right = s.size() - 1;
        int local = 0;
        while (left < s.size() || right >= 0) {
            if ((s[left] < 'a' || s[left] > 'z') && (s[left] < 'A' || s[left] > 'Z')) {
                reverse[local] = s[left];
                local++;
                left++;
            }
            else {
                if (('z' >= s[right] >= 'a') || ('Z' >= s[right] >= 'A')) {
                    reverse[local] = s[right];
                    local++;
                }
                right--;
                left++;
            }
        }
        return reverse;
    }
};