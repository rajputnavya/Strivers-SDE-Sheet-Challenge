// Question Link:
// Code Studio : https://www.codingninjas.com/codestudio/problems/preorder-traversal_8230856?challengeSlug=striver-sde-challenge&leftPanelTab=0
// LeetCode : https://leetcode.com/problems/binary-tree-preorder-traversal/submissions/965012426/

#include <bits/stdc++.h> 
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/

void getPreOrderTraversal(TreeNode *root, vector<int> &ans){
    if(root == NULL){
        return;
    }
    ans.push_back(root->data);
    getPreOrderTraversal(root->left, ans);
    getPreOrderTraversal(root->right, ans);
}

vector<int> getPreOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int> ans;
    getPreOrderTraversal(root, ans);
    return ans;
}
