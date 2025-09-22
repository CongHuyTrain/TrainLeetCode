#pragma once
#include<vector>
#include<unordered_map>
using namespace std;
//3005. Count Elements With Maximum Frequency
//Solved
//Easy
//You are given an array nums consisting of positive integers.
//Return the total frequencies of elements in nums such that those elements all have the maximum frequency.
//The frequency of an element is the number of occurrences of that element in the array.
//Example 1:
//Input: nums = [1, 2, 2, 3, 1, 4]
//Output : 4
//Explanation : The elements 1 and 2 have a frequency of 2 which is the maximum frequency in the array.
//So the number of elements in the array with maximum frequency is 4.
//Example 2 :
//    Input : nums = [1, 2, 3, 4, 5]
//    Output : 5
//    Explanation : All elements of the array have a frequency of 1 which is the maximum.
//    So the number of elements in the array with maximum frequency is 5.
//    Constraints :
//    1 <= nums.length <= 100
//    1 <= nums[i] <= 100
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> storage;
        int max = 0, result;
        for (int i = 0; i < nums.size(); i++) {
            storage[nums[i]]++;
            if (storage[nums[i]] == max) {
                result += max;
            }
            else if (storage[nums[i]] > max) {
                max = storage[nums[i]];
                result = max;
            }
            else    continue;
        }
        return result;
    }
};
// code other person:
//class Solution {
//public:
//    int maxFrequencyElements(vector<int>& nums) {
//        uint8_t freq[101] = { 0 };
//        uint8_t max = 0, res = 0;
//        for (int n : nums) {
//            uint8_t f = ++freq[n];
//            if (f > max) {
//                max = f;
//                res = f;
//            }
//            else if (f == max)
//                res += f;
//        }
//        return res;
//    }
//};
// same logic but use array instead of map