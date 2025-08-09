#pragma once
//class Solution {
//public:
//    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
//        int result = 0, resultNow = 0;
//        // case we walk from human to left( code run left -> human).
//        for (int i = 0; i < fruits.size() && fruits[i][0] <= startPos; i++) {
//            if (fruits[i][0] + k >= startPos) { // if local + step >= human
//                resultNow = fruits[i][1]; // count fruits of local
//                int poiter = startPos;
//                int count = k - (startPos - fruits[i][0]) * 2;
//                for (int j = i + 1; j < fruits.size(); j++) {  // continue  with that case
//                    if (fruits[j][0] <= startPos) {
//                        // if any fruit line in the way we're already walked, then count.
//                        resultNow += fruits[j][1];
//                    }
//                    else if (fruits[j][0] - poiter <= count) {
//                        // the other case we turn back to right.
//                        resultNow += fruits[j][1];
//                        count -= (fruits[j][0] - poiter);
//                        poiter = fruits[j][0];
//                    }
//                    else    break;
//                }
//                result = max(result, resultNow);
//                resultNow = 0;
//            }
//        }
//        // case we walk from human to right( code run right -> human).
//        for (int i = fruits.size() - 1; i >= 0 && fruits[i][0] >= startPos; i--) {
//            if (fruits[i][0] - k <= startPos) {
//                resultNow = fruits[i][1];
//                int poiter = startPos;
//                int count = k - (fruits[i][0] - startPos) * 2;
//                for (int j = i - 1; j >= 0; j--) {
//                    if (fruits[j][0] >= startPos) {
//                        resultNow += fruits[j][1];
//                    }
//                    else if (poiter - fruits[j][0] <= count) {
//                        resultNow += fruits[j][1];
//                        count -= (poiter - fruits[j][0]);
//                        poiter = fruits[j][0];
//                    }
//                    else    break;
//                }
//                result = max(result, resultNow);
//                resultNow = 0;
//            }
//        }
//        return result;
//    }
//};
//
class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        int left = 0, right = 0;
        int currentSum = 0, maxSum = 0;

        while (right < n) {
            currentSum += fruits[right][1]; // pick fruit at 'right'

            // If too far from startPos, shrink the window from the left
            while (left <= right && minSteps(fruits, startPos, left, right) > k) {
                currentSum -= fruits[left][1];
                left++;
            }

            maxSum = max(maxSum, currentSum); // update max
            right++; // expand window
        }

        return maxSum;
    }

private:
    int minSteps(const vector<vector<int>>& fruits, int startPos, int left, int right) {
        int leftPos = fruits[left][0];
        int rightPos = fruits[right][0];

        if (rightPos <= startPos) {
            // Only go left
            return startPos - leftPos;
        }
        else if (leftPos >= startPos) {
            // Only go right
            return rightPos - startPos;
        }
        else {
            // Go to one side first, then the other
            return min(startPos - leftPos, rightPos - startPos) + (rightPos - leftPos);
        }
    }
};