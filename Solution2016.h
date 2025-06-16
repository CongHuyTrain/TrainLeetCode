#pragma once
#include <algorithm>
#include<vector>
#include<iostream>
using namespace std;
//2016. Maximum Difference Between Increasing Elements
//Solved
//Easy
//Topics
//premium lock icon
//Companies
//Hint
//Given a 0 - indexed integer array nums of size n, find the maximum difference between nums[i] and nums[j](i.e., nums[j] - nums[i]), such that 0 <= i < j < n and nums[i] < nums[j].
//
//    Return the maximum difference.If no such i and j exists, return -1.
//
//
//
//    Example 1:
//
//Input: nums = [7, 1, 5, 4]
//Output : 4
//Explanation :
//    The maximum difference occurs with i = 1 and j = 2, nums[j] - nums[i] = 5 - 1 = 4.
//    Note that with i = 1 and j = 0, the difference nums[j] - nums[i] = 7 - 1 = 6, but i > j, so it is not valid.
//    Example 2:
//
//Input: nums = [9, 4, 3, 2]
//Output : -1
//Explanation :
//    There is no i and j such that i < j and nums[i] < nums[j].
//    Example 3 :
//
//    Input : nums = [1, 5, 2, 10]
//    Output : 9
//    Explanation :
//    The maximum difference occurs with i = 0 and j = 3, nums[j] - nums[i] = 10 - 1 = 9.
//
//
//    Constraints :
//
//    n == nums.length
//    2 <= n <= 1000
//    1 <= nums[i] <= 109
// bruce force.
//class Solution {
//public:
//    int maximumDifference(vector<int>& nums) {
//        int result = -1;
//        for (int j = nums.size() - 1; j > 0; j--) {
//            for (int i = 0; i < j; i++) {
//                if (nums[j] - nums[i] > 0)  result = max(result, nums[j] - nums[i]);
//            }
//        }
//        return result;
//    }
//};
// faster, i used two poiter and little like dp, i mark left is shotest and right is largest at the moment.
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        vector<int> left(nums.size(), -1);
        vector<int> right(nums.size(), -1);
        int result = -1;
        left[0] = nums[0];
        right[nums.size() - 1] = nums[nums.size() - 1];
        for (int i = 1; i < nums.size(); i++) {
            left[i] = min(left[i - 1], nums[i]);
        }
        for (int i = nums.size() - 2; i >= 0; i--) {
            right[i] = max(right[i + 1], nums[i]);
        }
        for (int i = 0; i < nums.size(); i++) {
            if (right[i] - left[i] > 0)  result = max(result, right[i] - left[i]);
        }
        return result;
    }
};
// but this is...
// simple and also fast more than my code.
// you just find the shotest and if have a j that bigger it, then return max of pevious or now.
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int ans = -1, premin = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] > premin) {
                ans = max(ans, nums[i] - premin);
            }
            else {
                premin = nums[i];
            }
        }
        return ans;
    }
};