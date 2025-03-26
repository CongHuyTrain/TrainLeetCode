#pragma once
#include<vector>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums, int value = 0) {
        if (value >= nums.size())    return true;
        if (nums[value] == 0)    return false;
        for (int i = nums[value]; i >= value; i--) {
            canJump(nums, i);
        }
        return false;
    }
};