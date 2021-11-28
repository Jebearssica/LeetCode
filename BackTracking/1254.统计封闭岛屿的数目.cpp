/*
 * @lc app=leetcode.cn id=1254 lang=cpp
 *
 * [1254] 统计封闭岛屿的数目
 *
 * https://leetcode-cn.com/problems/number-of-closed-islands/description/
 *
 * algorithms
 * Medium (60.18%)
 * Likes:    103
 * Dislikes: 0
 * Total Accepted:    16K
 * Total Submissions: 26.5K
 * Testcase Example:  '[[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]'
 *
 * 有一个二维矩阵 grid ，每个位置要么是陆地（记号为 0 ）要么是水域（记号为 1 ）。
 * 
 * 我们从一块陆地出发，每次可以往上下左右 4 个方向相邻区域走，能走到的所有陆地区域，我们将其称为一座「岛屿」。
 * 
 * 如果一座岛屿 完全 由水域包围，即陆地边缘上下左右所有相邻区域都是水域，那么我们将其称为 「封闭岛屿」。
 * 
 * 请返回封闭岛屿的数目。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：grid =
 * [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
 * 输出：2
 * 解释：
 * 灰色区域的岛屿是封闭岛屿，因为这座岛屿完全被水域包围（即被 1 区域包围）。
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入：grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
 * 输出：1
 * 
 * 
 * 示例 3：
 * 
 * 输入：grid = [[1,1,1,1,1,1,1],
 * [1,0,0,0,0,0,1],
 * [1,0,1,1,1,0,1],
 * [1,0,1,0,1,0,1],
 * [1,0,1,1,1,0,1],
 * [1,0,0,0,0,0,1],
 * ⁠            [1,1,1,1,1,1,1]]
 * 输出：2
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= grid.length, grid[0].length <= 100
 * 0 <= grid[i][j] <=1
 * 
 * 
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    void dfs(vector<vector<int>> &grid, int row, int col)
    {
        //check the validation
        if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size())
            return;
        if (grid[row][col] == 1)
            return;
        grid[row][col] = 1;
        dfs(grid, row + 1, col);
        dfs(grid, row - 1, col);
        dfs(grid, row, col + 1);
        dfs(grid, row, col - 1);
    }
    int closedIsland(vector<vector<int>> &grid)
    {
        int res = 0;
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
        for (int row = 0; row < grid.size(); row++)
        {
            for (int col = 0; col < grid[0].size(); col++)
            {
                if (grid[row][col] == 0)
                {
                    res++;
                    dfs(grid, row, col);
                }
            }
        }
        return res;
    }
};
// @lc code=end
