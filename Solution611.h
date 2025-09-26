#pragma once
#include <vector>
#include <algorithm>
using namespace std;
//611. Valid Triangle Number
//Solved
//Medium
//Given an integer array nums, 
//return the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.
//Example 1:
//Input: nums = [2, 2, 3, 4]
//Output : 3
//Explanation : Valid combinations are :
//2, 3, 4 (using the first 2)
//2, 3, 4 (using the second 2)
//2, 2, 3
//Example 2 :
//    Input : nums = [4, 2, 3, 4]
//    Output : 4
//    Constraints :
//    1 <= nums.length <= 1000
//    0 <= nums[i] <= 1000

// brute force solution
//class Solution {
//public:
//    int triangleNumber(vector<int>& nums) {
//        if (nums.size() < 3) return 0;
//        int start = 0, result = 0;
//        sort(nums.begin(), nums.end());
//        while (nums[start] == 0 && start < nums.size())  start++;
//        for (int i = start; i < nums.size() - 2; i++) {
//            for (int j = i + 1; j < nums.size() - 1; j++) {
//                for (int k = j + 1; k < nums.size(); k++) {
//                    if (nums[i] + nums[j] > nums[k]) result++;
//                }
//            }
//        }
//        return result;
//    }
//};
// smart
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size(), result = 0;
        sort(nums.begin(), nums.end());
        int left = 0, right = n - 2;
        for (int i = n - 1; i >= 2; i--) {
            int left = 0, right = i - 1;
            while (left < right) { 
                if (nums[i] < nums[right] + nums[left]) {
                    result += right - left;
                    right--;
					// when find a valid, we continue at that left( becasue all element < left always are invalid)
                }
                else    left++;
            }
        }
        return result;
    }
};