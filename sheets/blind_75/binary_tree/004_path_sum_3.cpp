/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#include <unordered_map>
using namespace std;
class Solution {
public:
    int f(TreeNode* root, int targetSum, int curSum, unordered_map<int, int> &mp){
        if(root==NULL) return 0;
    
        int cnt=0;
        curSum+=root->val;
        if(mp.count(curSum-targetSum)) cnt+=mp[curSum-targetSum];
        mp[curSum]++;
        cnt+=f(root->left, targetSum, curSum, mp);
        cnt+=f(root->right, targetSum, curSum, mp);
        mp[curSum]--; // backtrack
        return cnt;
    }
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<int, int> mp;
        // HashMap prefix sum approach - O(n) approach single pass
        mp[0] = 1; // for root node
        return f(root, targetSum, 0, mp);
    }
};