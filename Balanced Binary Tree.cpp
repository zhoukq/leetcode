/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1. 
*/
//思路：如果符合条件，则左子树的高度和右子树的高度只差也应该符合条件，左子树的右子树和左子树的高度差符合条件...，递归
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int htree(TreeNode* node,int h)
    {
        if(node==NULL)
            return h;
        int a=h,b=h;
        //if(node->left!=NULL)
        a=htree(node->left,h+1);
        //if(node->right!=NULL)
        b=htree(node->right,h+1);
        if(abs(a-b)>1)
            return -1;
        return a>b?a:b;
    }
    bool bbalanced(TreeNode* node)
    {
        if(node==NULL)
            return true;
        int a=htree(node->left,1),b=htree(node->right,1);
        
        if(abs(a-b)>1)
            return false;
        else if(a==-1)
            return false;
        else if(b==-1)
            return false;
        else
            return true;
    }
    bool isBalanced(TreeNode* root)
    {
        if(root==NULL)
            return true;
        return bbalanced(root);
    }
};
