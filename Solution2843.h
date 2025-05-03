#pragma once
#include<vector>
#include <string>
using namespace std;
class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int result = 0;
        for (int i = low; i <= high; i++) {
            vector<int> digits;
            int a = i;
            while (a > 0) {
                digits.push_back(a % 10);
                a /= 10;
            }
            // Check if the number has an even number of digits
            if (digits.size() % 2 != 0) continue;

            int leftSum = 0;
            int rightSum = 0;
            // Sum the digits of the first half and the second half
            for (int i = 0, j = digits.size() - 1; i < digits.size() / 2; i++, j--) {
                leftSum += digits[i];
                rightSum += digits[j];
            }
            // If the sums are equal, the number is symmetric
            if (leftSum == rightSum) result++;
        }
        return result;
    }
};
// faster
class Solution1 {
    // Helper function to check if a number is symmetric
    bool isSymmetric(int number) {
        string strNum = to_string(number);
        int length = strNum.length();

        // Symmetric integers must have even number of digits
        if (length % 2 != 0) {
            return false;
        }

        int half = length / 2;
        int leftSum = 0, rightSum = 0;

        for (int i = 0; i < half; ++i) {
            leftSum += strNum[i] - '0';
            rightSum += strNum[i + half] - '0';
        }

        return leftSum == rightSum;
    }

public:
    // Counts the number of symmetric integers in a given range
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for (int i = low; i <= high; ++i) {
            if (isSymmetric(i)) {
                ++count;
            }
        }
        return count;
    }
};