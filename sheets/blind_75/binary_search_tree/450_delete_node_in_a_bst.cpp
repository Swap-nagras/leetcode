/*
 * Problem: 450. Delete Node in a BST
 * URL: https://leetcode.com/problems/delete-node-in-a-bst/
 * Difficulty: medium
 * Topics: Trees, Recursion, Binary Search Tree
 */

#include "./common.hpp"
#include "./structures.hpp"

class Solution {
public:
    // We always return the modified subtree
    TreeNode* del(TreeNode *root, int key){
        // base condn
        if(root==nullptr) return nullptr;

        // find the node to be deleted
        if(key < root->val) root->left=del(root->left, key);
        else if(key > root->val) root->right=del(root->right, key);
        else if(key == root->val){
            if(root->left==nullptr && root->right==nullptr) return nullptr;
            
            // if either left or right is null, simply return the other
            else if(root->left==nullptr) return root->right;
            else if(root->right==nullptr) return root->left;

            // replace the deleted node either with max of left subtree or min of right subtree
            // find max of left subtree
            TreeNode *temp=root->left;
            while(temp->right!=nullptr){
                temp=temp->right;
            }
            root->val=temp->val;
            root->left=del(root->left, root->val); // recursively call delete on left subtree
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        root = del(root, key);
        return root;
    }
};
