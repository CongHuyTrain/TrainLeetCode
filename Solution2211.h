#pragma once
#include <string>
class Solution {
public:
    int countCollisions(string directions) {
        int left = 0, right = directions.size();
        int result = 0;
        bool coli = false, existS = false, existSEND = false;
        int carR = -1;
        while (left < right && directions[left] == 'L')  left++;
        while (left < right && directions[left] == 'S') {
            left++;
            existS = true;
        }
        while (right > 0 && directions[right - 1] == 'R')  right--;
        while (right > 0 && directions[right - 1] == 'S') {
            right--;
            existSEND = true;
        }
        for (int i = left; i < right; i++) {
            if (directions[i] == 'R') {
                coli = false;
                existS = false;
                carR++;
            }
            else if (directions[i] == 'L') {
                if (coli || existS) {
                    result++;
                }
                else {
                    result = result + 2 + carR;
                    carR = -1;
                    coli = true;
                }
            }
        }
        return existSEND ? result + carR + 1 : result;
    }
};