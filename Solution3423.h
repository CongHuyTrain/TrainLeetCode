#pragma once
#include <algorithm>
#include<vector>
using namespace std;
//3423. Maximum Difference Between Adjacent Elements in a Circular Array
//Solved
//Easy
//Topics
//premium lock icon
//Companies
//Hint
//Given a circular array nums, find the maximum absolute difference between adjacent elements.
//
//Note: In a circular array, the first and last elements are adjacent.
//
//
//
//Example 1 :
//
//	Input : nums = [1, 2, 4]
//
//	Output : 3
//
//	Explanation :
//
//	Because nums is circular, nums[0] and nums[2] are adjacent.They have the maximum absolute difference of | 4 - 1 | = 3.
//
//	Example 2 :
//
//	Input : nums = [-5, -10, -5]
//
//	Output : 5
//
//	Explanation :
//
//	The adjacent elements nums[0] and nums[1] have the maximum absolute difference of | -5 - (-10) | = 5.
//
//
//
//Constraints:
//
//2 <= nums.length <= 100
//- 100 <= nums[i] <= 100
class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int result = abs(nums[0] - nums[nums.size() - 1]);
        for (int i = 1; i < nums.size(); i++) {
            result = max(result, abs(nums[i] - nums[i - 1]));
        }
        return result;
    }
};