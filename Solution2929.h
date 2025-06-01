#pragma once
#include <algorithm>
using namespace std;
//2929. Distribute Candies Among Children II
//Solved
//Medium
//You are given two positive integers n and limit.
//Return the total number of ways to distribute n candies among 3 children such that no child gets more than limit candies.
//Example 1:
//Input: n = 5, limit = 2
//Output : 3
//Explanation : There are 3 ways to distribute 5 candies such that no child gets more than 2 candies : 
// (1, 2, 2), (2, 1, 2) and (2, 2, 1).
//Example 2 :
//    Input : n = 3, limit = 3
//    Output : 10
//    Explanation : There are 10 ways to distribute 3 candies such that no child gets more than 3 candies : 
// (0, 0, 3), (0, 1, 2), (0, 2, 1), (0, 3, 0), (1, 0, 2), (1, 1, 1), (1, 2, 0), (2, 0, 1), (2, 1, 0) and (3, 0, 0).
//    Constraints :
//    1 <= n <= 10^6
//    1 <= limit <= 10^6
class Solution {
public:
    long long distributeCandies(int n, int limit) { // n is the candies we must distribute all of them. Limit is a largest one children can be take.
        long long result = 0;
        for (int i = 0; i <= min(limit, n); i++) { // we load through i case( first number of 3 numbers
            if (limit * 2 < n-i) continue; // pass case like 0 if first number =0, number 2 and 3 must fulfill n. 
            //In short, it'll help pass case number 2 and 3 not fullfill n.
            result += 1 + min(limit, n - i) - max(n-i-limit, 0); // min is for number 2, we count number that can be match under limit
            // max is for number 3. It like we have case number 2, but some case we count that cannot do( because number 3 won't enough to fulfill n.
            // So, we minus for wrong case.
        }
        return result;
    }
};