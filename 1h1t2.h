#pragma
#include"L.h"
class PathSum {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL) {
            return false;
        }
        if (targetSum - root->val == 0 && root->left == NULL && root->right == NULL) return true;
        bool left = hasPathSum(root->left, targetSum - root->val);
        bool right = hasPathSum(root->right, targetSum - root->val);
        return (left == true || right == true);
    }
};