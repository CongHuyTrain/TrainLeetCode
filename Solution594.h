#pragma once
#include <algorithm>
#include<vector>
using namespace std;
/*594. Longest Harmonious Subsequence
Solved
Easy
We define a harmonious array as an array where the difference between its maximum value and its minimum value is exactly 1.
Given an integer array nums, return the length of its longest harmonious subsequence among all its possible subsequences.

Example 1:
Input: nums = [1,3,2,2,5,2,3,7]
Output: 5
Explanation:
The longest harmonious subsequence is [3,2,2,2,3].

Example 2:
Input: nums = [1,2,3,4]
Output: 2
Explanation:
The longest harmonious subsequences are [1,2], [2,3], and [3,4], all of which have a length of 2.
Example 3:
Input: nums = [1,1,1,1]
Output: 0
Explanation:
No harmonic subsequence exists.
Constraints:
1 <= nums.length <= 2 * 10^4
-10^9 <= nums[i] <= 10^9*/
class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size(), left = 0, right = 0, count = 0, maxSecond = -1; //maxSecond to mark location of first element max of subvector 
        int result = 0;
        sort(nums.begin(), nums.end());
        while (right < n) {
            if (nums[right] - nums[left] < 1) { // in case two element is resemble
                count++;
                right++;
                maxSecond = right;//we guess the next value is the first element max
            }
            else if (nums[right] - nums[left] == 1) { // in case normal
                count++;
                right++;
                result = max(result, count);
            }
            else { // the element is biger left.
                count = 0;
                left = maxSecond;
                right = maxSecond;
            }
        }
        return result;
    }
};
//
//class Solution {
//public:
//    int findLHS(vector<int>& nums) {
//        sort(nums.begin(), nums.end());
//        int j = 0, maxLength = 0;
//
//        for (int i = 0; i < nums.size(); ++i) {
//            while (nums[i] - nums[j] > 1) { // when i is go far more it
//                ++j;
//            }
//            if (nums[i] - nums[j] == 1) {
//                maxLength = max(maxLength, i - j + 1); 
//            }
//        }
//        return maxLength;
//    }
//};