<<<<<<< HEAD
﻿#include "L.h"
#pragma once
//DivideandconquerBST
// code nhanh
  struct TreeNode {
     int val;
      TreeNode *left;
      TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };


  class DivideandconquerBST {
  public:
      TreeNode* constructBST(const vector<int>& nums, int left, int right) {
          if (left > right) { return NULL; } // nếu trái lớn hơn phải thì null nghĩa là nếu nó thiếu nút để diễn đạt ?
          int mid = left + (right - left) / 2; // mid này đúng
          TreeNode* node = new TreeNode(nums[mid]);
          node->left = constructBST(nums, left, mid - 1); // đệ quy 
          node->right = constructBST(nums, mid + 1, right);

          return node;
      }
      TreeNode* sortedArrayToBST(vector<int>& nums) {
          return constructBST(nums, 0, nums.size() - 1); //trả về cây nhị phân đc xếp theo mảng theo thứ tự tăng dần. 
          // nên chính giữa sẽ là root, tiếp theo chia 2 bên để trị, mà mỗi nút đều đệ quy xem như một cái gốc riêng luôn để đệ quy dễ.
      }
  };
 
//class Solution {
//public:
//    TreeNode* sortedArrayToBST(vector<int>& nums) {
//
//        return bst(nums, 0, nums.size() - 1);
//    }
//    TreeNode* bst(vector<int>& nums, int left, int right) {
//        if (left > right) return NULL;
//
//        int mid = (left + right) / 2;
//        TreeNode* node = new TreeNode(nums[mid]);
//        if (left == right) return node;
//
//        node->left = bst(nums, left, mid - 1);
//        node->right = bst(nums, mid + 1, right);
//        return node;
//
//    }
//
//};
=======
﻿#include "L.h"
#pragma once
//DivideandconquerBST
// code nhanh
  struct TreeNode {
     int val;
      TreeNode *left;
      TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };


  class DivideandconquerBST {
  public:
      TreeNode* constructBST(const vector<int>& nums, int left, int right) {
          if (left > right) { return NULL; } // nếu trái lớn hơn phải thì null nghĩa là nếu nó thiếu nút để diễn đạt ?
          int mid = left + (right - left) / 2; // mid này đúng
          TreeNode* node = new TreeNode(nums[mid]);
          node->left = constructBST(nums, left, mid - 1); // đệ quy 
          node->right = constructBST(nums, mid + 1, right);

          return node;
      }
      TreeNode* sortedArrayToBST(vector<int>& nums) {
          return constructBST(nums, 0, nums.size() - 1); //trả về cây nhị phân đc xếp theo mảng theo thứ tự tăng dần. 
          // nên chính giữa sẽ là root, tiếp theo chia 2 bên để trị, mà mỗi nút đều đệ quy xem như một cái gốc riêng luôn để đệ quy dễ.
      }
  };
 
//class Solution {
//public:
//    TreeNode* sortedArrayToBST(vector<int>& nums) {
//
//        return bst(nums, 0, nums.size() - 1);
//    }
//    TreeNode* bst(vector<int>& nums, int left, int right) {
//        if (left > right) return NULL;
//
//        int mid = (left + right) / 2;
//        TreeNode* node = new TreeNode(nums[mid]);
//        if (left == right) return node;
//
//        node->left = bst(nums, left, mid - 1);
//        node->right = bst(nums, mid + 1, right);
//        return node;
//
//    }
//
//};
>>>>>>> ccfc2d41cc8ed0575db2cca47d1d2f8d82bb3b45
