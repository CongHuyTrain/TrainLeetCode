#pragma once
#include"L.h"
////wrong answer:
//class Solution {
//public:
//    int searchpath(vector<int> nums, int start, int end, int target) {
//        if (start > end) {
//            return -1;
//        }
//        int mid = start + (end - start) / 2; // Prevent potential overflow
//        if (target == nums[mid]) {
//            return mid;
//        }
//        else if (target < nums[mid]) {
//            return searchpath(nums, start, mid - 1, target);
//        }
//        else {
//            return searchpath(nums, mid + 1, end, target);
//        }
//    }
//    int search(vector<int>& nums, int target) {
//        int length = nums.size();
//        int result = -1;
//        if (target < nums[0]) {
//            result = searchpath(nums, length - (nums[length - 1] + 1), length - 1, target);
//        }
//        else {
//            result = searchpath(nums, 0, length - (nums[length - 1] + 1), target);
//        }
//        return result;
//    }
//};
//33
class Solution {
public:
    int searchpathleft(vector<int> nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                return i;
            }
        }
        return -1;
    }
    int searchpathright(vector<int> nums, int target) {
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] == target) {
                return i;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int result = -1;
        int start = 0;
        int end = nums.size();
        if (nums[0] == target)   return 0;
        else if (nums[0] < target) {
            result = searchpathright(nums, target);
        }
        else {
            result = searchpathleft(nums, target);
        }
        return result;
    }
};