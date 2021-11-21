/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 *
 * https://leetcode-cn.com/problems/permutation-in-string/description/
 *
 * algorithms
 * Medium (43.11%)
 * Likes:    458
 * Dislikes: 0
 * Total Accepted:    119.3K
 * Total Submissions: 276.3K
 * Testcase Example:  '"ab"\n"eidbaooo"'
 *
 * 给你两个字符串 s1 和 s2 ，写一个函数来判断 s2 是否包含 s1 的排列。如果是，返回 true ；否则，返回 false 。
 * 
 * 换句话说，s1 的排列之一是 s2 的 子串 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s1 = "ab" s2 = "eidbaooo"
 * 输出：true
 * 解释：s2 包含 s1 的排列之一 ("ba").
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s1= "ab" s2 = "eidboaoo"
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s1.length, s2.length <= 10^4
 * s1 和 s2 仅包含小写字母
 * 
 * 
 */

// @lc code=start
#include <string>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        unordered_map<char, int> need, window;
        for (char ch : s1)
            need[ch]++;
        int left = 0, right = 0;
        int valid = 0;
        while (right < s2.size())
        {
            char chIn = s2[right++];
            if (need.count(chIn))
            {
                window[chIn]++;
                if (window[chIn] == need[chIn])
                    valid++;
            }

            while (right - left >= s1.size())
            {
                if (valid == need.size())
                    return true;
                char chOut = s2[left++];
                if (need.count(chOut))
                {
                    if (window[chOut] == need[chOut])
                        valid--;
                    window[chOut]--;
                }
            }
        }
        return false;
    }
};
// @lc code=end
