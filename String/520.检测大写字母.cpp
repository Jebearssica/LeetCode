/*
 * @lc app=leetcode.cn id=520 lang=cpp
 *
 * [520] 检测大写字母
 *
 * https://leetcode-cn.com/problems/detect-capital/description/
 *
 * algorithms
 * Easy (56.38%)
 * Likes:    172
 * Dislikes: 0
 * Total Accepted:    55.1K
 * Total Submissions: 95.9K
 * Testcase Example:  '"USA"'
 *
 * 我们定义，在以下情况时，单词的大写用法是正确的：
 * 
 * 
 * 全部字母都是大写，比如 "USA" 。
 * 单词中所有字母都不是大写，比如 "leetcode" 。
 * 如果单词不只含有一个字母，只有首字母大写， 比如 "Google" 。
 * 
 * 
 * 给你一个字符串 word 。如果大写用法正确，返回 true ；否则，返回 false 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：word = "USA"
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：word = "FlaG"
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= word.length <= 100
 * word 由小写和大写英文字母组成
 * 
 * 
 */

// @lc code=start
#include <string>
using namespace std;
class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        int lastUpper = -1, lastLower = -1;
        for (int idx = 0; idx < word.size(); idx++)
        {
            if (islower(word[idx]))
                lastLower = idx;
            else
                lastUpper = idx;
        }
        if (lastUpper > 0 && lastLower > -1)
            return false;
        return true;
    }
};
// @lc code=end
