/*
 * @lc app=leetcode.cn id=1034 lang=cpp
 *
 * [1034] 边界着色
 *
 * https://leetcode-cn.com/problems/coloring-a-border/description/
 *
 * algorithms
 * Medium (44.07%)
 * Likes:    98
 * Dislikes: 0
 * Total Accepted:    17.2K
 * Total Submissions: 31.9K
 * Testcase Example:  '[[1,1],[1,2]]\n0\n0\n3'
 *
 * 给你一个大小为 m x n 的整数矩阵 grid ，表示一个网格。另给你三个整数 row、col 和 color
 * 。网格中的每个值表示该位置处的网格块的颜色。
 *
 * 两个网格块属于同一 连通分量 需满足下述全部条件：
 *
 *
 * 两个网格块颜色相同
 * 在上、下、左、右任意一个方向上相邻
 *
 *
 * 连通分量的边界 是指连通分量中满足下述条件之一的所有网格块：
 *
 *
 * 在上、下、左、右四个方向上与不属于同一连通分量的网格块相邻
 * 在网格的边界上（第一行/列或最后一行/列）
 *
 *
 * 请你使用指定颜色 color 为所有包含网格块 grid[row][col] 的 连通分量的边界 进行着色，并返回最终的网格 grid 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：grid = [[1,1],[1,2]], row = 0, col = 0, color = 3
 * 输出：[[3,3],[3,2]]
 *
 * 示例 2：
 *
 *
 * 输入：grid = [[1,2,2],[2,3,2]], row = 0, col = 1, color = 3
 * 输出：[[1,3,3],[2,3,3]]
 *
 * 示例 3：
 *
 *
 * 输入：grid = [[1,1,1],[1,1,1],[1,1,1]], row = 1, col = 1, color = 2
 * 输出：[[2,2,2],[2,1,2],[2,2,2]]
 *
 *
 *
 * 提示：
 *
 *
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 50
 * 1 <= grid[i][j], color <= 1000
 * 0 <= row < m
 * 0 <= col < n
 *
 *
 *
 *
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
private:
    vector<vector<bool>> visisted;
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    // return whether is border
    void dfs(vector<vector<int>> &grid, int row, int col, int target)
    {
        if (visisted[row][col])
            return;
        visisted[row][col] = true;
        if (grid[row][col] != target)
            return;
        // dfs along with 4 dir
        int borderCheck = 0;
        for (int i = 0; i < 4; i++)
        {
            int tempRow = row + dir[i][0];
            int tempCol = col + dir[i][1];
            if (tempRow >= 0 && tempRow < grid.size() && tempCol >= 0 && tempCol < grid[0].size())
            {
                if (grid[tempRow][tempCol] == target || grid[tempRow][tempCol] == 0)
                {
                    borderCheck++;
                    dfs(grid, tempRow, tempCol, target);
                }
            }
        }
        // is border
        if (borderCheck != 4)
            grid[row][col] = 0;
    }
    vector<vector<int>> colorBorder(vector<vector<int>> &grid, int row, int col, int color)
    {
        visisted.resize(grid.size(), vector<bool>(grid[0].size(), false));
        dfs(grid, row, col, grid[row][col]);
        for (int row = 0; row < grid.size(); row++)
        {
            for (int col = 0; col < grid[0].size(); col++)
            {
                if (grid[row][col] == 0)
                    grid[row][col] = color;
            }
        }
        return grid;
    }
};
// @lc code=end
