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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //采用距离n的双指针
        ListNode* dummy = new ListNode(0);//哑节点
        if(head == NULL) return head;
        dummy->next = head;
        ListNode* p=dummy;//前指针
        ListNode* q=dummy;//后指针
        int k=n;
        while(k--){
            p=p->next;
        }
        while(p->next){
            p=p->next;
            q=q->next;
        }
        ListNode* del=q->next;
        q->next=q->next->next;
        delete del;
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
};