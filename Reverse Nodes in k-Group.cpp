/* Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5 */
//思路：原子操作是单链表的反转，基本方法是设置一个哨兵节点，从第一个节点开始，依次把节点插入到哨兵节点后面
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
    //返回反转完的链表的最后一个节点
    ListNode* reverseList(ListNode* head,ListNode* node)
    {
        ListNode* head_temp,*node_temp;
        while(node)
        {
            head_temp=head->next;
            node_temp=node->next;
            head->next=node;
            node->next=head_temp;
            node=node_temp;
        }
        while(head->next)
        {
            head=head->next;
        }
        return head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        ListNode *hh=new ListNode(1),*first=head,*last=head,*temp;
        int flag=1;
        if(head==NULL||head->next==NULL||k==1)
            return head;
        for(int i=1;i<k;i++)
        {
            last=last->next;
            if(last==NULL)
                return head;
        }
        temp=last->next;
        last->next=NULL;
        last=reverseList(hh,first);
        head=hh->next;
        hh=last;
        first=temp;
        last=temp;
        if(!first)
            flag=0;
        while(flag)
        {
            for(int i=1;i<k;i++)
            {
                last=last->next;
                if(last==NULL)
                {
                    hh->next=first;
                    return head;
                }
            }
            temp=last->next;
            last->next=NULL;
            last=reverseList(hh,first);
            hh=last;
            first=temp;
            last=temp; 
            if(!first)
                flag=0;
        }
        return head;
        
    }
};
