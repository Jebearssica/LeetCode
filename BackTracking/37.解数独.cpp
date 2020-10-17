/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 *
 * https://leetcode-cn.com/problems/sudoku-solver/description/
 *
 * algorithms
 * Hard (66.59%)
 * Likes:    660
 * Dislikes: 0
 * Total Accepted:    58.8K
 * Total Submissions: 88.3K
 * Testcase Example:  '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
 *
 * 编写一个程序，通过填充空格来解决数独问题。
 * 
 * 一个数独的解法需遵循如下规则：
 * 
 * 
 * 数字 1-9 在每一行只能出现一次。
 * 数字 1-9 在每一列只能出现一次。
 * 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
 * 
 * 
 * 空白格用 '.' 表示。
 * 
 * 
 * 
 * 一个数独。
 * 
 * 
 * 
 * 答案被标成红色。
 * 
 * 提示：
 * 
 * 
 * 给定的数独序列只包含数字 1-9 和字符 '.' 。
 * 你可以假设给定的数独只有唯一解。
 * 给定数独永远是 9x9 形式的。
 * 
 * 
 */

// @lc code=start
#include <vector>
class Solution
{
public:
    /*
    m19: matrix 1*9
    m91: matrix 9*1
    m33: matrix 3*3
    */
    int m19[9];
    int m91[9];
    int m33[3][3];
    bool valid;
    //将一对值合成为一个值, 储存空格的表
    std::vector<std::pair<int, int>> spaces;

    void insertNumber(int i, int j, int number)
    {
        m19[i] ^= (1 << number);
        m91[j] ^= (1 << number);
        m33[i / 3][j / 3] ^= (1 << number);
    }

    void dfs(std::vector<std::vector<char>> &board, int pos)
    {
        //遍历完了所有空格, 则成功
        if (pos == spaces.size())
        {
            valid = true;
            return;
        }
        //提出空格所在位置
        auto [i, j] = spaces[pos];
        //注意1~9一共有9位>8, 所以一共有两个字节0000 000'9' 8~1, 记得9的高位还有7个0
        //必须要全为0的地方才能叫做合法位置
        int ValidPos = ~(m19[i] | m91[j] | m33[i / 3][j / 3]) & 0x1ff;
        for (; ValidPos && !valid; ValidPos &= (ValidPos - 1))
        {
            //用的msvc compiler 找到最低位为1的后面的零的个数, 就能知道对应的数字是多少
            //leetcode 用的gcc...
            int number = __builtin_ctz(ValidPos & (-ValidPos));
            insertNumber(i, j, number);
            board[i][j] = number + '0' + 1;
            dfs(board, pos + 1);
            insertNumber(i, j, number);
        }
    }

    void solveSudoku(std::vector<std::vector<char>> &board)
    {
        //初始化
        memset(m19, 0, sizeof(m19));
        memset(m91, 0, sizeof(m91));
        memset(m33, 0, sizeof(m33));
        valid = false;

        //读取数据
        //列
        for (int i = 0; i < 9; i++)
            //行
            for (int j = 0; j < 9; j++)
                //空的
                //有数字的, 存入对应位置
                if (board[i][j] == '.')
                    spaces.emplace_back(i, j);
                else
                    insertNumber(i, j, int(board[i][j] - '0' - 1));
        //整个数独初始化完毕, 开始解
        dfs(board, 0);
    }
};
// @lc code=end
