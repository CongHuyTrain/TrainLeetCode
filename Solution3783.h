#pragma once
#include<cmath>
class Solution {
public:
    int mirrorDistance(int n) {
        return abs(n - reverseInt(n));
    }
    int reverseInt(int num) {
        int re = 0;
        while (num > 0) {
            re = re * 10 + num % 10;
            num = num / 10;
        }
        return re;
    }
};