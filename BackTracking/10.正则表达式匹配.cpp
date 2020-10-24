/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 *
 * https://leetcode-cn.com/problems/regular-expression-matching/description/
 *
 * algorithms
 * Hard (30.49%)
 * Likes:    1594
 * Dislikes: 0
 * Total Accepted:    119.4K
 * Total Submissions: 391.6K
 * Testcase Example:  '"aa"\n"a"'
 *
 * 给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。
 * 
 * '.' 匹配任意单个字符
 * '*' 匹配零个或多个前面的那一个元素
 * 
 * 
 * 所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。
 * 
 * 说明:
 * 
 * 
 * s 可能为空，且只包含从 a-z 的小写字母。
 * p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。
 * 
 * 
 * 示例 1:
 * 
 * 输入:
 * s = "aa"
 * p = "a"
 * 输出: false
 * 解释: "a" 无法匹配 "aa" 整个字符串。
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * s = "aa"
 * p = "a*"
 * 输出: true
 * 解释: 因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。
 * 
 * 
 * 示例 3:
 * 
 * 输入:
 * s = "ab"
 * p = ".*"
 * 输出: true
 * 解释: ".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。
 * 
 * 
 * 示例 4:
 * 
 * 输入:
 * s = "aab"
 * p = "c*a*b"
 * 输出: true
 * 解释: 因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。
 * 
 * 
 * 示例 5:
 * 
 * 输入:
 * s = "mississippi"
 * p = "mis*is*p*."
 * 输出: false
 * 
 */

// @lc code=start
/* 判断树如下:
* s[n-1] == p[n-1]
  * 不匹配, 判断是否为特殊字符: p[n-1] == '*' || p[n-1] == '.'
    * p[n-1] == '*'
      * p[n-2] == s[n-1]
        * 匹配, 则判断s左侧的数是否是重复数
          * p[:(n-3)] == s[:(n-1)], 循环直到不匹配, 然后进行子问题判断
      * 不匹配, 则*此处的作用是使得p[n-2]次数为0, 继续向左进行判断
        * p[n-3] == s[n-1]
          * 继续子问题的判断
        * 不匹配, 直接退出
    * p[n-1] == '.'
      * 直接进行子问题判断
  * 非特殊字符不匹配, 直接退出
* 匹配, 继续子问题的判断
*/
#include <string>
#include <vector>
class Solution
{
public:
    bool isMatch(std::string s, std::string p)
    {
        int slength = s.size(), plength = p.size();
        std::vector<std::vector<bool>> dp(slength + 1, std::vector<bool>(plength + 1, false));
        dp[0][0] = true;
        for (int i = 2; plength >= 2 && i <= plength; i++)
            //如果为*, 则问题转变为p前移动两个元素的子问题
            if (p[i - 1] == '*')
                dp[0][i] = dp[0][i - 2];
        for (int i = 1; i <= slength; i++)
        {
            for (int j = 1; j <= plength; j++)
            {
                //字符一一对应
                if (s[i - 1] == p[j - 1] || p[j - 1] == '.')
                    dp[i][j] = dp[i - 1][j - 1];
                //出现'*'情况
                else if (p[j - 1] == '*')
                {
                    //针对"*a"这种开头为*类型的需要直接跳出, 防止index越界
                    if (j == 1)
                        return false;
                    //后方都不匹配, 此处'*'代表次数为0, 则问题转换为j-2的子问题
                    else if (p[j - 2] != s[i - 1] && p[j - 2] != '.')
                        dp[i][j] = dp[i][j - 2];
                    //问题转变为j-2 j-1 i-1的合集, 任意一个成功, 则能匹配成功
                    else
                        dp[i][j] = dp[i][j - 2] || dp[i][j - 1] || dp[i - 1][j];
                }
                //完全不匹配, 为false
                else
                    dp[i][j] = false;
            }
        }
        return dp[slength][plength];
    }
};
// @lc code=end
