#pragma once
#include<vector>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), g = 0, result = 0;
		// check array can be existed at least ability to have GCD = 1
		// and count number of 1s
        for (int x : nums) {
            if (x == 1)  result++;
            g = gcd(g, x);
        }
		// if there are more than one 1, we can just return n - number_of_1s
        //( because we return number of operations to make all elements equal to 1)
        if (result > 1) return n - result;
		// if GCD of whole array > 1, it's impossible to make all elements equal to 1 because impossible to get 1 from numbers with GCD > 1
        if (g > 1)   return -1;
		int min_sub = n; // initialize(khởi tạo) min_sub to n (maximum possible length of subarray) because we are looking for minimum length subarray with GCD = 1
		// we also check that if there is at least one subarray with GCD = 1
        for (int i = 0; i < n; i++) {
            int g = 0;
			// brute force to find the minimum length of subarray with GCD = 1
            for (int j = i; j < n; j++) {
				// calculate GCD of subarray nums[i..j]
                g = gcd(g, nums[j]);
				// if GCD = 1, update min_sub and break to next i
                if (g == 1) {
					min_sub = min(min_sub, j - i + 1); // length of subarray
					// break because we found the minimum length subarray starting from i so no need to check longer subarrays starting from i
                    break;
                }
            }
        }
		return min_sub + n - 2; // after calculating min_sub, total operations = (min_sub - 1) + (n - 1)
		// to think that we need (min_sub - 1) operations to make one 1 from that subarray, and then (n - 1) operations to make all other elements equal to 1
    }
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};