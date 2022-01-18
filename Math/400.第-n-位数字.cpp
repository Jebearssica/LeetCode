/*
 * @lc app=leetcode.cn id=400 lang=cpp
 *
 * [400] 第 N 位数字
 *
 * https://leetcode-cn.com/problems/nth-digit/description/
 *
 * algorithms
 * Medium (41.87%)
 * Likes:    228
 * Dislikes: 0
 * Total Accepted:    27.5K
 * Total Submissions: 62.2K
 * Testcase Example:  '3'
 *
 * 给你一个整数 n ，请你在无限的整数序列 [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...] 中找出并返回第 n
 * 位数字。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 3
 * 输出：3
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 11
 * 输出：0
 * 解释：第 11 位数字在序列 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... 里是 0 ，它是 10 的一部分。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 2^31 - 1
 * 
 * 
 */

// @lc code=start
#include <math.h>
using namespace std;
class Solution
{
public:
    int findNthDigit(int n)
    {
        int length = 1;
        //confirm the range
        while (length * 9 * pow(10, length - 1) < n)
        {
            n -= length * 9 * pow(10, length - 1);
            length++;
        }
        //define the start integer
        long start = powl(10, length - 1);
        //define the target integer
        long target = n / length + start - 1;
        //remain length
        n -= (target - start + 1) * length;
        return n == 0 ? (int)(target % 10) : ((target + 1) / (int)pow(10, length - n) % 10);
    }
};
// @lc code=end
