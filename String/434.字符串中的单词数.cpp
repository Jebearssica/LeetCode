/*
 * @lc app=leetcode.cn id=434 lang=cpp
 *
 * [434] 字符串中的单词数
 *
 * https://leetcode-cn.com/problems/number-of-segments-in-a-string/description/
 *
 * algorithms
 * Easy (37.38%)
 * Likes:    110
 * Dislikes: 0
 * Total Accepted:    42.8K
 * Total Submissions: 112K
 * Testcase Example:  '"Hello, my name is John"'
 *
 * 统计字符串中的单词个数，这里的单词指的是连续的不是空格的字符。
 * 
 * 请注意，你可以假定字符串里不包括任何不可打印的字符。
 * 
 * 示例:
 * 
 * 输入: "Hello, my name is John"
 * 输出: 5
 * 解释: 这里的单词是指连续的不是空格的字符，所以 "Hello," 算作 1 个单词。
 * 
 * 
 */

// @lc code=start
#include <string>
using namespace std;
class Solution
{
public:
    int countSegments(string s)
    {
        int res = 0;
        for (int idx = 0; idx < s.size(); idx++)
        {
            if ((idx == 0 || s[idx - 1] == ' ') && s[idx] != ' ')
                res++;
        }

        return res;
    }
};
// @lc code=end
