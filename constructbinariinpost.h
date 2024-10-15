#pragma once
#include"L.h"
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        return build(inorder, 0, n - 1, postorder, 0, n - 1);
    }
    TreeNode* build(vector<int>& inorder, int startIn, int endIn, vector<int>& postorder, int startPost, int endPost) {
        if (startIn > endIn) {
            return NULL;
        }

        int rootVal = postorder[endPost]; // Root value is at the end of postorder
        TreeNode* root = new TreeNode(rootVal);

        // Find the index of rootVal in inorder
        int index = startIn;
        while (inorder[index] != rootVal) {
            index++;
        }

        // Calculate the size of the left subtree
        int leftSubtreeSize = index - startIn;

        // Recursive calls to build left and right subtrees
        root->left = build(inorder, startIn, index - 1, postorder, startPost, startPost + leftSubtreeSize - 1);
        root->right = build(inorder, index + 1, endIn, postorder, startPost + leftSubtreeSize, endPost - 1);

        return root;
    }
};