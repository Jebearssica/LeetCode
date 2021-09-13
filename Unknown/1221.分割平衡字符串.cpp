/*
 * @lc app=leetcode.cn id=1221 lang=cpp
 *
 * [1221] 分割平衡字符串
 *
 * https://leetcode-cn.com/problems/split-a-string-in-balanced-strings/description/
 *
 * algorithms
 * Easy (80.39%)
 * Likes:    125
 * Dislikes: 0
 * Total Accepted:    51.5K
 * Total Submissions: 62.4K
 * Testcase Example:  '"RLRRLLRLRL"'
 *
 * 在一个 平衡字符串 中，'L' 和 'R' 字符的数量是相同的。
 * 
 * 给你一个平衡字符串 s，请你将它分割成尽可能多的平衡字符串。
 * 
 * 注意：分割得到的每个字符串都必须是平衡字符串。
 * 
 * 返回可以通过分割得到的平衡字符串的 最大数量 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "RLRRLLRLRL"
 * 输出：4
 * 解释：s 可以分割为 "RL"、"RRLL"、"RL"、"RL" ，每个子字符串中都包含相同数量的 'L' 和 'R' 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "RLLLLRRRLR"
 * 输出：3
 * 解释：s 可以分割为 "RL"、"LLLRRR"、"LR" ，每个子字符串中都包含相同数量的 'L' 和 'R' 。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "LLLLRRRR"
 * 输出：1
 * 解释：s 只能保持原样 "LLLLRRRR".
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：s = "RLRRRLLRLL"
 * 输出：2
 * 解释：s 可以分割为 "RL"、"RRRLLRLL" ，每个子字符串中都包含相同数量的 'L' 和 'R' 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * s[i] = 'L' 或 'R'
 * s 是一个 平衡 字符串
 * 
 * 
 */

// @lc code=start
#include <string>
using namespace std;
class Solution
{
public:
    int balancedStringSplit(string s)
    {
        if (s == "")
            return 0;

        int counter = 0, result = 0;
        for (char i : s)
        {
            i == 'L' ? counter++ : counter--;
            if (counter == 0)
                result++;
        }
        return result;
    }
};
// @lc code=end
