/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 *
 * https://leetcode-cn.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (76.30%)
 * Likes:    1362
 * Dislikes: 0
 * Total Accepted:    187.6K
 * Total Submissions: 245.6K
 * Testcase Example:  '3'
 *
 * 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：n = 3
 * 输出：[
 * ⁠      "((()))",
 * ⁠      "(()())",
 * ⁠      "(())()",
 * ⁠      "()(())",
 * ⁠      "()()()"
 * ⁠    ]
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <string>
class Solution
{
public:
    std::vector<std::string> result;

    /*
    input:
        &r: 结果
        &current: 当前即将要压入的结果的字符串
        left, right: 左右括号在current中的数量
        n: 总的括号对数
    */
    void backtrack(std::vector<std::string> &r, std::string &current, int left, int right, int n)
    {
        //当前字符串满足要压入的长度
        if (current.size() == 2 * n)
        {
            r.push_back(current);
            return;
        }
        //左括号有盈余, 就可以随便用
        if (left < n)
        {
            //压入
            current.push_back('(');
            backtrack(r, current, left + 1, right, n);
            //回溯完毕, 弹出
            current.pop_back();
        }
        //只要当前右括号数量小于左括号, 可以随便压入右括号, 前面有足够的左括号对应
        if (right < left)
        {
            current.push_back(')');
            backtrack(r, current, left, right + 1, n);
            current.pop_back();
        }
    }

    std::vector<std::string> generateParenthesis(int n)
    {
        std::string current;
        backtrack(result, current, 0, 0, n);
        return result;
    }
};
// @lc code=end
