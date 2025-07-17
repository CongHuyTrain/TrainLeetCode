#pragma once
#include<iostream>
#include<vector>
using namespace std;
//3202. Find the Maximum Length of Valid Subsequence II
//Solved
//Medium
//Topics
//premium lock icon
//Companies
//Hint
//You are given an integer array nums and a positive integer k.
//A subsequence sub of nums with length x is called valid if it satisfies :
//
//(sub[0] + sub[1]) % k == (sub[1] + sub[2]) % k == ... == (sub[x - 2] + sub[x - 1]) % k.
//Return the length of the longest valid subsequence of nums.
//
//
//Example 1:
//
//Input: nums = [1, 2, 3, 4, 5], k = 2
//
//Output : 5
//
//Explanation :
//
//    The longest valid subsequence is[1, 2, 3, 4, 5].
//
//    Example 2 :
//
//    Input : nums = [1, 4, 2, 3, 1, 4], k = 3
//
//    Output : 4
//
//    Explanation :
//
//    The longest valid subsequence is[1, 4, 1, 4].
class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int result = 2; // defalt length
        for (int i = 0; i < k; i++) { // loot 1: answer module of each num when mod k
            vector<int> dp(k, 0); // dp storage like...
            // for example, we have arr[num1, num2, num3] k = 3
            // num1 % k = a, when a + ? = i = 0, a + ? = i =1, a + ?= i= 2
            // how we know ?
            // so, we need a loot2 to find 'true love' to plus == i of loot1.
            // and dp is storage number of element like: i - a = 'true love', so at local true love, it's storage number the last of continue true love of her, we take that number and +1.
            for (int j = 0; j < nums.size(); j++) {
                int mod = nums[j] % k; // it's a, a is mod we have, and then we find what we lack to == i.
                int truelove = (i - mod + k) % k; // true love can be negative, so we + k and %k.
                dp[mod] = dp[truelove] + 1; // we storage continue true love of module
            }
            for (int a : dp) {
                result = max(result, a);
            }
        }
        return result;
    }
};