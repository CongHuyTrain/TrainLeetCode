#pragma once
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int reach = -1, count = 0;
        for (int i = startIndex; i >= 0; i--) {
            if (words[i] == target) {
                reach = count;
                break;
            }
            if (i == 0) {
                for (int i = n - 1; i > startIndex; i--) {
                    count++;
                    if (words[i] == target) {
                        reach = count;
                        break;
                    }
                }
            }
            count++;
        }
        if (reach == -1) return -1;
        int countright = 0;
        for (int i = startIndex; i <= startIndex * 2 + n - startIndex;i++) {
            if (words[i % n] == target) {
                reach = min(reach, countright);
                break;
            }
            countright++;
        }
        return reach;
    }
};