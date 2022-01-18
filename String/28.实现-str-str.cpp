/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 *
 * https://leetcode-cn.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (40.30%)
 * Likes:    1174
 * Dislikes: 0
 * Total Accepted:    522K
 * Total Submissions: 1.3M
 * Testcase Example:  '"hello"\n"ll"'
 *
 * 实现 strStr() 函数。
 *
 * 给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串出现的第一个位置（下标从 0
 * 开始）。如果不存在，则返回  -1 。
 *
 *
 *
 * 说明：
 *
 * 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
 *
 * 对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与 C 语言的 strstr() 以及 Java 的 indexOf()
 * 定义相符。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：haystack = "hello", needle = "ll"
 * 输出：2
 *
 *
 * 示例 2：
 *
 *
 * 输入：haystack = "aaaaa", needle = "bba"
 * 输出：-1
 *
 *
 * 示例 3：
 *
 *
 * 输入：haystack = "", needle = ""
 * 输出：0
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0
 * haystack 和 needle 仅由小写英文字符组成
 *
 *
 */

// @lc code=start
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;
class KMP
{
private:
    vector<vector<int>> dp;
    string pat;

public:
    KMP(string pat)
    {
        if (pat == "")
        {
            dp.resize(1, vector<int>(26, 0));
            return;
        }
        this->pat = pat;
        dp.resize(pat.size(), vector<int>(26, 0));
        dp[0][pat[0] - 'a'] = 1;
        int prevStatus = 0;
        for (int curStatus = 1; curStatus < pat.size(); curStatus++)
        {
            for (int next = 0; next < 26; next++)
                dp[curStatus][next] = dp[prevStatus][next];
            dp[curStatus][pat[curStatus] - 'a'] = curStatus + 1;
            prevStatus = dp[prevStatus][pat[curStatus] - 'a'];
        }
    }
    int search(string txt)
    {
        if (this->pat == "")
            return 0;
        int cur = 0;
        for (int idx = 0; idx < txt.size(); idx++)
        {
            cur = dp[cur][txt[idx] - 'a'];
            if (cur == pat.size())
                return idx - pat.size() + 1;
        }
        return -1;
    }
    ~KMP() {}
};
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        KMP kmp(needle);
        return kmp.search(haystack);
    }
};
// @lc code=end
