<<<<<<< HEAD
﻿#pragma once
#include"L.h"
class Solution {
public:
    /*169
    Given an array nums of size n, return the majority element.

        The majority element is the element that appears more than ⌊n / 2⌋ times.You may assume that the majority element always exists in the array.



        Example 1:

Input: nums = [3, 2, 3]
Output : 3
Example 2 :

    Input : nums = [2, 2, 1, 1, 1, 2, 2]
    Output : 2*/
    int majorityElement(vector<int>& nums) {
        map<int, int> storCount; // map to storage count
        for (int i = 0; i < nums.size(); i++) {
            storCount[nums[i]]++; // count appear about?
            if (storCount[nums[i]] > nums.size() / 2) return nums[i]; // check if it apears over size/2.
        }
        return -1; // if not
    }
=======
﻿#pragma once
#include"L.h"
class Solution {
public:
    /*169
    Given an array nums of size n, return the majority element.

        The majority element is the element that appears more than ⌊n / 2⌋ times.You may assume that the majority element always exists in the array.



        Example 1:

Input: nums = [3, 2, 3]
Output : 3
Example 2 :

    Input : nums = [2, 2, 1, 1, 1, 2, 2]
    Output : 2*/
    int majorityElement(vector<int>& nums) {
        map<int, int> storCount; // map to storage count
        for (int i = 0; i < nums.size(); i++) {
            storCount[nums[i]]++; // count appear about?
            if (storCount[nums[i]] > nums.size() / 2) return nums[i]; // check if it apears over size/2.
        }
        return -1; // if not
    }
>>>>>>> ccfc2d41cc8ed0575db2cca47d1d2f8d82bb3b45
};