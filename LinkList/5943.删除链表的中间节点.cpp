/*
 * @lc app=leetcode.cn id=5943 lang=cpp
 *
 * [5943] 删除链表的中间节点
 *
 * https://leetcode-cn.com/problems/delete-the-middle-node-of-a-linked-list/description/
 *
 * algorithms
 * Medium (58.63%)
 * Likes:    3
 * Dislikes: 0
 * Total Accepted:    4.1K
 * Total Submissions: 6.9K
 * Testcase Example:  '[1,3,4,7,1,2,6]'
 *
 * 给你一个链表的头节点 head 。删除 链表的 中间节点 ，并返回修改后的链表的头节点 head 。
 *
 * 长度为 n 链表的中间节点是从头数起第 ⌊n / 2⌋ 个节点（下标从 0 开始），其中 ⌊x⌋ 表示小于或等于 x 的最大整数。
 *
 *
 * 对于 n = 1、2、3、4 和 5 的情况，中间节点的下标分别是 0、1、1、2 和 2 。
 *
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入：head = [1,3,4,7,1,2,6]
 * 输出：[1,3,4,1,2,6]
 * 解释：
 * 上图表示给出的链表。节点的下标分别标注在每个节点的下方。
 * 由于 n = 7 ，值为 7 的节点 3 是中间节点，用红色标注。
 * 返回结果为移除节点后的新链表。
 *
 *
 * 示例 2：
 *
 *
 *
 *
 * 输入：head = [1,2,3,4]
 * 输出：[1,2,4]
 * 解释：
 * 上图表示给出的链表。
 * 对于 n = 4 ，值为 3 的节点 2 是中间节点，用红色标注。
 *
 *
 * 示例 3：
 *
 *
 *
 *
 * 输入：head = [2,1]
 * 输出：[2]
 * 解释：
 * 上图表示给出的链表。
 * 对于 n = 2 ，值为 1 的节点 1 是中间节点，用红色标注。
 * 值为 2 的节点 0 是移除节点 1 后剩下的唯一一个节点。
 *
 *
 *
 * 提示：
 *
 *
 * 链表中节点的数目在范围 [1, 10^5] 内
 * 1 <= Node.val <= 10^5
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
class Solution
{
public:
    ListNode *deleteMiddle(ListNode *head)
    {
        ListNode *dummyNode = new ListNode(0, head), *slow, *fast, *slowPrev;
        fast = head;
        slowPrev = dummyNode;
        slow = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
            slowPrev = slowPrev->next;
        }
        // delete slow
        slowPrev->next = slow->next;
        return dummyNode->next;
    }
};
// @lc code=end
