/*
 * @lc app=leetcode.cn id=1312 lang=cpp
 *
 * [1312] 让字符串成为回文串的最少插入次数
 *
 * https://leetcode-cn.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/
 *
 * algorithms
 * Hard (67.09%)
 * Likes:    126
 * Dislikes: 0
 * Total Accepted:    12.4K
 * Total Submissions: 18.5K
 * Testcase Example:  '"zzazz"'
 *
 * 给你一个字符串 s ，每一次操作你都可以在字符串的任意位置插入任意字符。
 *
 * 请你返回让 s 成为回文串的 最少操作次数 。
 *
 * 「回文串」是正读和反读都相同的字符串。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "zzazz"
 * 输出：0
 * 解释：字符串 "zzazz" 已经是回文串了，所以不需要做任何插入操作。
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "mbadm"
 * 输出：2
 * 解释：字符串可变为 "mbdadbm" 或者 "mdbabdm" 。
 *
 *
 * 示例 3：
 *
 *
 * 输入：s = "leetcode"
 * 输出：5
 * 解释：插入 5 个字符后字符串变为 "leetcodocteel" 。
 *
 *
 * 示例 4：
 *
 *
 * 输入：s = "g"
 * 输出：0
 *
 *
 * 示例 5：
 *
 *
 * 输入：s = "no"
 * 输出：1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 500
 * s 中所有字符都是小写字母。
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
    int minInsertions(string s)
    {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int left = n - 1; left >= 0; --left)
        {
            for (int right = left + 1; right < n; ++right)
            {
                if (s[left] == s[right])
                    dp[left][right] = dp[left + 1][right - 1];
                else
                    dp[left][right] = min(dp[left + 1][right], dp[left][right - 1]) + 1;
            }
        }
        return dp[0][n - 1];
    }
};
// @lc code=end
