#pragma once
#include"L.h"
/*35. Search Insert Position
Solved
Easy
Topics
Companies
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1
Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4
 

Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums contains distinct values sorted in ascending order.
-104 <= target <= 104*/
class index_of_target {
public:
    int searchInsert(vector<int>& nums, int target) {
        int index = -1; 
        if (nums[nums.size() - 1] < target) // case vector no value > target
            return nums.size();
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= target) { //case value >=  target, > mean it's a position that target need in.
                index = i;
                break;
            }
        }
        return index; //return position
    }
};

