/*
 * @lc app=leetcode.cn id=931 lang=cpp
 *
 * [931] 下降路径最小和
 *
 * https://leetcode-cn.com/problems/minimum-falling-path-sum/description/
 *
 * algorithms
 * Medium (65.85%)
 * Likes:    111
 * Dislikes: 0
 * Total Accepted:    18.5K
 * Total Submissions: 28.1K
 * Testcase Example:  '[[2,1,3],[6,5,4],[7,8,9]]'
 *
 * 给你一个 n x n 的 方形 整数数组 matrix ，请你找出并返回通过 matrix 的下降路径 的 最小和 。
 * 
 * 下降路径
 * 可以从第一行中的任何元素开始，并从每一行中选择一个元素。在下一行选择的元素和当前行所选元素最多相隔一列（即位于正下方或者沿对角线向左或者向右的第一个元素）。具体来说，位置
 * (row, col) 的下一个元素应当是 (row + 1, col - 1)、(row + 1, col) 或者 (row + 1, col + 1)
 * 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：matrix = [[2,1,3],[6,5,4],[7,8,9]]
 * 输出：13
 * 解释：下面是两条和最小的下降路径，用加粗+斜体标注：
 * [[2,1,3],      [[2,1,3],
 * ⁠[6,5,4],       [6,5,4],
 * ⁠[7,8,9]]       [7,8,9]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：matrix = [[-19,57],[-40,-5]]
 * 输出：-59
 * 解释：下面是一条和最小的下降路径，用加粗+斜体标注：
 * [[-19,57],
 * ⁠[-40,-5]]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：matrix = [[-48]]
 * 输出：-48
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == matrix.length
 * n == matrix[i].length
 * 1 <= n <= 100
 * -100 <= matrix[i][j] <= 100
 * 
 * 
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> dpTable;
    int min(int a, int b, int c)
    {
        int temp = b < c ? b : c;
        return a < temp ? a : temp;
    }
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        vector<vector<int>> dp(m, vector<int>(m, 10001));
        int result = 10001;
        //init
        for (size_t col = 0; col < m; col++)
        {
            dp[0][col] = matrix[0][col];
        }
        for (size_t row = 1; row < m; row++)
        {
            for (size_t col = 0; col < m; col++)
            {
                int temp = dp[row - 1][col];
                if (col > 0)
                {
                    temp = temp < dp[row - 1][col - 1] ? temp : dp[row - 1][col - 1];
                }
                if (col < m - 1)
                {
                    temp = temp < dp[row - 1][col + 1] ? temp : dp[row - 1][col + 1];
                }
                dp[row][col] = matrix[row][col] + temp;
            }
        }

        for (auto value : dp[m-1])
        {
            result = result < value ? result : value;
        }

        return result;
    }
};
// @lc code=end
