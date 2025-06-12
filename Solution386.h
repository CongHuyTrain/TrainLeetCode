#pragma once
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> lex;
        for (int i = 1; i <= 9; ++i) {
            generateLexicalNumbers(i, n, lex);
        }
        return lex;
    }
    void generateLexicalNumbers(int currnum, int limit, vector<int>& result) {
        if (currnum > limit) return;
        result.push_back(currnum);
        for (int nextDigit = 0; nextDigit <= 9; ++nextDigit) {
            int nextNumber = currnum * 10 + nextDigit;
            if (nextNumber <= limit) {
                generateLexicalNumbers(nextNumber, limit, result);
            }
            else    break;
        }
    }

};