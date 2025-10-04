#pragma once
#include <vector>
#include <queue> // for priority_queue
#include <tuple>
#include <iostream>
#include <algorithm>
using namespace std;
//407. Trapping Rain Water II
//Attempted
//Hard
//Given an m x n integer matrix heightMap representing the height of each unit cell in a 2D elevation map,
//return the volume of water it can trap after raining.
//Example 1:
//Input: heightMap = [[1, 4, 3, 1, 3, 2], [3, 2, 1, 3, 2, 4], [2, 3, 3, 2, 3, 1]]
//Output : 4
//Explanation : After the rain, water is trapped between the blocks.
//We have two small ponds 1 and 3 units trapped.
//The total volume of water trapped is 4.
//Example 2 :
//    Input : heightMap = [[3, 3, 3, 3, 3], [3, 2, 2, 2, 3], [3, 2, 1, 2, 3], [3, 2, 2, 2, 3], [3, 3, 3, 3, 3]]
//    Output : 10
//    Constraints :
//    m == heightMap.length
//    n == heightMap[i].length
//    1 <= m, n <= 200
//    0 <= heightMap[i][j] <= 2 * 10^4
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size(), n = heightMap[0].size();
		if (m < 3 || n < 3)   return 0; // cannot trap water if less than 3 rows or columns

        using T = tuple<int, int, int>; // fint=value, sint=row, tint = column
		// because to storage the smallest value and local first, then we can find neighbour easily
        priority_queue<T, vector<T>, greater<T>> storage;
		vector<vector<bool>> visited(m, vector<bool>(n, false)); // to mark visited cell
		// push all the border cell into the priority queue and mark them as visited
        for (int i = 0; i < m; i++) {
            storage.emplace(heightMap[i][0], i, 0); visited[i][0] = true;
            storage.emplace(heightMap[i][n - 1], i, n - 1); visited[i][n - 1] = true;
        }
        // same same
        for (int i = 1; i < n - 1; i++) {
            storage.emplace(heightMap[0][i], 0, i); visited[0][i] = true;
            storage.emplace(heightMap[m - 1][i], m - 1, i); visited[m - 1][i] = true;
        }

        int result = 0;
		// step array to find the neighbour easily
        int step[4][2] = { {1,0}, {-1, 0}, {0, 1}, {0, -1} }; // 10 up, -10 down, 01 right, 0-1 left

		while (!storage.empty()) { // until all the cell are visited
            auto [value, row, column] = storage.top(); storage.pop();
            for (auto& s : step) {
				// neighbour of row is exist four way( up, down, left, right)
				int neighbourRow = row + s[0], neighbourColumn = column + s[1]; // neighbour cell
				// if neighbour is out of bound or already visited, continue( we ignore it)
                if (neighbourRow < 0 || neighbourRow > m - 1 || neighbourColumn < 0 || neighbourColumn > n - 1 || visited[neighbourRow][neighbourColumn]) continue;
				visited[neighbourRow][neighbourColumn] = true; // if not, mark it as visited and process it
				int neighbourValue = heightMap[neighbourRow][neighbourColumn]; // get the neighbour value
				if (neighbourValue < value)  result += value - neighbourValue; // compare, if neighbour smaller, 
                //we can trap water( if you ask why, imagine we go from border to inside, the border is always higher
                //( because priority_queue), so we can trap water)
				storage.emplace(max(neighbourValue, value), neighbourRow, neighbourColumn); // push the neighbour into the queue
				// beacuse we all ready caculate the water of the neighbour, so we need to push the max value of itself and the border value( it becomes the new border)
            }
        }
        return result;
    }
};