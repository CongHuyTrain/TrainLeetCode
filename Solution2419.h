#pragma once
#include <vector>   
#include <algorithm>
using namespace std;
//2419. Longest Subarray With Maximum Bitwise AND
//Solved
//Medium
//You are given an integer array nums of size n.
//Consider a non - empty subarray from nums that has the maximum possible bitwise AND.
//In other words, let k be the maximum value of the bitwise AND of any subarray of nums.
// Then, only subarrays with a bitwise AND equal to k should be considered.
//Return the length of the longest such subarray.
//The bitwise AND of an array is the bitwise AND of all the numbers in it.
//A subarray is a contiguous sequence of elements within an array.
//Example 1:
//
//Input: nums = [1, 2, 3, 3, 2, 2]
//Output : 2
//Explanation :
//    The maximum possible bitwise AND of a subarray is 3.
//    The longest subarray with that value is[3, 3], so we return 2.
//    Example 2 :
//
//    Input : nums = [1, 2, 3, 4]
//    Output : 1
//    Explanation :
//    The maximum possible bitwise AND of a subarray is 4.
//    The longest subarray with that value is[4], so we return 1.
//    Constraints :
//    1 <= nums.length <= 10^5
//    1 <= nums[i] <= 10^6
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());//tìm phần tử lớn nhất trong vector nums. 
        //Hàm này trả về iterator trỏ đến phần tử lớn nhất.dùng dấu* để lấy giá trị mà iterator đó trỏ tới.
        int cons = 1, res = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] && nums[i] == maxi) cons++;
            else cons = 1;
            res = max(res, cons);
        }
        return res;
    }
};