/*
 * @lc app=leetcode.cn id=516 lang=cpp
 *
 * [516] 最长回文子序列
 *
 * https://leetcode-cn.com/problems/longest-palindromic-subsequence/description/
 *
 * algorithms
 * Medium (65.03%)
 * Likes:    612
 * Dislikes: 0
 * Total Accepted:    82.3K
 * Total Submissions: 126.2K
 * Testcase Example:  '"bbbab"'
 *
 * 给你一个字符串 s ，找出其中最长的回文子序列，并返回该序列的长度。
 * 
 * 子序列定义为：不改变剩余字符顺序的情况下，删除某些字符或者不删除任何字符形成的一个序列。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "bbbab"
 * 输出：4
 * 解释：一个可能的最长回文子序列为 "bbbb" 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "cbbd"
 * 输出：2
 * 解释：一个可能的最长回文子序列为 "bb" 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * s 仅由小写英文字母组成
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
    int longestPalindromeSubseq(string s)
    {
        int length = s.size();
        // vector<vector<int>> dp(length, vector<int>(length, 0));
        // for (int i = 0; i < length; i++)
        //     dp[i][i] = 1;
        vector<int> dp(length, 1);
        for (int left = length - 1; left >= 0; left--)
        {
            int preValue = 0;
            for (int right = left + 1; right < length; right++)
            {
                int temp = dp[right];
                if (s[left] == s[right])
                {
                    // dp[left][right] = dp[left + 1][right - 1] + 2;
                    dp[right] = preValue + 2;
                }
                else
                {
                    // dp[left][right] = dp[left + 1][right] > dp[left][right - 1] ? dp[left + 1][right] : dp[left][right - 1];
                    dp[right] = dp[right - 1] > dp[right] ? dp[right - 1] : dp[right];
                }
                preValue = temp;
            }
        }
        return dp[length - 1];
    }
};
// @lc code=end
