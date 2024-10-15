#pragma once
#include"L.h"
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) return result;
        // Thêm giá trị của nút hiện tại vào vector trước khi thực hiện duyệt các nút con
        result.push_back(root->val);

        // Duyệt cây theo thứ tự trước trên cây con trái
        if (root->left != nullptr) {
            vector<int> left = preorderTraversal(root->left);
            result.insert(result.end(), left.begin(), left.end());
        }

        // Duyệt cây theo thứ tự trước trên cây con phải
        if (root->right != nullptr) {
            vector<int> right = preorderTraversal(root->right);
            result.insert(result.end(), right.begin(), right.end());
        }
        return result;
    }
};