/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 *
 * https://leetcode-cn.com/problems/n-queens/description/
 *
 * algorithms
 * Hard (73.88%)
 * Likes:    1086
 * Dislikes: 0
 * Total Accepted:    162.1K
 * Total Submissions: 219.6K
 * Testcase Example:  '4'
 *
 * n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 * 
 * 给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。
 * 
 * 
 * 
 * 每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 4
 * 输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
 * 解释：如上图所示，4 皇后问题存在两个不同的解法。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 1
 * 输出：[["Q"]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 皇后彼此不能相互攻击，也就是说：任何两个皇后都不能处于同一条横行、纵行或斜线上。
 * 
 * 
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    vector<vector<string>> res;
    //在row固定的情况下判断合法性, 因此只需判断两个斜方向, col列方向一共三个方向的合法性
    bool isValid(vector<string> &board, int row, int col)
    {
        int size = board.size();
        //testing the col direction
        for (int i = 0; i < size; i++)
            if (board[i][col] == 'Q')
                return false;
        //testing the leftUp direction
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
            if (board[i][j] == 'Q')
                return false;
        //testing the rightUp direction
        for (int i = row - 1, j = col + 1; i >= 0 && j < size; i--, j++)
            if (board[i][j] == 'Q')
                return false;
        return true;
    }
    void backtracing(vector<string> &board, int row)
    {
        if (row == board.size())
        {
            res.push_back(board);
            return;
        }
        int colLength = board[row].size();
        for (int col = 0; col < colLength; col++)
        {
            if (!isValid(board, row, col))
                continue;
            board[row][col] = 'Q';
            backtracing(board, row + 1);
            board[row][col] = '.';
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> board(n, string(n, '.'));
        backtracing(board, 0);
        return res;
    }
};
// @lc code=end
