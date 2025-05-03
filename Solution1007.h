#pragma once
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
//1007. Minimum Domino Rotations For Equal Row
//Solved
//Medium
//Topics
//Companies
//In a row of dominoes, tops[i] and bottoms[i] represent the top and bottom halves of the ith domino. 
//(A domino is a tile with two numbers from 1 to 6 - one on each half of the tile.)
//We may rotate the ith domino, so that tops[i] and bottoms[i] swap values.
//Return the minimum number of rotations so that all the values in tops are the same, or all the values in bottoms are the same.
//If it cannot be done, return -1.
 
 
//Example 1:
//Input: tops = [2, 1, 2, 4, 2, 2], bottoms = [5, 2, 6, 2, 3, 2]
//Output : 2
//Explanation :
//    The first figure represents the dominoes as given by tops and bottoms : before we do any rotations.
//    If we rotate the second and fourth dominoes, we can make every value in the top row equal to 2, 
//    as indicated by the second figure.

//    Example 2 :
//
//    Input : tops = [3, 5, 1, 2, 3], bottoms = [3, 6, 3, 3, 4]
//    Output : -1
//    Explanation :
//    In this case, it is not possible to rotate the dominoes to make one row of values equal.
class Solution {
public:
    // count how many swap to make vector( top or bottom) all resemble
    int countSwap(vector<int> main, vector<int> submain, int count) {
        int result = 0; // 
        for (int i = 0; i < main.size(); i++) {
            if (main[i] != count) { // situation 
                if (submain[i] != count) return -1; // for situation of example 2, it no way to make vector(t or b) all resemble
                result++; // count 
            }
        }
        return result;
    }
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        unordered_map<int, int> countMapTop;
        for (auto& i : tops)    countMapTop[i]++; // count 
        int countTops = -1, max = 0;
        for (auto& i : countMapTop) {
            if (i.second > max) {
                countTops = i.first;
                max = i.second;
            }
        }
        unordered_map<int, int> countMapB;
        for (auto& i : bottoms)    countMapB[i]++;
        int countBottoms = -1; max = 0;
        for (auto& i : countMapB) {
            if (i.second > max) {
                countBottoms = i.first;
                max = i.second;
            }
        }
        if (countMapTop[countTops] == tops.size() || countMapB[countBottoms] == bottoms.size())  return 0; // we dont need this row, if we delete it, it also run, but slower.
        else if (countMapTop[countTops] > countMapB[countBottoms]) return countSwap(tops, bottoms, countTops); //
        else return countSwap(bottoms, tops, countBottoms);
    }
};