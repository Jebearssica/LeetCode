/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 *
 * https://leetcode-cn.com/problems/jump-game-ii/description/
 *
 * algorithms
 * Medium (43.69%)
 * Likes:    1385
 * Dislikes: 0
 * Total Accepted:    254.8K
 * Total Submissions: 582.2K
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * 给你一个非负整数数组 nums ，你最初位于数组的第一个位置。
 *
 * 数组中的每个元素代表你在该位置可以跳跃的最大长度。
 *
 * 你的目标是使用最少的跳跃次数到达数组的最后一个位置。
 *
 * 假设你总是可以到达数组的最后一个位置。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: nums = [2,3,1,1,4]
 * 输出: 2
 * 解释: 跳到最后一个位置的最小跳跃数是 2。
 * 从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
 *
 *
 * 示例 2:
 *
 *
 * 输入: nums = [2,3,0,1,4]
 * 输出: 2
 *
 *
 *
 *
 * 提示:
 *
 *
 * 1
 * 0
 *
 *
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int endIdx = 0, res = 0, maxIdx = 0;
        for (int idx = 0; idx < nums.size() - 1; ++idx)
        {
            maxIdx = max(maxIdx, idx + nums[idx]);
            if (endIdx == idx)
            {
                ++res;
                endIdx = maxIdx;
            }
        }
        return res;
    }
};
// @lc code=end
