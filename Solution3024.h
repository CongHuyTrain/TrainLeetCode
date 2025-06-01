#pragma once
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    bool checkTriangle(vector<int>& nums) {
        if (nums[0] + nums[1] <= nums[2] || nums[0] + nums[2] <= nums[1] || nums[1] + nums[2] <= nums[0])    return false;
        return true;
    }
    string triangleType(vector<int>& nums) {
        if (nums[0] == nums[2] && nums[0] == nums[1]) return "equilateral";
        else {
            if (checkTriangle(nums)) {
                if (nums[0] == nums[2] || nums[0] == nums[1] || nums[1] == nums[2])   return "isosceles";
                else {
                    return "scalene";
                }
            }
        }
        return "none";
    }
};