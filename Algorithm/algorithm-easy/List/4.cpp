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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        ListNode* p = l1;ListNode* q = l2;
        ListNode* m;
        ListNode* head;
        if(l1->val <= l2->val){
            head = l1;
            m = l1;
            p = p->next;
        } 
        else {
            head = l2;
            m = l2;
            q = q->next;
        }
        while(p !=NULL && q != NULL)
        {
            if(p->val < q->val){
                m->next = p;
                m = m->next;
                p = p->next;
            }
            else if(p->val == q->val){
                if(m->next == p){
                    m = m->next;
                    p = p->next;
                }
                else if(m->next == q){
                    m = m->next;
                    q = q->next;
                }
            }
            else{
                m->next = q;
                m = m->next;
                q = q->next;
            }
        }
        if( q != NULL ) m->next = q;
        else if(p != NULL ) m->next = p ; 
        return head;
    }
};