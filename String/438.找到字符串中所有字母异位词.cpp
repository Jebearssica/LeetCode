/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 *
 * https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/description/
 *
 * algorithms
 * Medium (51.74%)
 * Likes:    626
 * Dislikes: 0
 * Total Accepted:    95.6K
 * Total Submissions: 184.4K
 * Testcase Example:  '"cbaebabacd"\n"abc"'
 *
 * 给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。
 * 
 * 异位词 指字母相同，但排列不同的字符串。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: s = "cbaebabacd", p = "abc"
 * 输出: [0,6]
 * 解释:
 * 起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
 * 起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: s = "abab", p = "ab"
 * 输出: [0,1,2]
 * 解释:
 * 起始索引等于 0 的子串是 "ab", 它是 "ab" 的异位词。
 * 起始索引等于 1 的子串是 "ba", 它是 "ab" 的异位词。
 * 起始索引等于 2 的子串是 "ab", 它是 "ab" 的异位词。
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 
 * s 和 p 仅包含小写字母
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        unordered_map<char, int> need, window;
        for (char ch : p)
            need[ch]++;

        vector<int> res;
        int left = 0, right = 0;
        int valid = 0;
        while (right < s.size())
        {
            char chIn = s[right++];
            if (need.count(chIn))
            {
                window[chIn]++;
                if (window[chIn] == need[chIn])
                    valid++;
            }
            while (right - left >= p.size())
            {
                if (valid == need.size())
                    res.push_back(left);
                char chOut = s[left++];
                if (need.count(chOut))
                {
                    if (window[chOut] == need[chOut])
                        valid--;
                    window[chOut]--;
                }
            }
        }
        return res;
    }
};
// @lc code=end
