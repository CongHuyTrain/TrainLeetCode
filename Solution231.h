#pragma once
//231. Power of Two
//Solved
//Easy
//Topics
//premium lock icon
//Companies
//Given an integer n, return true if it is a power of two.Otherwise, return false.
//
//An integer n is a power of two, if there exists an integer x such that n == 2x.
//
//
//
//Example 1:
//
//Input: n = 1
//Output : true
//Explanation : 20 = 1
//Example 2 :
//
//    Input : n = 16
//    Output : true
//    Explanation : 24 = 16
//    Example 3 :
//
//    Input : n = 3
//    Output : false
//
//
//    Constraints :
//
//    -231 <= n <= 231 - 1
//
//
//    Follow up : Could you solve it without loops / recursion ?
class Solution {
public:
    bool isPowerOfTwo(int n) {
		return n > 0 && (n & (n - 1)) == 0; // use bitwise AND to check if n is a power of two
		// because 2^x is always increased 0 and 1 is the only bit set in its binary representation.
		//for example: 1 (0001), 2 (0010), 4 (0100), 8 (1000), etc.
		// and n-1( if n == 2^x) will always have 1.
		// for example: 1 (0000), 2 (0001), 4 (0011), 8 (0111), etc.
    }
};