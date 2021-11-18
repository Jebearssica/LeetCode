/*
 * @lc app=leetcode.cn id=673 lang=cpp
 *
 * [673] 最长递增子序列的个数
 *
 * https://leetcode-cn.com/problems/number-of-longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (39.22%)
 * Likes:    415
 * Dislikes: 0
 * Total Accepted:    33.2K
 * Total Submissions: 82K
 * Testcase Example:  '[1,3,5,4,7]'
 *
 * 给定一个未排序的整数数组，找到最长递增子序列的个数。
 * 
 * 示例 1:
 * 
 * 
 * 输入: [1,3,5,4,7]
 * 输出: 2
 * 解释: 有两个最长递增子序列，分别是 [1, 3, 4, 7] 和[1, 3, 5, 7]。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: [2,2,2,2,2]
 * 输出: 5
 * 解释: 最长递增子序列的长度是1，并且存在5个子序列的长度为1，因此输出5。
 * 
 * 
 * 注意: 给定的数组长度不超过 2000 并且结果一定是32位有符号整数。
 * 
 */

// @lc code=start
#include <vector>
#include <stack>
using namespace std;
class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
    {
        int length = nums.size(), piles = 0;
        stack<int> pilesStk;
        vector<int> top(length, 1);
        for (int i = 0; i < length; i++)
        {
            int cur = nums[i];
            int left = 0, right = piles;
            while (left < right)
            {
                int mid = left + (right - left) / 2;
                if (top[mid] >= cur)
                    right = mid;
                else
                    left = mid + 1;
            }
            if (left == piles)
                piles++;
            top[left] = cur;
        }
    }
};
// @lc code=end
