/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 *
 * https://leetcode-cn.com/problems/sliding-window-maximum/description/
 *
 * algorithms
 * Hard (49.66%)
 * Likes:    1260
 * Dislikes: 0
 * Total Accepted:    207.6K
 * Total Submissions: 418K
 * Testcase Example:  '[1,3,-1,-3,5,3,6,7]\n3'
 *
 * 给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k
 * 个数字。滑动窗口每次只向右移动一位。
 * 
 * 返回滑动窗口中的最大值。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
 * 输出：[3,3,5,5,6,7]
 * 解释：
 * 滑动窗口的位置                最大值
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 * ⁠1 [3  -1  -3] 5  3  6  7       3
 * ⁠1  3 [-1  -3  5] 3  6  7       5
 * ⁠1  3  -1 [-3  5  3] 6  7       5
 * ⁠1  3  -1  -3 [5  3  6] 7       6
 * ⁠1  3  -1  -3  5 [3  6  7]      7
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1], k = 1
 * 输出：[1]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [1,-1], k = 1
 * 输出：[1,-1]
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：nums = [9,11], k = 2
 * 输出：[11]
 * 
 * 
 * 示例 5：
 * 
 * 
 * 输入：nums = [4,-2], k = 2
 * 输出：[4]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * -10^4 
 * 1 
 * 
 * 
 */

// @lc code=start
#include <queue>
using namespace std;
// class Node
// {
// public:
//     int val;
//     Node *next, *prev;
//     Node(int val) : val(val), next(nullptr), prev(nullptr)
//     {
//     }
// };
// //overrride STL:deque
// class DoubleLinkList
// {
// private:
//     Node *head, *tail;
//     int _size;

// public:
//     int size()
//     {
//         return this->_size;
//     }
//     void pushLast(int n)
//     {
//         Node *add = new Node(n);
//         add->prev = this->tail->prev;
//         add->next = this->tail;
//         this->tail->prev->next = add;
//         this->tail->prev = add;
//         this->_size++;
//     }
//     int getLast()
//     {
//         return this->tail->prev->val;
//     }
//     int getFirst()
//     {
//         return this->head->next->val;
//     }
//     void popLast()
//     {
//         Node *last = this->tail->prev;
//         last->prev->next = last->next;
//         last->next->prev = last->prev;
//         this->_size--;
//     }
//     void popFirst()
//     {
//         Node *first = this->head->next;
//         first->prev->next = first->next;
//         first->next->prev = first->prev;
//         this->_size--;
//     }
//     DoubleLinkList() : _size(0)
//     {
//         this->head = new Node(0);
//         this->tail = new Node(0);
//         this->head->next = this->tail;
//         this->tail->prev = this->head;
//     }
//     ~DoubleLinkList() {}
// };
// class MonotoneQueue
// {
// private:
//     DoubleLinkList dll;

// public:
//     void push(int n)
//     {
//         while (this->dll.size() != 0 && this->dll.getLast() < n)
//             this->dll.popLast();
//         this->dll.pushLast(n);
//     }
//     void pop(int n)
//     {
//         if (n == this->dll.getFirst())
//             this->dll.popFirst();
//     }
//     int maxValue()
//     {
//         return this->dll.getFirst();
//     }
//     MonotoneQueue() {}
//     ~MonotoneQueue() {}
// };
class MonotoneQueue
{
private:
    deque<int> q;

public:
    void push(int n)
    {
        while (!q.empty() && q.back() < n)
            this->q.pop_back();
        this->q.push_back(n);
    }
    void pop(int n)
    {
        if (n == this->q.front())
            this->q.pop_front();
    }
    int maxValue()
    {
        return this->q.front();
    }
    MonotoneQueue() {}
    ~MonotoneQueue() {}
};
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        MonotoneQueue q;
        vector<int> res;

        for (int idx = 0; idx < nums.size(); idx++)
        {
            q.push(nums[idx]);
            if (idx >= k - 1)
            {
                res.push_back(q.maxValue());
                q.pop(nums[idx - k + 1]);
            }
        }
        return res;
    }
};
// @lc code=end
