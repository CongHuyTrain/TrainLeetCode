#pragma once
#include"L.h"
class searchcanbacbangbinary
  {
    public:
        int mySqrt(int x) {
            if (x == 0)  return 0;
            if (x == 1)  return 1;
            int left = 0;
            int right = x;
            int mid = -1;
            while (left <= right) {
                mid = left + (right - left) / 2;
                if (mid > x / mid) {
                    right = mid - 1;
                }
                else if (mid * mid == x) {
                    return mid;
                }
                else {
                    left = mid + 1; // bỏ một bên trái left vì lớn hơn số cần tìm
                }
            }
            return right;
        }
};
//class Solution {
//public:
//    int mySqrt(int x) {
//        double n = x;
//        // Relative error tolerance
//        double epsilon = 0.000001;
//        // Iterate until desired precision is achieved
//        while ((n - x / n) > epsilon) {
//            n = (n + x / n) / 2.0;
//        }
//        return n;
//    }
//};
