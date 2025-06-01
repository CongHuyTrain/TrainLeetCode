#pragma once
#include<vector>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int, int>> storage;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == 0)   storage.push_back(make_pair(i, j));
            }
        }
        for (int i = 0; i < storage.size(); i++) {
            int local = storage[i].first;
            int localin = storage[i].second;
            for (int j = 0; j < matrix[local].size(); j++) {
                matrix[local][j] = 0;
            }
            for (int j = 0; j < matrix.size(); j++) {
                matrix[j][localin] = 0;
            }
        }
    }
};