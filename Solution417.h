#pragma once
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> direct = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> result;
        const int m = heights.size(), n = heights[0].size();
        vector< vector<bool>> pacific(m, vector<bool>(n, false));
        vector< vector<bool>> atlantic(m, vector<bool>(n, false));
        for (int i = 0; i < n; i++) dfs(0, i, heights, pacific);
        for (int i = 0; i < m; i++) dfs(i, 0, heights, pacific);
        for (int i = 0; i < n; i++) dfs(m - 1, i, heights, atlantic);
        for (int i = 0; i < m; i++) dfs(i, n - 1, heights, atlantic);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j])    result.push_back({ i, j });
            }
        }
        return result;
    }
    void dfs(int i, int j, vector<vector<int>>& heights, vector<vector<bool>>& visited) {
        visited[i][j] = true;
        const int m = heights.size(), n = heights[0].size();
        for (auto& d : direct) {
            int x = i + d[0], y = j + d[1];
            if (x<0 || x>m - 1 || y<0 || y>n - 1 || visited[x][y] || heights[x][y] < heights[i][j]) continue;
            else    dfs(x, y, heights, visited);
        }
    }
};