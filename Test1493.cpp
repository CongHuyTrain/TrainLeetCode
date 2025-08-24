#include "Solution1493.h"
#include <iostream>
int main() {
    vector<vector<int>> testCases = {
        {1, 1, 0, 1},
        {0, 1, 1, 1, 0, 1, 1, 0, 1},
        {1, 1, 1},
        {1,0,1,1,1,1,1,1,0,1,1,1,1,1 }
    };
    vector<int> expected = { 3, 5, 2, 11};
    Solution s;
    for (int i = 0; i < testCases.size(); i++) {
        int result = s.longestSubarray(testCases[i]);
        cout << "Test case " << i + 1 << ": ";
        cout << "Output = " << result << ", Expected = " << expected[i];
        if (result == expected[i])
            cout << "Passed";
        else
            cout << "Failed";
        cout << endl;
    }
    return 0;
}
