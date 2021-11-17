/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 *
 * https://leetcode-cn.com/problems/sudoku-solver/description/
 *
 * algorithms
 * Hard (67.04%)
 * Likes:    932
 * Dislikes: 0
 * Total Accepted:    97.3K
 * Total Submissions: 145K
 * Testcase Example:  '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
 *
 * 编写一个程序，通过填充空格来解决数独问题。
 * 
 * 数独的解法需 遵循如下规则：
 * 
 * 
 * 数字 1-9 在每一行只能出现一次。
 * 数字 1-9 在每一列只能出现一次。
 * 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）
 * 
 * 
 * 数独部分空格内已填入了数字，空白格用 '.' 表示。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 输入：board =
 * [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
 * 
 * 输出：[["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
 * 解释：输入的数独如上图所示，唯一有效的解决方案如下所示：
 * 
 * 
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * board.length == 9
 * board[i].length == 9
 * board[i][j] 是一位数字或者 '.'
 * 题目数据 保证 输入数独仅有一个解
 * 
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
public:
    vector<pair<int, int>> space;
    bool isValid(vector<vector<char>> &board, int row, int col, char digit)
    {
        //check the row and col
        for (int i = 0; i < 9; i++)
            if (board[i][col] == digit || board[row][i] == digit)
                return false;
        //check the 3x3 matrix
        for (int i = row / 3 * 3; i < row / 3 * 3 + 3; i++)
            for (int j = col / 3 * 3; j < col / 3 * 3 + 3; j++)
                if (board[i][j] == digit)
                    return false;
        return true;
    }
    bool backtracing(vector<vector<char>> &board, int pos)
    {
        if (pos == space.size())
            return true;
        auto [row, col] = space[pos];
        for (char digit = '1'; digit <= '9'; digit++)
        {
            if (!isValid(board, row, col, digit))
                continue;
            board[row][col] = digit;
            if (backtracing(board, pos + 1))
                return true;
            board[row][col] = '.';
        }
        return false;
    }
    void solveSudoku(vector<vector<char>> &board)
    {
        //find the empty space
        for (int row = 0; row < 9; row++)
            for (int col = 0; col < 9; col++)
                if (board[row][col] == '.')
                    space.emplace_back(row, col);
        backtracing(board, 0);
    }
};
// @lc code=end
