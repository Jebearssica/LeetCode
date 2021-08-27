/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
 *
 * https://leetcode-cn.com/problems/rotate-list/description/
 *
 * algorithms
 * Medium (41.83%)
 * Likes:    614
 * Dislikes: 0
 * Total Accepted:    189.4K
 * Total Submissions: 452.8K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：head = [1,2,3,4,5], k = 2
 * 输出：[4,5,1,2,3]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：head = [0,1,2], k = 4
 * 输出：[2,0,1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中节点的数目在范围 [0, 500] 内
 * -100 
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
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head && k && head->next)
        {
            ListNode *nail, *result = nullptr;
            nail = head;
            int length = 1;
            while (nail->next)
            {
                nail = nail->next;
                length++;
            }
            //convert to loop link list
            nail->next = head;
            for (size_t i = 0; i < length - (k % length); i++)
            {
                nail = nail->next;
            }
            result = nail->next;
            nail->next = nullptr;
            return result;
        }
        else
        {
            return head;
        }
    }
};
// @lc code=end
