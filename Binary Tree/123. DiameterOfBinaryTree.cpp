// Question Link : 
// Code Studio : https://www.codingninjas.com/codestudio/problems/diameter-of-binary-tree_8230762?challengeSlug=striver-sde-challenge&leftPanelTab=0
// LeetCode : https://leetcode.com/problems/diameter-of-binary-tree/submissions/965012663/


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

pair<int, int> diameterOfBinaryTreeHelper(TreeNode<int> *root){
    if(root == NULL){
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }
    pair<int, int> leftAns = diameterOfBinaryTreeHelper(root->left);
    pair<int, int> rightAns = diameterOfBinaryTreeHelper(root->right);

    int leftHeight = leftAns.first;
    int leftDiameter = leftAns.second;
    int rightHeight = rightAns.first;
    int rightDiameter = rightAns.second;

    int height = 1+ max(leftHeight, rightHeight);
    int diameter = max(leftHeight + rightHeight, max(leftDiameter, rightDiameter));

    pair<int, int> p;
    p.first = height;
    p.second = diameter;
    return p;

}

int diameterOfBinaryTree(TreeNode<int> *root)
{
    return diameterOfBinaryTreeHelper(root).second;
}
