/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 *
 * https://leetcode-cn.com/problems/unique-binary-search-trees/description/
 *
 * algorithms
 * Medium (69.12%)
 * Likes:    875
 * Dislikes: 0
 * Total Accepted:    90.6K
 * Total Submissions: 131K
 * Testcase Example:  '3'
 *
 * 给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？
 * 
 * 示例:
 * 
 * 输入: 3
 * 输出: 5
 * 解释:
 * 给定 n = 3, 一共有 5 种不同结构的二叉搜索树:
 * 
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
 * 
 */

// @lc code=start
#include <vector>
class Solution
{
public:
    int numTrees(int n)
    {
        std::vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                //左右子树类型数量的积
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};
// @lc code=end
