#pragma once
#include"L.h"
//171. Excel Sheet Column Number
//Solved
//Easy
//Topics
//Companies
//Given a string columnTitle that represents the column title as appears in an Excel sheet, return its corresponding column number.
//
//For example :
//
//A -> 1
//B -> 2
//C -> 3
//...
//Z -> 26
//AA -> 27
//AB -> 28
//...
//
//
//Example 1:
//
//Input: columnTitle = "A"
//Output : 1
//Example 2 :
//
//    Input : columnTitle = "AB"
//    Output : 28
//    Example 3 :
//
//    Input : columnTitle = "ZY"
//    Output : 701
//
//
//    Constraints :
//
//    1 <= columnTitle.length <= 7
//    columnTitle consists only of uppercase English letters.
//    columnTitle is in the range["A", "FXSHRXW"].
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int result = 0;
        for (int i = 0; i < columnTitle.size(); i++) {
            int int_element = columnTitle[i] - 'A' + 1;
            for (int j = 1; j < columnTitle.size() - i; j++) {
                int_element = int_element * 26;
            }
            result += int_element;
        }
        return result;
    }
};
//class Solution {
//public:
//    int titleToNumber(string columnTitle) {
//        int result = 0;
//        for (char c : columnTitle) {
//            int value = c - 'A' + 1;
//            result = result * 26 + value;
//        }
//        return result;
//
//    }
//};