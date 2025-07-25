#pragma once
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <numeric>
using namespace std;
//3487. Maximum Unique Subarray Sum After Deletion
//Attempted
//Easy
//Topics
//premium lock icon
//Companies
//Hint
//You are given an integer array nums.
//
//You are allowed to delete any number of elements from nums without making it empty.After performing the deletions, select a subarray of nums such that :
//
//All elements in the subarray are unique.
//The sum of the elements in the subarray is maximized.
//Return the maximum sum of such a subarray.
//
//
//
//Example 1:
//
//Input: nums = [1, 2, 3, 4, 5]
//
//Output : 15
//
//Explanation :
//
//    Select the entire array without deleting any element to obtain the maximum sum.
//
//    Example 2 :
//
//    Input : nums = [1, 1, 0, 1, 1]
//
//    Output : 1
//
//    Explanation :
//
//    Delete the element nums[0] == 1, nums[1] == 1, nums[2] == 0, and nums[3] == 1. Select the entire array[1] to obtain the maximum sum.
//
//    Example 3 :
//
//    Input : nums = [1, 2, -1, -2, 1, 0, -1]
//
//    Output : 3
//
//    Explanation :
//
//    Delete the elements nums[2] == -1 and nums[3] == -2, and select the subarray[2, 1] from[1, 2, 1, 0, -1] to obtain the maximum sum.
//class Solution {
//public:
//    int maxSum(vector<int>& nums) {
//        unordered_map<int, bool> check;
//        bool start = false;
//        int result = 0;
//		for (int i = 0; i < nums.size(); i++) { // iterate through the array
//            if (nums[i] > 0) { 
//                if (check[nums[i]] == false) {
//                    if (result <= 0)  result = 0; // if result is negative, reset it to 0
//					else result += nums[i]; // add the positive number to the result
//                    check[nums[i]] = true;
//					start = true; // start is true for first else.
//                }
//            }
//            else {
//				if (start == false) { // array is all negative
//                    result = nums[i];
//                    start = true;
//                }
//                else    result = max(result, nums[i]);
//            }
//        }
//        return result;
//    }
//};
// Time Complexity: O(n), where n is the number of elements in the input array.
// Space Complexity: O(n), where n is the number of unique elements in the input array.
class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> positiveNumsSet;
        for (int num : nums) {
            if (num > 0) {
                positiveNumsSet.emplace(num);
            }
        }
        if (positiveNumsSet.empty()) {
            return *max_element(nums.begin(), nums.end());
        }
        return accumulate(positiveNumsSet.begin(), positiveNumsSet.end(), 0); // tính tuần tự từ giá trị bắt đầu = 0
    }
};
