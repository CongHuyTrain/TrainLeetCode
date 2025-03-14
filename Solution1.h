<<<<<<< HEAD
#pragma once
#include<iostream>
#include<unordered_map>
using namespace std;
//1. Two Sum
//Solved
//Easy
//Topics
//Companies
//Hint
//Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
//
//You may assume that each input would have exactly one solution, and you may not use the same element twice.
//
//You can return the answer in any order.
//
//
//
//Example 1:
//
//Input: nums = [2, 7, 11, 15], target = 9
//Output : [0, 1]
//Explanation : Because nums[0] + nums[1] == 9, we return[0, 1].
//Example 2 :
//
//    Input : nums = [3, 2, 4], target = 6
//    Output : [1, 2]
//    Example 3 :
//
//    Input : nums = [3, 3], target = 6
//    Output : [0, 1]
//class Solution {
//public:
//    vector<int> twoSum(vector<int>& nums, int target) {
//        for (int i = 0; i < nums.size() - 1; i++) {
//            for (int j = i + 1; j < nums.size(); j++) {
//                if (nums[i] + nums[j] == target) {
//                    return { i, j };
//                }
//            }
//        }
//        return {};
//    }
//};
// the faster is use hashmap
// the porpose of function is find a pair that is total == target, and return local of pair.
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numCount;
        for (int i = 0; i < nums.size(); i++) {
            if (numCount.find(target - nums[i]) != numCount.end()) { //if exit a num that + nums[i] = target then return.
                return { numCount[target - nums[i]], i };
            }
            numCount[nums[i]] = i;
        }
        return {};
    }
=======
#pragma once
#include<iostream>
#include<unordered_map>
using namespace std;
//1. Two Sum
//Solved
//Easy
//Topics
//Companies
//Hint
//Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
//
//You may assume that each input would have exactly one solution, and you may not use the same element twice.
//
//You can return the answer in any order.
//
//
//
//Example 1:
//
//Input: nums = [2, 7, 11, 15], target = 9
//Output : [0, 1]
//Explanation : Because nums[0] + nums[1] == 9, we return[0, 1].
//Example 2 :
//
//    Input : nums = [3, 2, 4], target = 6
//    Output : [1, 2]
//    Example 3 :
//
//    Input : nums = [3, 3], target = 6
//    Output : [0, 1]
//class Solution {
//public:
//    vector<int> twoSum(vector<int>& nums, int target) {
//        for (int i = 0; i < nums.size() - 1; i++) {
//            for (int j = i + 1; j < nums.size(); j++) {
//                if (nums[i] + nums[j] == target) {
//                    return { i, j };
//                }
//            }
//        }
//        return {};
//    }
//};
// the faster is use hashmap
// the porpose of function is find a pair that is total == target, and return local of pair.
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numCount;
        for (int i = 0; i < nums.size(); i++) {
            if (numCount.find(target - nums[i]) != numCount.end()) { //if exit a num that + nums[i] = target then return.
                return { numCount[target - nums[i]], i };
            }
            numCount[nums[i]] = i;
        }
        return {};
    }
>>>>>>> ccfc2d41cc8ed0575db2cca47d1d2f8d82bb3b45
};