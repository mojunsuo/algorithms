//K个一组翻转链表
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* first=new ListNode(0);
    ListNode* prev=first;
    ListNode*curr=head;
    ListNode* next;
    first->next=head;
    int length=0;
    while(head!=NULL)
    {
        length++;
        head=head->next;
    }
    head=first->next;
    for(int i=0;i<length/k;i++)
    {
        for(int j=0;j<k-1;j++)
        {
            next=curr->next;
            curr->next=next->next;
            next->next=prev->next;
            prev->next=next;
        }
        prev=curr;
        curr=prev->next;
    }
    return first->next;
    }
};