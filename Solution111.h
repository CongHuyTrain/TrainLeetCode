#pragma once
#include"L.h"
class MinimumDepthofBinaryTree {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        int right = 1 + minDepth(root->right);
        int left = 1 + minDepth(root->left);
        if (root->left == NULL && root->right != NULL) {
            return right; // case left = null then return right
        }
        else if (root->right == NULL && root->left != NULL) {
            return left; // nguoc lai
        }
        else {
            return right >= left ? left : right; // return minimum
        }
    }
};
// code nhanh 
/*
int speed = []() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int left = minDepth(root->left);
        int right = minDepth(root->right);

        if (right == 0 || left == 0)
            return max (left, right) + 1;
        root->left = nullptr;
        root->right = nullptr;
        return min(left, right) + 1;
    }
};*/