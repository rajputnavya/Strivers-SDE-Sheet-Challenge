// Question Link :
// Code Studio : https://www.codingninjas.com/codestudio/problems/check-identical-trees_8230719?challengeSlug=striver-sde-challenge&leftPanelTab=1
// LeetCode : https://leetcode.com/problems/same-tree/submissions/965016378/


#include <bits/stdc++.h> 
/**********************************************************

    Following is the Binary Tree Node class structure:

    template <typename T>

    class BinaryTreeNode {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
		
        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

***********************************************************/

bool identicalTrees(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
    // Write your code here. 	
    if(root1 == NULL && root2 == NULL){
        return true;
    } 
    if((root1 == NULL && root2 != NULL) || (root1 != NULL && root2 == NULL)){
        return false;
    }
    if(root1->data != root2->data){
        return false;
    }
    bool leftAns = identicalTrees(root1->left, root2->left);
    bool rightAns = identicalTrees(root1->right, root2->right);

    return leftAns && rightAns;
}
