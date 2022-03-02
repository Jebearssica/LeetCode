/*
 * @lc app=leetcode.cn id=564 lang=cpp
 *
 * [564] 寻找最近的回文数
 *
 * https://leetcode-cn.com/problems/find-the-closest-palindrome/description/
 *
 * algorithms
 * Hard (18.54%)
 * Likes:    171
 * Dislikes: 0
 * Total Accepted:    11.4K
 * Total Submissions: 44.1K
 * Testcase Example:  '"123"'
 *
 * 给定一个表示整数的字符串 n ，返回与它最近的回文整数（不包括自身）。如果不止一个，返回较小的那个。
 *
 * “最近的”定义为两个整数差的绝对值最小。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: n = "123"
 * 输出: "121"
 *
 *
 * 示例 2:
 *
 *
 * 输入: n = "1"
 * 输出: "0"
 * 解释: 0 和 2是最近的回文，但我们返回最小的，也就是 0。
 *
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= n.length <= 18
 * n 只由数字组成
 * n 不含前导 0
 * n 代表在 [1, 10^18 - 1] 范围内的整数
 *
 *
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    string nearestPalindromic(string n)
    {
        long num = stol(n);
        int length = n.size();
        vector<long> opt = {(long)pow(10, length) + 1, (long)pow(10, length - 1) - 1};
        for (int offset = -1; offset <= 1; ++offset)
        {
            string prefix = n.substr(0, (length + 1) / 2);
            prefix = to_string(stol(prefix) + offset);
            opt.push_back(stol(prefix + string(prefix.rbegin() + length % 2, prefix.rend())));
        }
        long res = -1;
        for (auto &curOpt : opt)
        {
            if (curOpt == num)
                continue;
            if (res == -1 || abs(curOpt - num) < abs(res - num) || (abs(curOpt - num) == abs(res - num) && curOpt < res))
                res = curOpt;
        }
        return to_string(res);
    }
};
// @lc code=end
