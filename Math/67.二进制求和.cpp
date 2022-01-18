/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 *
 * https://leetcode-cn.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (54.14%)
 * Likes:    712
 * Dislikes: 0
 * Total Accepted:    209.1K
 * Total Submissions: 386.3K
 * Testcase Example:  '"11"\n"1"'
 *
 * 给你两个二进制字符串，返回它们的和（用二进制表示）。
 *
 * 输入为 非空 字符串且只包含数字 1 和 0。
 *
 *
 *
 * 示例 1:
 *
 * 输入: a = "11", b = "1"
 * 输出: "100"
 *
 * 示例 2:
 *
 * 输入: a = "1010", b = "1011"
 * 输出: "10101"
 *
 *
 *
 * 提示：
 *
 *
 * 每个字符串仅由字符 '0' 或 '1' 组成。
 * 1 <= a.length, b.length <= 10^4
 * 字符串如果不是 "0" ，就都不含前导零。
 *
 *
 */

// @lc code=start
#include <string>
using namespace std;
class Solution
{
public:
    string addBinary(string a, string b)
    {
        string res;
        int carry = 0;
        int idxA = a.size() - 1, idxB = b.size() - 1;
        while (idxA >= 0 || idxB >= 0 || carry != 0)
        {
            int digitA = idxA >= 0 ? a[idxA] - '0' : 0;
            int digitB = idxB >= 0 ? b[idxB] - '0' : 0;
            int sum = digitA + digitB + carry;
            carry = sum >= 2 ? 1 : 0;
            sum = sum >= 2 ? sum - 2 : sum;
            res += to_string(sum);
            idxA--;
            idxB--;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
