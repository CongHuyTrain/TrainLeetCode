#pragma once
#include<unordered_map>
using namespace std;
//219. Contains Duplicate II
//Solved
//Easy
//Topics
//Companies
//Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.
//
//
//
//Example 1:
//
//Input: nums = [1, 2, 3, 1], k = 3
//Output : true
//Example 2 :
//
//	Input : nums = [1, 0, 1, 1], k = 1
//	Output : true
//	Example 3 :
//
//	Input : nums = [1, 2, 3, 1, 2, 3], k = 2
//	Output : false
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> storage;
        // count duplicate 
        for (int i = 0; i < nums.size(); i++) {
            storage[nums[i]]++;
        }
        for (int i = 0; i < nums.size() - 1; i++) {
            if (storage[nums[i]] <= 1)   continue; // check, if element not exit duplicate, continue.
            for (int j = i + 1; j < i + k + 1; j++) {
                if (nums[i] == nums[j])    return true;
            }
        }
        // vd   1, 2, 3, 1, 2, 3
        //      i      | 
        //         j  
        //            j
        return false;
    }
};