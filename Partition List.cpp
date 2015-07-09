/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5. 
*/
//思路：把链表的位置存在一个vector里,然后在vector里找大于等于x的数，再从这个数后面开始找小于它的数，插入到x前面
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) 
    {
        if(head==NULL)
            return NULL;
        vector<ListNode*> temp;
        int i;
        ListNode* tt=head;
        while(tt!=NULL)
        {
            temp.push_back(tt);
            tt=tt->next;
        }
        for(i=0;i<temp.size();i++)
        {
            if(temp[i]->val>=x)
                break;
        }
        for(int j=i+1;j<temp.size();j++)
        {
            if(temp[j]->val<x)
            {
                ListNode* a=temp[j];
                for(int ii=j-1;ii>=i;ii--)
                {
                    temp[ii+1]=temp[ii];
                }
                temp[i]=a;
                i++;
            }
            if(i>=temp.size())
                break;
        }
        for(i=0;i<temp.size()-1;i++)
        {
            temp[i]->next=temp[i+1];
        }
        temp[i]->next=NULL;
        return temp[0];
    }
};
