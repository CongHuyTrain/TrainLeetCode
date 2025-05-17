#pragma once
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& w, vector<int>& g) {
        vector<string> result;
        result.push_back(w[0]);
        int flat = g[0];
        for (int i = 1; i < g.size(); i++) {
            if (g[i] != flat) {
                result.push_back(w[i]);
                flat = g[i];
            }
        }
        return result;
    }
};