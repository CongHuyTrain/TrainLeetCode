#pragma once
#include"L.h"
/*Given the root of a binary tree, return the level
order traversal of its nodes' values. (i.e., from left to right, level by level).
Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []*/

class BinaryTreeLevelOrderTraversal {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res; // storage to return
        queue<TreeNode*>q;  // create queue

        if (!root) return res; // case root = NULL
        q.push(root); // if not null then push root to queue

        while (!q.empty()) { // q empty p
            vector<int>v; //vector to push level
            int s = q.size();

            for (int i = 0; i < s; i++) {
                TreeNode* temp = q.front(); // take fist
                q.pop(); 
                v.push_back(temp->val); // add to the last

                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
            res.push_back(v); // add to the last


        }



        return res;
    }
};
