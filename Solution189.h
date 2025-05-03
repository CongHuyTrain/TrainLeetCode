#pragma once
#include<vector>
using namespace std;
//189. Rotate Array
//Solved
//Medium
//Topics
//Companies
//Hint
//Given an integer array nums, rotate the array to the right by k steps, where k is non - negative.
//
//
//
//Example 1:
//
//Input: nums = [1, 2, 3, 4, 5, 6, 7], k = 3
//Output : [5, 6, 7, 1, 2, 3, 4]
//Explanation :
//    rotate 1 steps to the right : [7, 1, 2, 3, 4, 5, 6]
//    rotate 2 steps to the right : [6, 7, 1, 2, 3, 4, 5]
//    rotate 3 steps to the right : [5, 6, 7, 1, 2, 3, 4]
//    Example 2 :
//
//    Input : nums = [-1, -100, 3, 99], k = 2
//    Output : [3, 99, -1, -100]
//    Explanation :
//    rotate 1 steps to the right : [99, -1, -100, 3]
//    rotate 2 steps to the right : [3, 99, -1, -100]
class Solution {
public:
    void reserve(int left, int right, vector<int>& nums) {
        int temp;
        while (left < right) {
            temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
            left++; right--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        if (k > nums.size()) k = k % nums.size(); // situation that k>nums.size
        reserve(0, nums.size() - 1, nums);
        reserve(0, k - 1, nums);
        reserve(k, nums.size() - 1, nums);
    }
};