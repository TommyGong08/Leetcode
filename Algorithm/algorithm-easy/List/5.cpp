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
    bool isPalindrome(ListNode* head) {
        //将每个值压入堆栈
        vector<int> v;
        ListNode* p = head;
        while(p != NULL){
            v.push_back(p->val);
            p = p->next;
        }
        int i=0;
        int flag = 1;
        while(i < v.size()){
            if(v[i] == v.back()){
                v.pop_back();
                i++;
            }
            else{
                flag = 0;
                break;
            }
        }
        if(flag == 0) return false;
        else return true;
    }
};