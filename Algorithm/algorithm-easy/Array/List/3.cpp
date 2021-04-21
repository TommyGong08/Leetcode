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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return head;
        if(head -> next == NULL) return head;
        if(head ->next->next == NULL ) {
            ListNode* q= head->next;
            head->next->next = head;
            head->next = NULL;
            return q;
        } 
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* p = dummy;
        ListNode* q = head;
        ListNode* m = head->next;
        while( m->next ){
            q->next = p;
            p = q;
            q = m;
            m=m->next;
        }
        delete head->next;
        head->next = NULL;
        q->next = p;
        m->next = q;
        return m;
    }
};