/*
 * @lc app=leetcode.cn id=600 lang=cpp
 *
 * [600] 不含连续1的非负整数
 *
 * https://leetcode-cn.com/problems/non-negative-integers-without-consecutive-ones/description/
 *
 * algorithms
 * Hard (34.33%)
 * Likes:    140
 * Dislikes: 0
 * Total Accepted:    5.3K
 * Total Submissions: 14.1K
 * Testcase Example:  '5'
 *
 * 给定一个正整数 n，找出小于或等于 n 的非负整数中，其二进制表示不包含 连续的1 的个数。
 * 
 * 示例 1:
 * 
 * 输入: 5
 * 输出: 5
 * 解释: 
 * 下面是带有相应二进制表示的非负整数<= 5：
 * 0 : 0
 * 1 : 1
 * 2 : 10
 * 3 : 11
 * 4 : 100
 * 5 : 101
 * 其中，只有整数3违反规则（有两个连续的1），其他5个满足规则。
 * 
 * 说明: 1 <= n <= 10^9
 * 
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    int findIntegers(int n)
    {
        int length = floor(log2(n) + 1) + 1, result = 0;
        vector<int> dp(length, 1);
        for (int i = 2; i < length; i++)
            dp[i] = dp[i - 1] + dp[i - 2];
        int pre = 0;
        for (int i = length - 2; i >= 0; i--)
        {
            int val = 1 << i;
            //判断最高位是否为0
            if ((n & val) != 0)
            {
                n -= val; //最高位置0, 方便下一个循环处理(已经进入下一层)
                result += dp[i + 1];
                //上一层结点为1, 连续两个1重复, 推出
                if (pre == 1)
                    break;
                //标记为1, 进入下一层
                pre = 1;
            }
            else
                pre = 0;
            if (i == 0)
                result++;
        }

        return result;
    }
};
// @lc code=end
