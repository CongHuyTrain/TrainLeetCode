#pragma once
#include"L.h"
//168
class convertinttostring {
public:
    string convertToTitle(int columnNumber) {
        string result = "";
        while (columnNumber) {
            char last = 'A' + (columnNumber - 1) % 26;
            result = last + result;
            columnNumber = (columnNumber - 1) / 26;
        }
        return result;
    }
};
//vd 1 -> A, 27-> AA, 703->AAA.
//code faster
/*
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res;

        while (columnNumber > 0) {
            columnNumber--;
            res += (columnNumber % 26) + 'A';
            columnNumber /= 26;
        }

        std::reverse(res.begin(), res.end());
        */