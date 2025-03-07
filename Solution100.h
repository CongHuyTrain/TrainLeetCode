#pragma once
#include"L.h"
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
//do theo dfs
class compare2binary
{
    public:
        bool isSameTree(TreeNode* p, TreeNode* q) {
            if (p == NULL && q == NULL) { //tai sao so sanh truoc vi ca 2 la null moi dung so sanh dai xuong bo
                //qua so sanh cac gia tri tang toc do va no o dau moi dung logic
                return true;
            }
            if ((p == nullptr || q == nullptr) || p->val != q->val) {
                return false;
            }
            bool left = isSameTree(p->left, q->left);
            bool right = isSameTree(p->right, q->right);
            return right && left;
        }

};

