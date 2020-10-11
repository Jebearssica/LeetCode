/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 *
 * https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (55.49%)
 * Likes:    942
 * Dislikes: 0
 * Total Accepted:    182.6K
 * Total Submissions: 328.9K
 * Testcase Example:  '"23"'
 *
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
 * 
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入："23"
 * 输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * 说明:
 * 尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。
 * 
 */

// @lc code=start
#include <string>
#include <vector>
#include <unordered_map>
class Solution
{
public:
    std::unordered_map<char, std::string> phoneMap{
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"},
    };
    std::string current;
    std::vector<std::string> result;
    void DFS(int index, std::string digits)
    {
        if (index == digits.size())
        {
            result.push_back(current);
            return;
        }
        for (int i = 0; i < phoneMap[digits[index]].size(); i++)
        {
            current.push_back(phoneMap[digits[index]][i]);
            DFS(index + 1, digits);
            current.pop_back();
        }
    }
    std::vector<std::string> letterCombinations(std::string digits)
    {
        //判断为空情况
        if (digits.empty())
            return result;
        DFS(0, digits);
        return result;
    }
};
// @lc code=end
