#pragma once
//1957. Delete Characters to Make Fancy String
//Solved
//Easy
//Topics
//premium lock icon
//Companies
//Hint
//A fancy string is a string where no three consecutive characters are equal.
//
//Given a string s, delete the minimum possible number of characters from s to make it fancy.
//
//Return the final string after the deletion.It can be shown that the answer will always be unique.
//
//
//
//Example 1:
//
//Input: s = "leeetcode"
//Output : "leetcode"
//Explanation :
//    Remove an 'e' from the first group of 'e's to create "leetcode".
//    No three consecutive characters are equal, so return "leetcode".
//    Example 2 :
//
//    Input : s = "aaabaaaa"
//    Output : "aabaa"
//    Explanation :
//    Remove an 'a' from the first group of 'a's to create "aabaaaa".
//    Remove two 'a's from the second group of 'a's to create "aabaa".
//    No three consecutive characters are equal, so return "aabaa".
//    Example 3 :
//
//    Input : s = "aab"
//    Output : "aab"
//    Explanation : No three consecutive characters are equal, so return "aab".
//
//
//    Constraints :
//
//    1 <= s.length <= 105
//    s consists only of lowercase English letters.
class Solution {
public:
    string makeFancyString(string s) {
        string result = "";
        result += s[0];
        char compare = result[0];
        int count = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == compare) {
                count++;
                if (count == 3) {
                    while (i < s.size()) {
                        i++;
                        if (s[i] != compare)
                            break;
                    }
                    if (i == s.size())   return result;
                    count = 1;
                    result += s[i];
                    compare = s[i];
                }
                else {
                    result += s[i];
                }
            }
            else {
                count = 1;
                result += s[i];
                compare = s[i];
            }
        }
        return result;
    }
};