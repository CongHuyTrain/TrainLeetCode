#pragma once
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        vector<vector<int>> p(grid.size(), vector<int>(grid[0].size()));
        int total = 1, n = grid.size(), m = grid[0].size();
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                p[i][j] = total;
                total *= (grid[i][j] % 12345);
                total %= 12345;
            }
        }
        total = 1;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                p[i][j] = (p[i][j] * total) % 12345;
                total *= (grid[i][j] % 12345);
                total %= 12345;
            }
        }
        return p;
    }
};