#pragma once
#include"L.h"
     //Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


class DFSfinddepth
{
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL)    return 0;
        int leftD = 1 + maxDepth(root->left);
        int rightD = 1 + maxDepth(root->right);
        return max(leftD, rightD);
    }
};


//code nhanh
//class DFSfinddepth
// {
//    public:
//        int maxDepth(TreeNode* root) {
//            if (root == NULL) return 0;
//            int l = maxDepth(root->left);
//            int r = maxDepth(root->right);
//            return 1 + max(l, r);
//        }
//};

