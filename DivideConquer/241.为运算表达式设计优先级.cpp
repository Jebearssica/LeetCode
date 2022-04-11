/*
 * @lc app=leetcode.cn id=241 lang=cpp
 *
 * [241] 为运算表达式设计优先级
 *
 * https://leetcode-cn.com/problems/different-ways-to-add-parentheses/description/
 *
 * algorithms
 * Medium (73.53%)
 * Likes:    526
 * Dislikes: 0
 * Total Accepted:    39.2K
 * Total Submissions: 53.3K
 * Testcase Example:  '"2-1-1"'
 *
 * 给你一个由数字和运算符组成的字符串 expression ，按不同优先级组合数字和运算符，计算并返回所有可能组合的结果。你可以 按任意顺序
 * 返回答案。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：expression = "2-1-1"
 * 输出：[0,2]
 * 解释：
 * ((2-1)-1) = 0
 * (2-(1-1)) = 2
 *
 *
 * 示例 2：
 *
 *
 * 输入：expression = "2*3-4*5"
 * 输出：[-34,-14,-10,-10,10]
 * 解释：
 * (2*(3-(4*5))) = -34
 * ((2*3)-(4*5)) = -14
 * ((2*(3-4))*5) = -10
 * (2*((3-4)*5)) = -10
 * (((2*3)-4)*5) = 10
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= expression.length <= 20
 * expression 由数字和算符 '+'、'-' 和 '*' 组成。
 * 输入表达式中的所有整数值在范围 [0, 99] 
 *
 *
 */

// @lc code=start
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    unordered_map<string, vector<int>> memo;
    vector<int> diffWaysToCompute(string expression)
    {
        if (memo.count(expression))
            return memo[expression];
        vector<int> res;
        for (int idx = 0; idx < expression.size(); ++idx)
        {
            char op = expression[idx];
            vector<int> left, right;
            if (!isdigit(op))
            {
                left = diffWaysToCompute(expression.substr(0, idx));
                right = diffWaysToCompute(expression.substr(idx + 1));
            }
            for (auto &numL : left)
            {
                for (auto &numR : right)
                {
                    if (op == '+')
                        res.push_back(numL + numR);
                    else if (op == '-')
                        res.push_back(numL - numR);
                    else if (op == '*')
                        res.push_back(numL * numR);
                }
            }
        }
        if (res.empty())
            res.push_back(stoi(expression));
        memo[expression] = res;
        return res;
    }
};
// @lc code=end
