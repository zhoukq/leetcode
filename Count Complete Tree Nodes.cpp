/*Given a complete binary tree, count the number of nodes.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.*/
//思路：左子数的高度等于右子树的高度时，是完全二叉树，可以用公式算，不相等是递归
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
    int countNodes(TreeNode* root) 
    {
        TreeNode *lt=root,*rt=root;
        int nl=0,nr=0;
        if(root==NULL)
            return 0;
        while(lt!=NULL)
        {
            nl++;
            lt=lt->left;
        }
        while(rt!=NULL)
        {
            nr++;
            rt=rt->right;
        }
        if(nl==nr)
        {
            return pow(2,nl)-1;
        }
        else
        {
            return countNodes(root->left)+countNodes(root->right)+1;
        }
    }
};
