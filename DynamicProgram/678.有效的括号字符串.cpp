/*
 * @lc app=leetcode.cn id=678 lang=cpp
 *
 * [678] 有效的括号字符串
 *
 * https://leetcode-cn.com/problems/valid-parenthesis-string/description/
 *
 * algorithms
 * Medium (35.03%)
 * Likes:    332
 * Dislikes: 0
 * Total Accepted:    28.5K
 * Total Submissions: 77.2K
 * Testcase Example:  '"()"'
 *
 * 给定一个只包含三种字符的字符串：（ ，） 和 *，写一个函数来检验这个字符串是否为有效字符串。有效字符串具有如下规则：
 * 
 * 
 * 任何左括号 ( 必须有相应的右括号 )。
 * 任何右括号 ) 必须有相应的左括号 ( 。
 * 左括号 ( 必须在对应的右括号之前 )。
 * * 可以被视为单个右括号 ) ，或单个左括号 ( ，或一个空字符串。
 * 一个空字符串也被视为有效字符串。
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: "()"
 * 输出: True
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: "(*)"
 * 输出: True
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: "(*))"
 * 输出: True
 * 
 * 
 * 注意:
 * 
 * 
 * 字符串大小将在 [1，100] 范围内。
 * 
 * 
 */

// @lc code=start
#include <string>
#include <stack>
using namespace std;
class Solution
{
public:
    stack<int> left;
    stack<int> star;
    bool checkValidString(string s)
    {
        for (int idx = 0; idx < s.size(); idx++)
        {
            if (s[idx] == '*')
            {
                star.push(idx);
                continue;
            }
            else if (s[idx] == '(')
                left.push(idx);
            else if (left.empty())
                if (star.empty())
                    return false;
                else
                    star.pop();
            else
                left.pop();
        }
        while (!left.empty() && !star.empty())
        {
            if (left.top() > star.top())
                return false;
            left.pop();
            star.pop();
        }

        return left.empty();
    }
};
// @lc code=end
