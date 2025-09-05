#pragma once
//2749. Minimum Operations to Make the Integer Zero
//Solved
//Medium
//Topics
//premium lock icon
//Companies
//Hint
//You are given two integers num1 and num2.
//
//In one operation, you can choose integer i in the range[0, 60] and subtract 2i + num2 from num1.
//
//Return the integer denoting the minimum number of operations needed to make num1 equal to 0.
//
//If it is impossible to make num1 equal to 0, return -1.
//
//
//
//Example 1:
//
//Input: num1 = 3, num2 = -2
//Output : 3
//Explanation : We can make 3 equal to 0 with the following operations :
//-We choose i = 2 and subtract 22 + (-2) from 3, 3 - (4 + (-2)) = 1.
//- We choose i = 2 and subtract 22 + (-2) from 1, 1 - (4 + (-2)) = -1.
//- We choose i = 0 and subtract 20 + (-2) from - 1, (-1) - (1 + (-2)) = 0.
//It can be proven, that 3 is the minimum number of operations that we need to perform.
//Example 2 :
//
//    Input : num1 = 5, num2 = 7
//    Output : -1
//    Explanation : It can be proven, that it is impossible to make 5 equal to 0 with the given operation.
//
//
//    Constraints :
//
//    1 <= num1 <= 109
//    - 109 <= num2 <= 109
/*class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        unordered_map<int, long long>dp;
        for(int i = 0; i <= 60 && (2^i) + num2 <= num1;i++){
                dp[i] = (2^i) + num2;
        }
        int result = 0;
        while(num1 > 1 + num2){
            int nearNum = 1 + num2;
            for(int i = dp.size()-1; i >=0 ;i++){
                if(dp[i] <= num1){
                    nearNum = dp[i];
                    break;
                }
            }
            num1 -= nearNum;
            result++;
            if(num1 < 1 + num2)   return -1;
            else if(num1 == 0)   return result;
        }
        return 1;
    }
};*/
class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for (int k = 1; k <= 60; k++) {
            long long x = (long long)num1 - (long long)k * num2;
            if (x < 0) break;
            int bitCount = __builtin_popcountll(x);
            if (bitCount <= k && k <= x) return k;
        }
        return -1;
    }
};