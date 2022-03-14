/*
 * @lc app=leetcode.cn id=793 lang=cpp
 *
 * [793] 阶乘函数后 K 个零
 *
 * https://leetcode-cn.com/problems/preimage-size-of-factorial-zeroes-function/description/
 *
 * algorithms
 * Hard (39.83%)
 * Likes:    80
 * Dislikes: 0
 * Total Accepted:    6.1K
 * Total Submissions: 15.3K
 * Testcase Example:  '0'
 *
 *  f(x) 是 x! 末尾是 0 的数量。回想一下 x! = 1 * 2 * 3 * ... * x，且 0! = 1 。
 *
 *
 * 例如， f(3) = 0 ，因为 3! = 6 的末尾没有 0 ；而 f(11) = 2 ，因为 11!= 39916800 末端有 2 个 0 。
 *
 *
 * 给定 k，找出返回能满足 f(x) = k 的非负整数 x 的数量。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：k = 0
 * 输出：5
 * 解释：0!, 1!, 2!, 3!, 和 4! 均符合 k = 0 的条件。
 *
 *
 * 示例 2：
 *
 *
 * 输入：k = 5
 * 输出：0
 * 解释：没有匹配到这样的 x!，符合 k = 5 的条件。
 *
 * 示例 3:
 *
 *
 * 输入: k = 3
 * 输出: 5
 *
 *
 *
 *
 * 提示:
 *
 *
 * 0 <= k <= 10^9
 *
 *
 */

// @lc code=start
#include <limits>
using namespace std;
class Solution
{
public:
    long long trailingZeroes(long long n)
    {
        long long res = 0;
        long long div = 5;
        while (div <= n)
        {
            res += n / div;
            div *= 5;
        }
        return res;
    }
    int preimageSizeFZF(int k)
    {

        int res = 0;
        long left = 0, right = LONG_MAX;
        while (left < right)
        {
            long mid = left + (right - left) / 2;
            long temp = trailingZeroes(mid); 
            if(temp == k)
                return 5;
            else if(temp > k)
                right = mid;
            else
                left = mid + 1;
        }
        return 0;
    }
};
// @lc code=end
