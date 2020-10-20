/*
 * @lc app=leetcode.cn id=44 lang=cpp
 *
 * [44] 通配符匹配
 *
 * https://leetcode-cn.com/problems/wildcard-matching/description/
 *
 * algorithms
 * Hard (31.39%)
 * Likes:    545
 * Dislikes: 0
 * Total Accepted:    55.3K
 * Total Submissions: 175.9K
 * Testcase Example:  '"aa"\n"a"'
 *
 * 给定一个字符串 (s) 和一个字符模式 (p) ，实现一个支持 '?' 和 '*' 的通配符匹配。
 * 
 * '?' 可以匹配任何单个字符。
 * '*' 可以匹配任意字符串（包括空字符串）。
 * 
 * 
 * 两个字符串完全匹配才算匹配成功。
 * 
 * 说明:
 * 
 * 
 * s 可能为空，且只包含从 a-z 的小写字母。
 * p 可能为空，且只包含从 a-z 的小写字母，以及字符 ? 和 *。
 * 
 * 
 * 示例 1:
 * 
 * 输入:
 * s = "aa"
 * p = "a"
 * 输出: false
 * 解释: "a" 无法匹配 "aa" 整个字符串。
 * 
 * 示例 2:
 * 
 * 输入:
 * s = "aa"
 * p = "*"
 * 输出: true
 * 解释: '*' 可以匹配任意字符串。
 * 
 * 
 * 示例 3:
 * 
 * 输入:
 * s = "cb"
 * p = "?a"
 * 输出: false
 * 解释: '?' 可以匹配 'c', 但第二个 'a' 无法匹配 'b'。
 * 
 * 
 * 示例 4:
 * 
 * 输入:
 * s = "adceb"
 * p = "*a*b"
 * 输出: true
 * 解释: 第一个 '*' 可以匹配空字符串, 第二个 '*' 可以匹配字符串 "dce".
 * 
 * 
 * 示例 5:
 * 
 * 输入:
 * s = "acdcb"
 * p = "a*c?b"
 * 输出: false
 * 
 */

// @lc code=start
#include <string>
#include <vector>
class Solution
{
public:
    bool isMatch(std::string s, std::string p)
    {
        auto allstar = [](const std::string str, int left, int right) {
            for (int i = left; i < right; i++)
                if (str[i] != '*')
                    return false;
            return true;
        };
        auto charMatch = [](char u, char v) {
            return u == v || v == '?';
        };
        //从末尾不为*开始处理, 处理成p末尾为*的情况
        while (s.size() && p.size() && p.back() != '*')
        {
            //匹配, 从后往前筛除
            if (charMatch(s.back(), p.back()))
            {
                s.pop_back();
                p.pop_back();
            }
            else
                return false;
        }
        //如果p匹配完毕, 检查s是否匹配完毕
        if (p.empty())
            return s.empty();
        int sindex = 0, pindex = 0, sflag = -1, pflag = -1;
        //从前往后匹配字串
        while (sindex < s.size() && pindex < p.size())
        {
            if (p[pindex] == '*')
            {
                pindex++;
                sflag = sindex;
                pflag = pindex;
            }
            else if (charMatch(s[sindex], p[pindex]))
            {
                sindex++;
                pindex++;
            }
            else if (sflag != -1 && sflag + 1 < s.size())
            {
                sflag++;
                //'*'子字符串匹配失败, 返回到'*'所在位置重新匹配
                sindex = sflag;
                pindex = pflag;
            }
            else
                return false;
        }
        //如果剩余的不是全*, 则匹配失败
        return allstar(p, pindex, p.size());
    }
};
// @lc code=end
