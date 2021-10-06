/*
 * @lc app=leetcode.cn id=414 lang=cpp
 *
 * [414] 第三大的数
 *
 * https://leetcode-cn.com/problems/third-maximum-number/description/
 *
 * algorithms
 * Easy (36.40%)
 * Likes:    260
 * Dislikes: 0
 * Total Accepted:    66.2K
 * Total Submissions: 178.3K
 * Testcase Example:  '[3,2,1]'
 *
 * 给你一个非空数组，返回此数组中 第三大的数 。如果不存在，则返回数组中最大的数。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：[3, 2, 1]
 * 输出：1
 * 解释：第三大的数是 1 。
 * 
 * 示例 2：
 * 
 * 
 * 输入：[1, 2]
 * 输出：2
 * 解释：第三大的数不存在, 所以返回最大的数 2 。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：[2, 2, 3, 1]
 * 输出：1
 * 解释：注意，要求返回第三大的数，是指在所有不同数字中排第三大的数。
 * 此例中存在两个值为 2 的数，它们都排第二。在所有不同数字中排第三大的数为 1 。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * -2^31 
 * 
 * 
 * 
 * 
 * 进阶：你能设计一个时间复杂度 O(n) 的解决方案吗？
 * 
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        long fir = LONG_MIN, sec = LONG_MIN, thir = LONG_MIN;
        for (long num : nums)
        {
            if (num > fir)
            {
                thir = sec;
                sec = fir;
                fir = num;
            }
            else if (num > sec && num < fir)
            {
                thir = sec;
                sec = num;
            }
            else if (num > thir && num < sec)
            {
                thir = num;
            }
        }
        return thir == LONG_MIN ? fir : thir;
    }
};
// @lc code=end
