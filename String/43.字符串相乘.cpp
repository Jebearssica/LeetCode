/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 *
 * https://leetcode-cn.com/problems/multiply-strings/description/
 *
 * algorithms
 * Medium (44.89%)
 * Likes:    869
 * Dislikes: 0
 * Total Accepted:    207.8K
 * Total Submissions: 463.1K
 * Testcase Example:  '"2"\n"3"'
 *
 * 给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
 *
 * 注意：不能使用任何内置的 BigInteger 库或直接将输入转换为整数。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: num1 = "2", num2 = "3"
 * 输出: "6"
 *
 * 示例 2:
 *
 *
 * 输入: num1 = "123", num2 = "456"
 * 输出: "56088"
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= num1.length, num2.length <= 200
 * num1 和 num2 只能由数字组成。
 * num1 和 num2 都不包含任何前导零，除了数字0本身。
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
    string multiply(string num1, string num2)
    {
        int n = num1.size(), m = num2.size();
        vector<int> cache(n + m, 0);
        for (int i = n - 1; i >= 0; --i)
        {
            for (int j = m - 1; j >= 0; --j)
            {
                int startIdx = i + j;
                int curRes = (num1[i] - '0') * (num2[j] - '0') + cache[startIdx + 1];
                cache[startIdx + 1] = curRes % 10;
                cache[startIdx] += curRes / 10;
            }
        }
        int resStartIdx = 0;
        while (resStartIdx < n + m && cache[resStartIdx] == 0)
            ++resStartIdx;
        string res;
        for (; resStartIdx < n + m; ++resStartIdx)
            res += cache[resStartIdx] + '0';
        return res.size() == 0 ? "0" : res;
    }
};
// @lc code=end
