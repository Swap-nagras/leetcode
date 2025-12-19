#ifndef STRUCTURES_HPP
#define STRUCTURES_HPP

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Definition for a Node in N-ary tree.
class Node {
public:
    int val;
    vector<Node*> children;
    
    Node() {}
    Node(int _val) : val(_val) {}
    Node(int _val, vector<Node*> _children) : val(_val), children(_children) {}
};

// Definition for a graph node.
class GraphNode {
public:
    int val;
    vector<GraphNode*> neighbors;
    
    GraphNode() : val(0) {}
    GraphNode(int _val) : val(_val) {}
    GraphNode(int _val, vector<GraphNode*> _neighbors) : val(_val), neighbors(_neighbors) {}
};

#endif // STRUCTURES_HPP
