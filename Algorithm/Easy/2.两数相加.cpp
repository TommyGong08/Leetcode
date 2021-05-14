/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 *
 * https://leetcode-cn.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (39.98%)
 * Likes:    6078
 * Dislikes: 0
 * Total Accepted:    805.7K
 * Total Submissions: 2M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * 给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
 * 
 * 请你将两个数相加，并以相同形式返回一个表示和的链表。
 * 
 * 你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：l1 = [2,4,3], l2 = [5,6,4]
 * 输出：[7,0,8]
 * 解释：342 + 465 = 807.
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：l1 = [0], l2 = [0]
 * 输出：[0]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
 * 输出：[8,9,9,9,0,0,0,1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 每个链表中的节点数在范围 [1, 100] 内
 * 0 
 * 题目数据保证列表表示的数字不含前导零
 * 
 * 
 */

// @lc code=start
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int flag = 0;//用于记录进位
        int sum = 0;//用于记录和
        ListNode* head = new ListNode();
        ListNode* p = head;
        while(l1 != nullptr || l2 != nullptr){
            if(l1 != nullptr && l2 != nullptr){
                if(flag == 1) sum = l1->val + l2->val + 1;
                else if(flag == 0) sum = l1->val + l2->val;
                l1 = l1->next;
                l2 = l2->next;
            }
            else if(l1 == nullptr && l2 != nullptr){
                if(flag == 1) sum = l2->val + 1;
                else if(flag == 0) sum = l2->val;
                l2 = l2 -> next;
            }
            else{
                if(flag == 1) sum = l1->val + 1;
                else if(flag == 0) sum = l1->val;
                l1 = l1 -> next;
            }
            //有进位
            if(sum >= 10){
                flag = 1;
                sum -= 10;
            }
            else{
                //sum < 10
                flag = 0;
            }
            p->next = new ListNode(sum);
            p = p->next;
        }
        if(flag == 1) p->next = new ListNode(1);
        return head->next;
    } 
};
// @lc code=end

