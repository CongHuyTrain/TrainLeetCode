#pragma once
#include <vector>
using namespace std;
//1493. Longest Subarray of 1's After Deleting One Element
//Solved
//Medium
//Given a binary array nums, you should delete one element from it.
//Return the size of the longest non - empty subarray containing only 1's in the resulting array. 
//Return 0 if there is no such subarray.
//Example 1:
//Input: nums = [1, 1, 0, 1]
//Output : 3
//Explanation : After deleting the number in position 2, [1, 1, 1] contains 3 numbers with value of 1's.
//Example 2 :
//    Input : nums = [0, 1, 1, 1, 0, 1, 1, 0, 1]
//    Output : 5
//    Explanation : After deleting the number in position 4, [0, 1, 1, 1, 1, 1, 0, 1] longest subarray with value of 1's is [1,1,1,1,1].
//    Example 3 :
//    Input : nums = [1, 1, 1]
//    Output : 2
//    Explanation : You must delete one element.
//    Constraints
//    1 <= nums.length <= 105
//    nums[i] is either 0 or 1.
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int sub1 = 0, sub2 = 0, result = 0;
		//sub1 is the first subarray of 1's, sub2 is the second subarray of 1's
        for (int i = 0; i < nums.size(); i++) { // loop 0
			if (nums[i] == 0)    continue; // skip 0's
			while (i < nums.size() && nums[i] == 1) { //loop 1-> count first subarray of 1's
                sub1++;
                i++;
            }
			i++; // skip the 0 between two subarrays of 1's
			while (i < nums.size() && nums[i] == 1) { // loop 2 -> count second subarray of 1's
                sub2++;
                i++;
            }
			result = max(result, sub1 + sub2); // update result
			i = i - sub2 - 1;// reset i to the position of the 0, minus 1 because i have been incremented in the loop 2
            sub1 = 0;
            sub2 = 0;
        }
		return nums.size() == result ? result - 1 : result;// if the array contains all 1's, we need to delete one element, so return result - 1
    }
};