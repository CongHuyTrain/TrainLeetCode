#pragma once
#include <vector>
using namespace std;
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board.size(); j++) {
                if (board[i][j] == '.') {
                    vector<int, int> able;
                    able = solveSudoku(board, i, j);
                    for (int k = 1; k < able.size(); k++) {
                        if (able[k] == 0) {
                            board[i][j] = k;
                            if (i == 8 && j == 8)    return board;
                            solveSudoku(board);
                        }
                    }
                }
            }
        }
    }
    vector<int, int> solveSudoku(vector<vector<char>> board, int col, int row) {
        vector<int, int> count(10, 0);
        for (int i = 0; i < board.size(); i++) {
            if (board[i][row] != ".") {
                count[board[i][row]]++;
            }
        }
        for (int i = 0; i < board[0].size(); i++) {
            if (board[col][i] != ".") {
                count[board[col][i]]++;
            }
        }
        return count;
    }
};