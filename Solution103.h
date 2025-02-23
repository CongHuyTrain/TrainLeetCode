#pragma once
#include"L.h"
//103. Binary Tree Zigzag Level Order Traversal
//Medium
//Topics
//Companies
//Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).
//
//
//
//Example 1:
//
//
//Input: root = [3, 9, 20, null, null, 15, 7]
//Output : [[3], [20, 9], [15, 7]]
//Example 2 :
//
//    Input : root = [1]
//    Output : [[1]]
//    Example 3 :
//
//        Input : root = []
//        Output : []


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
   //sai  
//class returnvalclasstree
//    {
//    public:
//        vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
//            if (root != nullptr &&
//                (root->left != nullptr || root->right != nullptr)) {
//                return root->val;
//            }
//            return zigzagLevelOrder(root->left), zigzagLevelOrder(root->left);
//
//        }
//};
//class returnvalclasstree {
//public:
//    vector<vector<int>> zigzagLevelOrder(TreeNode* root) { //mục tiêu là tìm được từng tụ [các giá trị cùng tầng]  
//        vector<vector<int>> res;
//        if (!root) return res;
//        vector<int> lvl;
//        queue<TreeNode*> q;
//        bool LtoR = true;// 
//        q.push(root);
//
//        while (!q.empty()) {
//            int size = q.size();
//            while (size--) {
//                TreeNode* node = q.front();   q.pop();
//
//                lvl.push_back(node->val);
//                if (node->left)  q.push(node->left);
//                if (node->right) q.push(node->right);
//            }
//            if (!LtoR) reverse(lvl.begin(), lvl.end());
//            res.push_back(lvl);
//            lvl.clear();
//            LtoR = !LtoR;
//        }
//        return res;
//    }
//};
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     TreeNode *left;
// *     TreeNode *right;
// *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
// *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// * };
// */
//dùng bfs để in các vector có giá trị của mỗi lớp  
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) { //trường hợp rỗng
            return ans;
        }
        std::queue<TreeNode*> q; //duyệt bfs bằng queue
        q.push(root); //đưa root vào queue nghĩa là đẩy cả cái cây vào queue
        int depth = 0;
        while (!q.empty()) { // rỗng khi ko còn phần tử để bfs nữa
            int size = q.size(); //size của queue
            vector<int> row; // lặp lại quá trình tạo vector để lưu giá trị vào  mỗi vector rồi trả giá trị về vector chính rồi in
            for (int i = 0; i < size; i++) { // lặp trong khi size còn đó
                TreeNode* cur = q.front(); //nốt hiện tại dang duyệt bfs là phần tử đầu của queue
                q.pop(); // xóa đầu
                if (depth & 1) { // 0 đầu tiên nên ko thể thêm giá trị thẳng vào hả?
                    row.insert(row.begin(), cur->val);
                }
                else {
                    row.push_back(cur->val); // chỗ này để push giá trị
                }
                if (cur->left) { // nếu tồn tại left thì đẩy vào queue
                    q.push(cur->left);
                }
                if (cur->right) { //giống vậy
                    q.push(cur->right);
                }
            }
            depth++; // ko còn tồn tai phần tử trong queue 
            ans.push_back(row); // push cái vector nãy h tìm được của một lớp ngang về
        }

        return ans; // return tất cả
    }
};
//Để hiểu ý nghĩa của điều kiện if (depth & 1) và cách mà nó ảnh hưởng đến việc chèn giá trị vào vector row, hãy xem xét những điểm sau :
//
//Biến depth được sử dụng để theo dõi cấp độ hiện tại trong cây.
//Khi depth là một số lẻ, điều kiện if (depth & 1) sẽ đúng và giá trị của nút hiện tại(cur->val) sẽ được chèn vào đầu của vector row thông qua row.insert(row.begin(), cur->val); .
//Khi depth là một số chẵn, điều kiện if (depth & 1) sẽ sai và giá trị của nút hiện tại sẽ được thêm vào cuối của vector row thông qua row.push_back(cur->val); .
//Do đó, bằng cách này, giá trị của các nút được chèn vào vector row sẽ thay đổi tuỳ thuộc vào cấp độ hiện tại trong cây, tạo ra hiệu ứng zigzag khi duyệt cây và xử lý giá trị của các nút.

// O(n) time and O(n) space