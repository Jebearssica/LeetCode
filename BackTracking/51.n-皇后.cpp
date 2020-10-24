/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 *
 * https://leetcode-cn.com/problems/n-queens/description/
 *
 * algorithms
 * Hard (73.09%)
 * Likes:    649
 * Dislikes: 0
 * Total Accepted:    85K
 * Total Submissions: 115.9K
 * Testcase Example:  '4'
 *
 * n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 * 
 * 
 * 
 * 上图为 8 皇后问题的一种解法。
 * 
 * 给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。
 * 
 * 每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：4
 * 输出：[
 * ⁠[".Q..",  // 解法 1
 * ⁠ "...Q",
 * ⁠ "Q...",
 * ⁠ "..Q."],
 * 
 * ⁠["..Q.",  // 解法 2
 * ⁠ "Q...",
 * ⁠ "...Q",
 * ⁠ ".Q.."]
 * ]
 * 解释: 4 皇后问题存在两个不同的解法。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 皇后彼此不能相互攻击，也就是说：任何两个皇后都不能处于同一条横行、纵行或斜线上。
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <string>
class Solution
{
public:
    std::vector<std::vector<std::string>> result;
    std::vector<std::string> currentBoard;
    void generateBoard(std::vector<int> &Queen, int n)
    {
        //通过Queen找到皇后位置, 并按行生成棋盘
        //其中Queen记录每行皇后所在位置
        currentBoard.clear();
        for (int i = 0; i < n; i++)
        {
            std::string rowLine = std::string(n, '.');
            rowLine[Queen[i]] = 'Q';
            currentBoard.push_back(rowLine);
        }
        result.push_back(currentBoard);
    }
    void backtracking(std::vector<int> &Queen, int rowIndex, int n, int column, int mainDiagnal, int subDiagnal)
    {
        if (rowIndex == n)
            generateBoard(Queen, n);
        else
        {
            int validPos = ((1 << n) - 1) & (~(column | mainDiagnal | subDiagnal));
            while (validPos != 0)
            {
                //找到皇后所在的列位置
                int position = validPos & ~(validPos);
                //末位 置零
                validPos = validPos & (validPos - 1);
                int columnPos = __builtin_ctz(position);
                Queen[rowIndex] = columnPos;
                backtracking(Queen, rowIndex + 1, n, column | position, (mainDiagnal | position) >> 1, (subDiagnal | position) << 1);
            }
        }
    }
    std::vector<std::vector<std::string>> solveNQueens(int n)
    {
        auto Queen = std::vector<int>(n, -1);
        backtracking(Queen, 0, n, 0, 0, 0);
        return result;
    }
};
// @lc code=end
