#pragma once
#include<unordered_map>
#include<vector>
using namespace std;
//75. Sort Colors
//Solved
//Medium
//Topics
//Companies
//Hint
//Given an array nums with n objects colored red, white, or blue, sort them in - place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
//
//We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
//
//You must solve this problem without using the library's sort function.
//
//
//
//Example 1:
//
//Input: nums = [2, 0, 2, 1, 1, 0]
//Output : [0, 0, 1, 1, 2, 2]
//Example 2 :
//
//    Input : nums = [2, 0, 1]
//    Output : [0, 1, 2]
//
//
//    Constraints :
//
//    n == nums.length
//    1 <= n <= 300
//    nums[i] is either 0, 1, or 2.

// way for easy
void sortColors(vector<int>& nums) {
    unordered_map<int, int > count;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 0)    count[0]++;
        else if (nums[i] == 1)   count[1]++;
        else    count[2]++;
    }
    for (int i = 0; i < count[0]; i++) {
        nums[i] = 0;
    }
    for (int i = count[0]; i < count[0] + count[1]; i++) {
        nums[i] = 1;
    }
    for (int i = count[0] + count[1]; i < nums.size(); i++) {
        nums[i] = 2;
    }
}
