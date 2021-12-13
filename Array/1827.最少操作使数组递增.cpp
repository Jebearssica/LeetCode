/*
 * @lc app=leetcode.cn id=1827 lang=cpp
 *
 * [1827] 最少操作使数组递增
 *
 * https://leetcode-cn.com/problems/minimum-operations-to-make-the-array-increasing/description/
 *
 * algorithms
 * Easy (79.39%)
 * Likes:    13
 * Dislikes: 0
 * Total Accepted:    10.6K
 * Total Submissions: 13.4K
 * Testcase Example:  '[1,1,1]'
 *
 * 给你一个整数数组 nums （下标从 0 开始）。每一次操作中，你可以选择数组中一个元素，并将它增加 1 。
 *
 *
 * 比方说，如果 nums = [1,2,3] ，你可以选择增加 nums[1] 得到 nums = [1,3,3] 。
 *
 *
 * 请你返回使 nums 严格递增 的 最少 操作次数。
 *
 * 我们称数组 nums 是 严格递增的 ，当它满足对于所有的 0 <= i < nums.length - 1 都有 nums[i] <
 * nums[i+1] 。一个长度为 1 的数组是严格递增的一种特殊情况。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [1,1,1]
 * 输出：3
 * 解释：你可以进行如下操作：
 * 1) 增加 nums[2] ，数组变为 [1,1,2] 。
 * 2) 增加 nums[1] ，数组变为 [1,2,2] 。
 * 3) 增加 nums[2] ，数组变为 [1,2,3] 。
 *
 *
 * 示例 2：
 *
 * 输入：nums = [1,5,2,4,1]
 * 输出：14
 *
 *
 * 示例 3：
 *
 * 输入：nums = [8]
 * 输出：0
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 5000
 * 1 <= nums[i] <= 10^4
 *
 *
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int prev = nums[0], res = 0;
        for (int idx = 1; idx < nums.size(); idx++)
        {
            if (nums[idx] <= prev)
            {
                res += prev + 1 - nums[idx];
                prev++;
            }
            else
                prev = nums[idx];
        }
        return res;
    }
};
// @lc code=end
