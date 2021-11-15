/*
 * @lc app=leetcode.cn id=316 lang=cpp
 *
 * [316] 去除重复字母
 *
 * https://leetcode-cn.com/problems/remove-duplicate-letters/description/
 *
 * algorithms
 * Medium (47.63%)
 * Likes:    613
 * Dislikes: 0
 * Total Accepted:    70K
 * Total Submissions: 146.9K
 * Testcase Example:  '"bcabc"'
 *
 * 给你一个字符串 s ，请你去除字符串中重复的字母，使得每个字母只出现一次。需保证 返回结果的字典序最小（要求不能打乱其他字符的相对位置）。
 * 
 * 注意：该题与 1081
 * https://leetcode-cn.com/problems/smallest-subsequence-of-distinct-characters
 * 相同
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "bcabc"
 * 输出："abc"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "cbacdcbc"
 * 输出："acdb"
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * s 由小写英文字母组成
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
    string removeDuplicateLetters(string s)
    {
        vector<int> cnt(26, 0);
        vector<bool> isInStack(26, false);
        //count the char
        for (char ch : s)
            cnt[ch - 'a']++;
        string res;
        for (char ch : s)
        {
            cnt[ch - 'a']--;
            if (isInStack[ch - 'a'])
                continue;
            while (!res.empty() && res.back() > ch)
            {
                if (cnt[res.back() - 'a'] == 0)
                    break;
                isInStack[res.back() - 'a'] = false;
                res.pop_back();
            }
            res.push_back(ch);
            isInStack[ch - 'a'] = true;
        }
        return res;
    }
};
// @lc code=end
