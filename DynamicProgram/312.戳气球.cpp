/*
 * @lc app=leetcode.cn id=312 lang=cpp
 *
 * [312] 戳气球
 *
 * https://leetcode-cn.com/problems/burst-balloons/description/
 *
 * algorithms
 * Hard (68.60%)
 * Likes:    889
 * Dislikes: 0
 * Total Accepted:    63.5K
 * Total Submissions: 92.5K
 * Testcase Example:  '[3,1,5,8]'
 *
 * 有 n 个气球，编号为0 到 n - 1，每个气球上都标有一个数字，这些数字存在数组 nums 中。
 *
 * 现在要求你戳破所有的气球。戳破第 i 个气球，你可以获得 nums[i - 1] * nums[i] * nums[i + 1] 枚硬币。 这里的 i
 * - 1 和 i + 1 代表和 i 相邻的两个气球的序号。如果 i - 1或 i + 1 超出了数组的边界，那么就当它是一个数字为 1 的气球。
 *
 * 求所能获得硬币的最大数量。
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [3,1,5,8]
 * 输出：167
 * 解释：
 * nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
 * coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
 *
 * 示例 2：
 *
 *
 * 输入：nums = [1,5]
 * 输出：10
 *
 *
 *
 *
 * 提示：
 *
 *
 * n == nums.length
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
    int maxCoins(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        vector<int> points(n + 2, 1);
        for (int idx = 0; idx < n; idx++)
            points[idx + 1] = nums[idx];
        for (int row = n; row >= 0; --row)
            for (int col = row + 1; col < n + 2; col++)
                for (int k = row + 1; k < col; k++)
                    dp[row][col] = max(dp[row][col], dp[row][k] + dp[k][col] + points[row] * points[k] * points[col]);
        return dp[0][n + 1];
    }
};
// @lc code=end
