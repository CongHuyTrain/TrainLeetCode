#pragma once
#include"L.h"
class pathsumii {
public:
    //return; to say that done
    void path(TreeNode* root, int targetSum, vector<int> result, vector<vector<int>>& ans) {
        if (root == NULL) return;
        if (root->left == NULL && root->right == NULL) {
            if (root->val == targetSum) {
                result.push_back(root->val);
                ans.push_back(result);
            }
            return;
        }
        result.push_back(root->val);
        path(root->left, targetSum - root->val, result, ans);
        path(root->right, targetSum - root->val, result, ans);

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> resultmain;
        vector<int> result;
        path(root, targetSum, result, resultmain);
        return resultmain;
    }
};
/*
class Solution {
public:
    void solve(vector<vector<int>> &ans,vector<int> &arr,TreeNode* root,int k){
        if(root==NULL){
            return ;
        }
        arr.push_back(root->val);
        if(root->left==NULL && root->right==NULL){
            if(k==root->val){
                ans.push_back(arr);
            }
        }
        solve(ans,arr,root->left,k-root->val);
        solve(ans,arr,root->right,k-root->val);
        arr.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> arr;
        int sum=0;
        solve(ans,arr,root,targetSum);
        return ans;
    }
    */