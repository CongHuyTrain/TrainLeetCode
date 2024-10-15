#pragma once
#include"L.h"
class checkbinarytreebalance
  {
    public:
        int isBalance(TreeNode* root) {
            if (root == nullptr) return 0;
            return 1 + max(isBalance(root->left), isBalance(root->right));
            //tree qq count left and right by recursion
        }
        bool isBalanced(TreeNode* root) {
            if (root == nullptr)  return true;
            int left = isBalance(root->left);
            int right = isBalance(root->right);
            if (abs(left - right) > 1) return false;
            //banlance when left and right of main root == or == +1
            //resursion left and right and watch it like root 
            bool leftBalanced = isBalanced(root->left);
            bool rightBalanced = isBalanced(root->right);
            //return check two of them true yet?
            return leftBalanced && rightBalanced;

        }
};

