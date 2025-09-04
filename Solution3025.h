#pragma once
#include <vector>
#include <algorithm>
using namespace std;
//3025. Find the Number of Ways to Place People I
//Solved
//Medium
//You are given a 2D array points of size n x 2 representing integer coordinates of some points on a 2D plane, 
//where points[i] = [xi, yi].
//Count the number of pairs of points(A, B), where
//A is on the upper left side of B, and
//there are no other points in the rectangle(or line) they make(including the border).
//Return the count.
//Example 1:
//Input: points = [[1, 1], [2, 2], [3, 3]]
//Output : 0
//Explanation :
//    There is no way to choose A and B so A is on the upper left side of B.
//    Example 2:
//Input: points = [[6, 2], [4, 4], [2, 6]]
//Output : 2
//Explanation :
//    The left one is the pair(points[1], points[0]), where points[1] is on the upper left side of points[0] 
//    and the rectangle is empty.
//    The middle one is the pair(points[2], points[1]), same as the left one it is a valid pair.
//    The right one is the pair(points[2], points[0]), where points[2] is on the upper left side of points[0], 
//    but points[1] is inside the rectangle so it's not a valid pair.
//    Example 3:
//Input: points = [[3, 1], [1, 3], [1, 1]]
//Output : 2
//Explanation :
//    The left one is the pair(points[2], points[0]), where points[2] is on the upper left side of points[0] 
//    and there are no other points on the line they form.Note that it is a valid state when the two points form a line.
//    The middle one is the pair(points[1], points[2]), it is a valid pair same as the left one.
//    The right one is the pair(points[1], points[0]), it is not a valid pair as points[2] is on the border of the rectangle.
//    Constraints:
//2 <= n <= 50
//points[i].length == 2
//0 <= points[i][0], points[i][1] <= 50
//All points[i] are distinct.
class Solution {
public:
    static bool coordination(vector<int>& p, vector<int>& q) {
        return p[0] == q[0] ? p[1] < q[1] : p[0] > q[0];
        // because look ex2, if x== and y > ?, we rearrange first, and we can count it
        // count because it is a perpendicular([]) line.
        // tran to a point bigger it
        // and the bigger we make a rectangle with have no effect of a point x==
    }
    int numberOfPairs(vector<vector<int>>& points) {
        int result = 0;
		sort(points.begin(), points.end(), coordination); // coordination is a function defined 
        for (int i = 0; i < points.size() - 1; i++) {
            int yA = INT_MAX;
            for (int j = i + 1; j < points.size(); j++) {
                if (points[j][1] >= points[i][1] && yA > points[j][1]) {
                    result++;
					yA = points[j][1]; // update yA to the new lowest y found
                }
            }
        }
        return result;
    }
};