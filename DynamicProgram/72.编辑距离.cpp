/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 *
 * https://leetcode-cn.com/problems/edit-distance/description/
 *
 * algorithms
 * Hard (61.19%)
 * Likes:    1818
 * Dislikes: 0
 * Total Accepted:    171.3K
 * Total Submissions: 279.1K
 * Testcase Example:  '"horse"\n"ros"'
 *
 * 给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。
 * 
 * 你可以对一个单词进行如下三种操作：
 * 
 * 
 * 插入一个字符
 * 删除一个字符
 * 替换一个字符
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：word1 = "horse", word2 = "ros"
 * 输出：3
 * 解释：
 * horse -> rorse (将 'h' 替换为 'r')
 * rorse -> rose (删除 'r')
 * rose -> ros (删除 'e')
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：word1 = "intention", word2 = "execution"
 * 输出：5
 * 解释：
 * intention -> inention (删除 't')
 * inention -> enention (将 'i' 替换为 'e')
 * enention -> exention (将 'n' 替换为 'x')
 * exention -> exection (将 'n' 替换为 'c')
 * exection -> execution (插入 'u')
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * word1 和 word2 由小写英文字母组成
 * 
 * 
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    int min(int a, int b, int c)
    {
        int temp = a < b ? a : b;
        return temp < c ? temp : c;
    }
    int minDistance(string word1, string word2)
    {
        int rows = word1.size(), cols = word2.size();
        // vector<vector<int>> dp(rows + 1, vector<int>(cols + 1, 0));
        vector<int> dp(cols + 1, 0);
        // for (int row = 1; row <= rows; row++)
        // {
        //     dp[row][0] = row;
        // }
        // for (int col = 1; col <= cols; col++)
        // {
        //     dp[0][col] = col;
        // }
        for (int col = 1; col <= cols; col++)
        {
            dp[col] = col;
        }
        for (int row = 1; row <= rows; row++)
        {
            int pre = dp[0];
            dp[0] = row;
            for (int col =  1; col <= cols; col++)
            {
                int temp = dp[col];
                if (word1[row - 1] == word2[col - 1])
                    // dp[row][col] = dp[row - 1][col - 1];
                    dp[col] = pre;
                else
                    // dp[row][col] = min(dp[row - 1][col], dp[row - 1][col - 1], dp[row][col - 1]) + 1;
                    dp[col] = min(pre, temp, dp[col - 1]) + 1;
                pre = temp;
            }
        }
        // return dp[rows][cols];
        return dp[cols];
    }
};
// @lc code=end
