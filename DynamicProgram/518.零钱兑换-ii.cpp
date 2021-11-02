/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
 *
 * https://leetcode-cn.com/problems/coin-change-2/description/
 *
 * algorithms
 * Medium (65.80%)
 * Likes:    635
 * Dislikes: 0
 * Total Accepted:    111.9K
 * Total Submissions: 169.8K
 * Testcase Example:  '5\n[1,2,5]'
 *
 * 给你一个整数数组 coins 表示不同面额的硬币，另给一个整数 amount 表示总金额。
 * 
 * 请你计算并返回可以凑成总金额的硬币组合数。如果任何硬币组合都无法凑出总金额，返回 0 。
 * 
 * 假设每一种面额的硬币有无限个。 
 * 
 * 题目数据保证结果符合 32 位带符号整数。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：amount = 5, coins = [1, 2, 5]
 * 输出：4
 * 解释：有四种方式可以凑成总金额：
 * 5=5
 * 5=2+2+1
 * 5=2+1+1+1
 * 5=1+1+1+1+1
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：amount = 3, coins = [2]
 * 输出：0
 * 解释：只用面额 2 的硬币不能凑成总金额 3 。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：amount = 10, coins = [10] 
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 1 
 * coins 中的所有值 互不相同
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
    int change(int amount, vector<int> &coins)
    {
        // vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, 0));
        vector<int> dp(amount + 1, 0);
        //init
        // for (int i = 0; i <= coins.size(); i++)
        // {
        //     dp[i][0] = 1;
        // }
        dp[0] = 1;
        for (int i = 1; i <= coins.size(); i++)
        {
            for (int j = 1; j <= amount; j++)
            {
                // dp[i][j] = dp[i - 1][j];
                // if (j - coins[i - 1] >= 0)
                //     dp[i][j] += dp[i][j - coins[i - 1]];
                if (j - coins[i - 1] >= 0)
                    dp[j] += dp[j - coins[i - 1]];
            }
        }
        // return dp[coins.size()][amount];
        return dp[amount];
    }
};
// @lc code=end
