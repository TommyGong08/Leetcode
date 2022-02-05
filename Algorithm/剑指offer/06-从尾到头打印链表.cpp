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
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        while(head!=NULL){
            res.push_back(head->val);
            head = head->next;
        }
        int temp_num = 0;
        int len = res.size();
        for(int i = 0; i < len/2; i++){
            temp_num = res[len-1-i];
            res[len-i-1] = res[i];
            res[i] = temp_num;
        }
        return res;
    }
};