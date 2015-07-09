//Sort a linked list in O(n log n) time using constant space complexity.
//思路：采用归并排序，即递归地把链表的左半边和右半边进行排序，因为要把一段链表分成两份，所以需要找到一段链表的中点，这里用两个指针一个走一步，一个走两步来找中点
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
    ListNode* merge(ListNode* left,ListNode* right)
    {
        ListNode* rr=new ListNode(0);
        ListNode* head=rr;

        while(left!=NULL&&right!=NULL)
        {
            if(left->val>right->val)
            {
                head->next=right;
                right=right->next;
            }
            else
            {
                head->next=left;
                left=left->next;
            }
            head=head->next;
        }
        if(left==NULL)
            head->next=right;
        else
            head->next=left;
        head=rr->next;
        rr->next=NULL;
        delete rr;
        return head;
    }
    ListNode* mergesort(ListNode* head)
    {
        if(head==NULL||head->next==NULL)
            return head;
        ListNode *a=head,*b=head,*pre=NULL;
        while(b!=NULL&&b->next!=NULL)
        {
            pre=a;
            a=a->next;
            b=b->next->next;
        }
        pre->next=NULL;
        ListNode* left=mergesort(head);
        ListNode* right=mergesort(a);
        return merge(left,right);
    }
    ListNode* sortList(ListNode* head) 
    {
        if(head==NULL||head->next==NULL)
            return head;
        return mergesort(head);
    }
};
