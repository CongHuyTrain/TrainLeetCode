#pragma once
#include"L.h"
//class Solution {
//public:
//    TreeNode* constructTree(vector < int >& preorder, int preStart, int preEnd, vector
//        < int >& inorder, int inStart, int inEnd, map < int, int >& mp) {
//        if (preStart > preEnd || inStart > inEnd) return NULL;
//
//        TreeNode* root = new TreeNode(preorder[preStart]);
//        int elem = mp[root->val];
//        int nElem = elem - inStart;
//
//        root->left = constructTree(preorder, preStart + 1, preStart + nElem, inorder,
//            inStart, elem - 1, mp);
//        root->right = constructTree(preorder, preStart + nElem + 1, preEnd, inorder,
//            elem + 1, inEnd, mp);
//
//        return root;
//    }
//
//    TreeNode* buildTree(vector < int >& preorder, vector < int >& inorder) {
//        int preStart = 0, preEnd = preorder.size() - 1;
//        int inStart = 0, inEnd = inorder.size() - 1;
//
//        map < int, int > mp; // ðýa 
//        for (int i = inStart; i <= inEnd; i++) {
//            mp[inorder[i]] = i;
//        }
//
//        return constructTree(preorder, preStart, preEnd, inorder, inStart, inEnd, mp);
//    }
//};

class Solution {
public:
    TreeNode* build(vector<int>& pre, int preLow, int preHigh, vector<int>& in, int inLow, int inHigh) {
        // base case
        if (preLow > preHigh || inLow > inHigh) return NULL; // vector no loger member or node.
        TreeNode* root = new TreeNode(pre[preLow]); //because pre mid left right so use it the number at position nho nhat
        if (preLow == preHigh) return root; // all mabmber of 2 vector had 
        int i = inLow;
        // find the 0th element of preOrder in InOrder 
        while (i <= inHigh) {
            if (in[i] == pre[preLow]) break;
            i++;
        }
        int leftCount = i - inLow;
        int rightCount = inHigh - 1;
        // recursion part of left & right subtree
        root->left = build(pre, preLow + 1, preLow + leftCount, in, inLow, i - 1);
        root->right = build(pre, preLow + leftCount + 1, preHigh, in, i + 1, inHigh);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return build(preorder, 0, n - 1, inorder, 0, n - 1);
    }
};
//bai tu code
//class Solution {
//public:
//    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//        int i = preorder.size();
//        return build(preorder, 0, i - 1, inorder, 0, i - 1);
//    }
//    TreeNode* build(vector<int>& pr, int startpr, int endpr, vector<int>& in, int startin, int endin) {
//        if (endpr < startpr || startin > endin) return NULL;
//        TreeNode* root = new TreeNode(pr[startpr]);
//        if (endpr == startpr) return root;
//        int i = startin;
//        while (i <= endin) {
//            if (in[i] == pr[startpr]) {
//                break;
//            }
//            i++;
//        }
//        root->left = build(pr, startpr + 1, startpr + i - startin, in, startin, i - 1);
//        root->right = build(pr, startpr + i - startin + 1, endpr, in, i + 1, endin);
//        return root;
//    }
//};
//code nhanh.
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inToIndex;

        for (int i = 0; i < inorder.size(); ++i)
            inToIndex[inorder[i]] = i;

        return build(preorder, 0, preorder.size() - 1, inorder, 0,
            inorder.size() - 1, inToIndex);
    }

private:
    TreeNode* build(const vector<int>& preorder, int preStart, int preEnd,
        const vector<int>& inorder, int inStart, int inEnd,
        const unordered_map<int, int>& inToIndex) {
        if (preStart > preEnd)
            return nullptr;

        const int rootVal = preorder[preStart];
        const int rootInIndex = inToIndex.at(rootVal);
        const int leftSize = rootInIndex - inStart;

        TreeNode* root = new TreeNode(rootVal);
        root->left = build(preorder, preStart + 1, preStart + leftSize, inorder,
            inStart, rootInIndex - 1, inToIndex);
        root->right = build(preorder, preStart + leftSize + 1, preEnd, inorder,
            rootInIndex + 1, inEnd, inToIndex);
        return root;
    }
};