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
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode* head0 = new ListNode(0);
        head0->next = head;
        head = head0;
        while(head->next!=NULL){
            if(head->next->val == val){
                head->next = head->next->next;
            }
            else{
                head = head -> next;
            }
        }
        return head0->next;
    }
};