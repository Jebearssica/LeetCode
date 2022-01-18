/*
 * @lc app=leetcode.cn id=1020 lang=cpp
 *
 * [1020] 飞地的数量
 *
 * https://leetcode-cn.com/problems/number-of-enclaves/description/
 *
 * algorithms
 * Medium (54.45%)
 * Likes:    58
 * Dislikes: 0
 * Total Accepted:    10.3K
 * Total Submissions: 18.9K
 * Testcase Example:  '[[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]'
 *
 * 给出一个二维数组 A，每个单元格为 0（代表海）或 1（代表陆地）。
 * 
 * 移动是指在陆地上从一个地方走到另一个地方（朝四个方向之一）或离开网格的边界。
 * 
 * 返回网格中无法在任意次数的移动中离开网格边界的陆地单元格的数量。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：[[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
 * 输出：3
 * 解释： 
 * 有三个 1 被 0 包围。一个 1 没有被包围，因为它在边界上。
 * 
 * 示例 2：
 * 
 * 输入：[[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
 * 输出：0
 * 解释：
 * 所有 1 都在边界上或可以到达边界。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= A.length <= 500
 * 1 <= A[i].length <= 500
 * 0 <= A[i][j] <= 1
 * 所有行的大小都相同
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
    void dfs(vector<vector<int>> &grid, int row, int col)
    {
        //check the validation
        if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size())
            return;
        if (grid[row][col] == 0)
            return;
        grid[row][col] = 0;
        dfs(grid, row + 1, col);
        dfs(grid, row - 1, col);
        dfs(grid, row, col + 1);
        dfs(grid, row, col - 1);
    }
    int numEnclaves(vector<vector<int>> &grid)
    {
        int sumArea = 0;
        //remove the edge island
        for (int row = 0; row < grid.size(); row++)
        {
            dfs(grid, row, 0);
            dfs(grid, row, grid[0].size() - 1);
        }
        for (int col = 0; col < grid[0].size(); col++)
        {
            dfs(grid, 0, col);
            dfs(grid, grid.size() - 1, col);
        }
        //sum
        for (int row = 0; row < grid.size(); row++)
            sumArea += accumulate(grid[row].begin(), grid[row].end(), 0);
        return sumArea;
    }
};
// @lc code=end
