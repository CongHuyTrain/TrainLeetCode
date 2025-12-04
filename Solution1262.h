#pragma once
#include <vector>
using namespace std;

//1262. Greatest Sum Divisible by Three
//Solved
//Medium
//Given an integer array nums, return the maximum possible sum of elements of the array such that it is divisible by three.
//Example 1:
//Input: nums = [3, 6, 5, 1, 8]
//Output : 18
//Explanation : Pick numbers 3, 6, 1 and 8 their sum is 18 (maximum sum divisible by 3).
//Example 2 :
//    Input : nums = [4]
//    Output : 0
//    Explanation : Since 4 is not divisible by 3, do not pick any number.
//    Example 3 :
//    Input : nums = [1, 2, 3, 4, 4]
//    Output : 12
//    Explanation : Pick numbers 1, 3, 4 and 4 their sum is 12 (maximum sum divisible by 3).
//    Constraints :
//    1 <= nums.length <= 4 * 10^4
//    1 <= nums[i] <= 10^4
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int result = 0;
        // create to find a smallest and smaller than it of 1 and 2
        // because if %3 = 1 -> we can minus 1 or minus two 2, ...  
        int min1 = INT_MAX, min11 = INT_MAX;
        int min2 = INT_MAX, min22 = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            int a = nums[i];
            result += a; // add it and
            if (a % 3 == 1) { // if remainder == 1
                if (a < min1) { //  check if < min1
                    min11 = min1; // step back 
                    min1 = a;
                }
                else if (a < min11) { // else if < min11
                    min11 = a;  // replace it
                }
            }
            else if (a % 3 == 2) {
                if (a < min2) {
                    min22 = min2;
                    min2 = a;
                }
                else if (a < min22) {
                    min22 = a;
                }
            }
        }
        if (result % 3 == 0) return result;
        else if (result % 3 == 1) {
            int element2 = (min2 == INT_MAX || min22 == INT_MAX) ? INT_MAX : min2 + min22;
            return result - min(min1, element2);
        }
        else {
            int element1 = (min1 == INT_MAX || min11 == INT_MAX) ? INT_MAX : min1 + min11;
            return result - min(min2, element1);
        }
    }
};