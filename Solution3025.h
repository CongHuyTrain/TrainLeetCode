#pragma once
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int result = 0;
        sort(points.begin(), points.end());
        // sort follow x.
        // * Start a pointA:
        // case 1: consider a point that have ((x >= xA && y <= yA)&& existPoint(x, xA, y, yA))
        for (int i = 0; i < points.size() - 1; i++) {
            int xA = points[i][0], yA = points[i][1];
            for (int j = i + 1; j < points.size(); j++) {
                int x = points[j][0], y = points[j][1];
                if (x >= xA && y <= yA && !existPoint(points, i, j)) result++;
            }
        }
        return result;
    }
    bool existPoint(vector<vector<int>>& points, int localA, int local) {
        int start = localA;
        while (start < points.size() && points[start][0] < points[local][0]) {
            if (start == local)  continue;
            if (points[start][1] <= points[localA][1])   return true;
            start++;
        }
        return false;
    }
};