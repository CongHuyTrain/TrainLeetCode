#pragma once
#include"L.h"
/*You are given a large integer represented as an integer array digits, 
where each digits[i] is the ith digit of the integer.
The digits are ordered from most significant to least significant in left-to-right order.
The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.

 

Example 1:

Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].
Example 2:

Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
Incrementing by one gives 4321 + 1 = 4322.
Thus, the result should be [4,3,2,2].
Example 3:

Input: digits = [9]
Output: [1,0]
Explanation: The array represents the integer 9.
Incrementing by one gives 9 + 1 = 10.
Thus, the result should be [1,0].*/
class addonetointvector {
public:
    vector<int> plusOne(vector<int>& digits) {
        int number = 0;
        for (int i = 0; i <= digits.size() - 1; i++) { //check if vector all 9
            if (digits[i] == 9) {
                number++;
            }
        }
        if (number == digits.size()) { //if true then 0 = 1 and after 0 and push 0
            digits[0] = 1;
            for (int i = 1; i <= digits.size() - 1; i++) {
                digits[i] = 0;
            }
            digits.push_back(0);
            return digits;
        }
        number = 1;
        int i = digits.size() - 1;
        while (number != 0 && i >= 0) {
            if (digits[i] == 9) {
                digits[i] = 0;
                i--;
            }
            else {
                digits[i] = digits[i] + 1;
                number = 0;
            }
        }
        return digits;
    }
};
/* code chay nhanh
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int addition = 0;
        auto right = digits.end() - 1;
        while(right >= digits.begin() && *right == 9){
            *(right--) = 0;
        }
        if (right+1 == digits.begin()) digits.insert(digits.begin(), 1); 
        else (*right)+=1;
        return digits;
    }
};*/
