/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 *
 * https://leetcode-cn.com/problems/minimum-path-sum/description/
 *
 * algorithms
 * Medium (68.78%)
 * Likes:    989
 * Dislikes: 0
 * Total Accepted:    260.6K
 * Total Submissions: 378.8K
 * Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
 *
 * 给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
 * 
 * 说明：每次只能向下或者向右移动一步。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：grid = [[1,3,1],[1,5,1],[4,2,1]]
 * 输出：7
 * 解释：因为路径 1→3→1→1→1 的总和最小。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：grid = [[1,2,3],[4,5,6]]
 * 输出：12
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == grid.length
 * n == grid[i].length
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
    int minPathSum(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> dp(rows, vector(cols, 0));
        //init dp table
        dp[0][0] = grid[0][0];
        for (size_t row = 1; row < rows; row++)
        {
            dp[row][0] = dp[row - 1][0] + grid[row][0];
        }
        for (size_t col = 1; col < cols; col++)
        {
            dp[0][col] = dp[0][col - 1] + grid[0][col];
        }
        //init end

        for (size_t row = 1; row < rows; row++)
        {
            for (size_t col = 1; col < cols; col++)
            {
                dp[row][col] = (dp[row - 1][col] < dp[row][col - 1] ? dp[row - 1][col] : dp[row][col - 1]) + grid[row][col];
            }
        }
        return dp[rows - 1][cols - 1];
    }
};
// @lc code=end
