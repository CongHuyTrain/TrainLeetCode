#pragma once
#include<vector>
#include <algorithm>
using namespace std;
//56. Merge Intervals
//Solved
//Medium
//Topics
//Companies
//Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non - overlapping intervals that cover all the intervals in the input.
//
//
//
//Example 1:
//
//Input: intervals = [[1, 3], [2, 6], [8, 10], [15, 18]]
//Output : [[1, 6], [8, 10], [15, 18]]
//Explanation : Since intervals[1, 3] and [2, 6] overlap, merge them into[1, 6].
//Example 2 :
//
//    Input : intervals = [[1, 4], [4, 5]]
//    Output : [[1, 5]]
//    Explanation : Intervals[1, 4] and [4, 5] are considered overlapping.
//
//
//        Constraints :
//
//        1 <= intervals.length <= 104
//        intervals[i].length == 2
//        0 <= starti <= endi <= 104
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        int startNow = -1, endNow = -1;
        sort(intervals.begin(), intervals.end());
        for (auto& interval : intervals) {
            int start = interval[0], end = interval[1];
            if (start > endNow) {
                if (endNow != -1) {
                    result.push_back({ startNow, endNow });
                }
                endNow = end;
                startNow = start;
            }
            else {
                if (endNow < end)    endNow = end;
            }
        }
        if (endNow != -1) {
            result.push_back({ startNow, endNow });
        }
        return result;
    }
};