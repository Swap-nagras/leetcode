/*
 * Problem: 236. Lowest Common Ancestor of a Binary Tree
 * URL: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
 * Difficulty: medium
 * Topics: tree, depth-first search, recursion
 */

#include "../../../common.hpp"
#include "../../../structures.hpp"

class Solution {
public:
    TreeNode* f(TreeNode* root, TreeNode* p, TreeNode* q){
        // base condition
        if(root==nullptr) return nullptr;
        if(root==p) return p;
        if(root==q) return q;
        
        // main logic
        TreeNode *l=f(root->left, p, q);
        TreeNode *r=f(root->right, p, q);
        if(l && r) return root; // if both fn calls return non null
        // if either returns non null
        if(l!=nullptr) return l;
        if(r!=nullptr) return r;
        return nullptr;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // search for p,q at the same time
        // similar to finding path from root to x 
        return f(root, p, q);
    }
};