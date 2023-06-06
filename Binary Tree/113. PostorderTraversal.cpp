// Question Link : 
// Code Studio : https://www.codingninjas.com/codestudio/problems/postorder-traversal_8230858?challengeSlug=striver-sde-challenge&leftPanelTab=1
// LeetCode : https://leetcode.com/problems/binary-tree-postorder-traversal/submissions/965012598/

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

void getPostOrderTraversal(TreeNode *root, vector<int> &ans){
    if(root == NULL){
        return;
    }
    getPostOrderTraversal(root->left, ans);
    getPostOrderTraversal(root->right, ans);
    ans.push_back(root->data);
}

vector<int> getPostOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int> ans;
    getPostOrderTraversal(root, ans);
    return ans;
}
