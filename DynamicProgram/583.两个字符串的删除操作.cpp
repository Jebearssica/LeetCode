/*
 * @lc app=leetcode.cn id=583 lang=cpp
 *
 * [583] 两个字符串的删除操作
 *
 * https://leetcode-cn.com/problems/delete-operation-for-two-strings/description/
 *
 * algorithms
 * Medium (58.74%)
 * Likes:    257
 * Dislikes: 0
 * Total Accepted:    34.7K
 * Total Submissions: 57.6K
 * Testcase Example:  '"sea"\n"eat"'
 *
 * 给定两个单词 word1 和 word2，找到使得 word1 和 word2 相同所需的最小步数，每步可以删除任意一个字符串中的一个字符。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入: "sea", "eat"
 * 输出: 2
 * 解释: 第一步将"sea"变为"ea"，第二步将"eat"变为"ea"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 给定单词的长度不超过500。
 * 给定单词中的字符只含有小写字母。
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
    int minDistance(string word1, string word2)
    {
        int length1 = word1.size(), length2 = word2.size();
        vector<int> dp(length2 + 1, 0);
        for (int i = 1; i <= length1; i++)
        {
            auto ch1 = word1[i - 1];
            int upL = 0;
            for (int j = 1; j <= length2; j++)
            {
                int upR = dp[j];
                auto ch2 = word2[j - 1];
                if (ch1 == ch2)
                    dp[j] = upL + 1;
                else
                    dp[j] = max(dp[j - 1], upR);
                upL = upR;
            }
        }
        return length1 + length2 - 2 * dp[length2];
    }
};
// @lc code=end
