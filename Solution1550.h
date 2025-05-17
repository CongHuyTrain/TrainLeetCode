#pragma once
#include<vector>
using namespace std;
//1550. Three Consecutive Odds
//Solved
//Easy
//Topics
//Companies
//Hint
//Given an integer array arr, return true if there are three consecutive odd numbers in the array.Otherwise, return false.
//Example 1:
//Input: arr = [2, 6, 4, 1]
//Output : false
//Explanation : There are no three consecutive odds.
//Example 2 :
//    Input : arr = [1, 2, 34, 3, 4, 5, 7, 23, 12]
//    Output : true
//    Explanation : [5, 7, 23] are three consecutive odds.
//    Constraints :
//    1 <= arr.length <= 1000
//    1 <= arr[i] <= 1000

// function try to check if exist 3 consecutive odd numbers, return true, else return false;
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int count = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (count > 2)   return true;
            else if (arr[i] % 2 != 0)    count++;
            else    count = 0;
        }
        return count > 2 ? true : false;
    }
};