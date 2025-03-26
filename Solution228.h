#pragma once
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.size() == 0)    return {};
        vector<string> result;
        string start = "";
        string end = "";
        int count = 0;
        for (int i = 0; i < nums.size() - 1; i++) { 
            if (nums[i + 1] - 1 != nums[i] && count == 0) {//nums[i + 1] - 1 != nums[i] because int is 32 bit=)))
                result.push_back(to_string(nums[i]));
            }
            else if (nums[i + 1] - 1 != nums[i] && count != 0) {
                result.push_back(start + "->" + end);
                count = 0;
            }
            else if (nums[i + 1] - 1 == nums[i] && count == 0) {
                start = to_string(nums[i]);
                end = to_string(nums[i + 1]);
                count++;
            }
            else {
                end = to_string(nums[i + 1]);
                count++;
            }
        }
        if (end != to_string(nums[nums.size() - 1]))  result.push_back(to_string(nums[nums.size() - 1]));
        else {
            result.push_back(start + "->" + end);
        }
        return result;
    }
};