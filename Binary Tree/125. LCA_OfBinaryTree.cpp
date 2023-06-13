// Question Link : 
// Code Studio : https://www.codingninjas.com/codestudio/problems/lca-of-binary-tree_8230760?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
	//    Write your code here
    if(root == NULL){
        return -1;
    }
    if(root->data == x || root->data == y){
        return root->data;
    }
    int leftAns = lowestCommonAncestor(root->left, x, y);
    int rightAns = lowestCommonAncestor(root->right, x, y);

    if(leftAns != -1 && rightAns != -1){
        return root->data;
    }
    return max(leftAns, rightAns);
}
