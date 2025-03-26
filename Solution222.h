#pragma once
#include"L.h"
//222
class completetreecount {
public:
    int countNodes(TreeNode* root) {

        if (!root) return 0;

        int hl = 0, hr = 0;

        TreeNode* l = root, * r = root;

        while (l) { hl++; l = l->left; }

        while (r) { hr++; r = r->right; }

        if (hl == hr) return pow(2, hl) - 1;

        return 1 + countNodes(root->left) + countNodes(root->right);

    }
};
/*
class Solution {
    static inline auto _ = [] {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::ofstream out("user.out", std::ios::out | std::ios::binary);
        out.rdbuf()->pubsetbuf(nullptr, 256);
        std::string s;
        std::noskipws(std::cin);
        while (std::getline(std::cin, s)) {
            int count = 0;
            bool inNum = false;
            for (char c : s) {
                if (std::isdigit(c) != 0) {
                    if (!inNum) {
                        ++count;
                        inNum = true;
                    }
                }
                else {
                    inNum = false;
                }
            }
            out << count << '\n';
        }
        std::skipws(std::cin);
        out.flush();
        exit(0);
        return 0;
        }();

public:
    int getLeftHeight(TreeNode* root) {
        int ans = 0;
        while (root) {
            root = root->left;
            ans++;
        }
        return ans;
    }
    int getRightHeight(TreeNode* root) {
        int ans = 0;
        while (root) {
            root = root->right;
            ans++;
        }
        return ans;
    }
    int countNodes(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int lh = getLeftHeight(root);
        int rh = getRightHeight(root);
        if (lh == rh) {
            return (pow(2, lh) - 1);
        }
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};