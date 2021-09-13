/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 *
 * https://leetcode-cn.com/problems/target-sum/description/
 *
 * algorithms
 * Medium (50.15%)
 * Likes:    892
 * Dislikes: 0
 * Total Accepted:    144.6K
 * Total Submissions: 291.7K
 * Testcase Example:  '[1,1,1,1,1]\n3'
 *
 * 给你一个整数数组 nums 和一个整数 target 。
 * 
 * 向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：
 * 
 * 
 * 例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。
 * 
 * 
 * 返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,1,1,1,1], target = 3
 * 输出：5
 * 解释：一共有 5 种方法让最终目标和为 3 。
 * -1 + 1 + 1 + 1 + 1 = 3
 * +1 - 1 + 1 + 1 + 1 = 3
 * +1 + 1 - 1 + 1 + 1 = 3
 * +1 + 1 + 1 - 1 + 1 = 3
 * +1 + 1 + 1 + 1 - 1 = 3
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1], target = 1
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 0 
 * 0 
 * -1000 
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <numeric>
using namespace std;
class Solution
{
public:
    int subset(vector<int> &nums, int target)
    {
        int length = nums.size();
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int row = 1; row <= length; row++)
        {
            for (int col = target; col >= 0; col--)
            {
                if (col >= nums[row - 1])
                    dp[col] = dp[col] + dp[col - nums[row - 1]];
                else
                    dp[col] = dp[col];
            }
        }

        return dp[target];
    }
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        //invalid
        if (target > sum || (sum - target) % 2 != 0)
            return 0;
        return subset(nums, (sum - target) / 2);
    }
};
// @lc code=end
