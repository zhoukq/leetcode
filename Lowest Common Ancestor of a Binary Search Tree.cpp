/* Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).” */
//思路：
//1.递归找，三种情况:1.1 节点的左右子树包含p,q 1.2 一个节点是p，那么q肯定在它下面 1.3一个点是q，那么p肯定在它下面
//2.利用bst特点把到p,q的两条路径记录在一条链表里，寻找链表的第一个公共节点
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
    bool build_list(TreeNode *root,TreeNode *node,list<TreeNode*> &ll)
{
    if(node==root)
    {
        //ll.push_back(root);
        return true;
    }
    if(root==NULL)
        return false;
    bool a=build_list(root->left,node,ll);
    bool b=build_list(root->right,node,ll);
    if(a)
    {
        ll.push_front(root->left);
        return true;
    }
    else if(b)
    {
        ll.push_front(root->right);
        return true;
    }
    else
        return false;
}

    TreeNode* find_common_node(list<TreeNode*> &pp,list<TreeNode*> &qq)
    {
        if(pp.size()>qq.size())
        {
            int t=pp.size()-qq.size();
            auto i=pp.end();
            auto j=qq.end();
            i--;
            j--;
            for(;t>0;t--,i--);
            while(*i!=*j)
            {
                i--;
                j--;
            }
            return *i;
        }
        else
        {
            int t=qq.size()-pp.size();
            auto i=qq.end();
            auto j=pp.end();
            i--;
            j--;
            for(;t>0;t--,i--);
            while(*i!=*j)
            {
                i--;
                j--;
            }
            return *i;
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if(root==NULL)
            return NULL;
        if(p==NULL)
            return q;
        if(q==NULL)
            return p;
        list<TreeNode*> pp,qq;
        build_list(root,p,pp);
        pp.push_front(root);
        build_list(root,q,qq);
        qq.push_front(root);
        return find_common_node(pp,qq);
    }
};
