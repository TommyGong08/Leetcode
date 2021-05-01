/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 *
 * https://leetcode-cn.com/problems/remove-linked-list-elements/description/
 *
 * algorithms
 * Easy (47.92%)
 * Likes:    586
 * Dislikes: 0
 * Total Accepted:    154.7K
 * Total Submissions: 322.3K
 * Testcase Example:  '[1,2,6,3,4,5,6]\n6'
 *
 * 给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：head = [1,2,6,3,4,5,6], val = 6
 * 输出：[1,2,3,4,5]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：head = [], val = 1
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：head = [7,7,7,7], val = 7
 * 输出：[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 列表中的节点在范围 [0, 10^4] 内
 * 1 
 * 0 
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* sd = new ListNode(0);
        sd->next = head;
        ListNode* curr = head;
        ListNode* prev = sd;
        while(curr != nullptr){
            //比较当前节点和要删除的节点
            if(curr->val == val){
                prev->next = curr->next;
            }
            else{
                prev = curr;
            }
            curr = curr->next;
        }
        return sd->next;
    }
};
// @lc code=end

/*
算法：

初始化哨兵节点为 ListNode(0) 且设置 sentinel.next = head。
初始化两个指针 curr 和 prev 指向当前节点和前继节点。
当 curr != nullptr：
    比较当前节点和要删除的节点：
        若当前节点就是要删除的节点：则 prev.next = curr.next。
        否则设 prev = curr。
    遍历下一个元素：curr = curr.next。
返回 sentinel.next。

作者：LeetCode
链接：https://leetcode-cn.com/problems/remove-linked-list-elements/solution/yi-chu-lian-biao-yuan-su-by-leetcode/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

