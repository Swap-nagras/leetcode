/*
 * Problem: 1372. Longest ZigZag Path in a Binary Tree
 * URL: https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/
 * Difficulty: 
 * Topics: 
 */

#include "../../../common.hpp"
#include "../../../structures.hpp"

class Solution {
public:
    // top-down approach
    // prev - where am i being called from? 0-left, 1-right
    void f(TreeNode* root, bool prev, int curLen, int &maxLen){
        if(root==nullptr) return; // do not update maxLen since the node does not exist

        maxLen=max(curLen, maxLen);
        if(prev==0){
            f(root->left, 0, 1, maxLen); // start of new len (called from left and going left again)
            f(root->right, 1, 1+curLen, maxLen); // called from left and going right, so continue incrementing curLen
        }
        else{
            f(root->left, 0, 1+curLen, maxLen); // called from right and going left, so continue incrementing curLen
            f(root->right, 1, 1, maxLen); // start of new len (called from right and going right again)
        }
    }
    int longestZigZag(TreeNode* root) {
        int maxLen=0;
        f(root->left, 0, 1, maxLen);
        f(root->right, 1, 1, maxLen);
        return  maxLen;
    }
};
