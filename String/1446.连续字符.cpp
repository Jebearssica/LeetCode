/*
 * @lc app=leetcode.cn id=1446 lang=cpp
 *
 * [1446] 连续字符
 *
 * https://leetcode-cn.com/problems/consecutive-characters/description/
 *
 * algorithms
 * Easy (57.59%)
 * Likes:    60
 * Dislikes: 0
 * Total Accepted:    31K
 * Total Submissions: 50.6K
 * Testcase Example:  '"leetcode"'
 *
 * 给你一个字符串 s ，字符串的「能量」定义为：只包含一种字符的最长非空子字符串的长度。
 *
 * 请你返回字符串的能量。
 *
 *
 *
 * 示例 1：
 *
 * 输入：s = "leetcode"
 * 输出：2
 * 解释：子字符串 "ee" 长度为 2 ，只包含字符 'e' 。
 *
 *
 * 示例 2：
 *
 * 输入：s = "abbcccddddeeeeedcba"
 * 输出：5
 * 解释：子字符串 "eeeee" 长度为 5 ，只包含字符 'e' 。
 *
 *
 * 示例 3：
 *
 * 输入：s = "triplepillooooow"
 * 输出：5
 *
 *
 * 示例 4：
 *
 * 输入：s = "hooraaaaaaaaaaay"
 * 输出：11
 *
 *
 * 示例 5：
 *
 * 输入：s = "tourist"
 * 输出：1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 500
 * s 只包含小写英文字母。
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int maxPower(string s)
    {
        int res = 1, cnt = 1;
        for (int idx = 1; idx < s.size(); idx++)
        {
            if (s[idx - 1] == s[idx])
            {
                cnt++;
                res = max(res, cnt);
            }
            else
                cnt = 1;
        }
        return res;
    }
};
// @lc code=end
