/*
 * @lc app=leetcode.cn id=686 lang=cpp
 *
 * [686] 重复叠加字符串匹配
 *
 * https://leetcode-cn.com/problems/repeated-string-match/description/
 *
 * algorithms
 * Medium (35.81%)
 * Likes:    253
 * Dislikes: 0
 * Total Accepted:    41.9K
 * Total Submissions: 104.7K
 * Testcase Example:  '"abcd"\n"cdabcdab"'
 *
 * 给定两个字符串 a 和 b，寻找重复叠加字符串 a 的最小次数，使得字符串 b 成为叠加后的字符串 a 的子串，如果不存在则返回 -1。
 *
 * 注意：字符串 "abc" 重复叠加 0 次是 ""，重复叠加 1 次是 "abc"，重复叠加 2 次是 "abcabc"。
 *
 *
 *
 * 示例 1：
 *
 * 输入：a = "abcd", b = "cdabcdab"
 * 输出：3
 * 解释：a 重复叠加三遍后为 "abcdabcdabcd", 此时 b 是其子串。
 *
 *
 * 示例 2：
 *
 * 输入：a = "a", b = "aa"
 * 输出：2
 *
 *
 * 示例 3：
 *
 * 输入：a = "a", b = "a"
 * 输出：1
 *
 *
 * 示例 4：
 *
 * 输入：a = "abc", b = "wxyz"
 * 输出：-1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= a.length <= 10^4
 * 1 <= b.length <= 10^4
 * a 和 b 由小写英文字母组成
 *
 *
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class KMP
{
private:
    vector<vector<int>> trans;
    string pat;

public:
    int search(string txt)
    {
        int txtsize = txt.size();
        if (this->pat == "")
            return 0;
        for (int txtIdx = 0, patIdx = 0; txtIdx - patIdx < txtsize; txtIdx++)
        {
            patIdx = trans[patIdx][txt[txtIdx % txtsize] - 'a'];
            if (patIdx == this->pat.size())
                return txtIdx - pat.size() + 1;
        }
        return -1;
    }
    KMP(string a)
    {
        pat = a;
        if (pat == "")
            return;
        trans.resize(a.size(), vector<int>(26, 0));
        // init status
        trans[0][pat[0] - 'a'] = 1;
        int prev = 0;
        for (int curStatus = 1; curStatus < pat.size(); curStatus++)
        {
            for (int idx = 0; idx < 26; idx++)
                trans[curStatus][idx] = trans[prev][idx];
            trans[curStatus][pat[curStatus] - 'a'] = curStatus + 1;
            prev = trans[prev][pat[curStatus] - 'a'];
        }
    }
    ~KMP() {}
};
class Solution
{
public:
    int repeatedStringMatch(string a, string b)
    {
        KMP kmp(b);
        int idx = kmp.search(a);
        if (idx == -1)
            return -1;
        if (a.size() - idx >= b.size())
            return 1;
        return (idx + b.size() - 1 - a.size()) / a.size() + 1 + 1;
    }
};
// @lc code=end
