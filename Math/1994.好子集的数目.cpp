/*
 * @lc app=leetcode.cn id=1994 lang=cpp
 *
 * [1994] 好子集的数目
 *
 * https://leetcode-cn.com/problems/the-number-of-good-subsets/description/
 *
 * algorithms
 * Hard (37.42%)
 * Likes:    55
 * Dislikes: 0
 * Total Accepted:    4.8K
 * Total Submissions: 8.6K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给你一个整数数组 nums 。如果 nums 的一个子集中，所有元素的乘积可以表示为一个或多个 互不相同的质数 的乘积，那么我们称它为 好子集
 * 。
 *
 *
 * 比方说，如果 nums = [1, 2, 3, 4] ：
 *
 *
 * [2, 3] ，[1, 2, 3] 和 [1, 3] 是 好 子集，乘积分别为 6 = 2*3 ，6 = 2*3 和 3 = 3 。
 * [1, 4] 和 [4] 不是 好 子集，因为乘积分别为 4 = 2*2 和 4 = 2*2 。
 *
 *
 *
 *
 * 请你返回 nums 中不同的 好 子集的数目对 10^9 + 7 取余 的结果。
 *
 * nums 中的 子集 是通过删除 nums
 * 中一些（可能一个都不删除，也可能全部都删除）元素后剩余元素组成的数组。如果两个子集删除的下标不同，那么它们被视为不同的子集。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [1,2,3,4]
 * 输出：6
 * 解释：好子集为：
 * - [1,2]：乘积为 2 ，可以表示为质数 2 的乘积。
 * - [1,2,3]：乘积为 6 ，可以表示为互不相同的质数 2 和 3 的乘积。
 * - [1,3]：乘积为 3 ，可以表示为质数 3 的乘积。
 * - [2]：乘积为 2 ，可以表示为质数 2 的乘积。
 * - [2,3]：乘积为 6 ，可以表示为互不相同的质数 2 和 3 的乘积。
 * - [3]：乘积为 3 ，可以表示为质数 3 的乘积。
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [4,2,3,15]
 * 输出：5
 * 解释：好子集为：
 * - [2]：乘积为 2 ，可以表示为质数 2 的乘积。
 * - [2,3]：乘积为 6 ，可以表示为互不相同质数 2 和 3 的乘积。
 * - [2,15]：乘积为 30 ，可以表示为互不相同质数 2，3 和 5 的乘积。
 * - [3]：乘积为 3 ，可以表示为质数 3 的乘积。
 * - [15]：乘积为 15 ，可以表示为互不相同质数 3 和 5 的乘积。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 30
 *
 *
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    static constexpr int prime[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    static constexpr int mod = 1e9 + 7;
    static constexpr int maxNumber = 30;
    int numberOfGoodSubsets(vector<int> &nums)
    {
        vector<int> cnt(maxNumber + 1);
        for (auto num : nums)
            ++cnt[num];
        int mask = 1 << 10;
        vector<long> dp(mask);
        dp[0] = 1;
        for (int curNum = 2; curNum <= maxNumber; ++curNum)
        {
            if (cnt[curNum] == 0)
                continue;
            int curMask = 0, tempCurNum = curNum;
            bool valid = true;
            for (int idx = 0; idx < 10; ++idx)
            {
                int primeCnt = 0;
                while (tempCurNum % prime[idx] == 0)
                {
                    tempCurNum /= prime[idx];
                    curMask |= 1 << idx;
                    ++primeCnt;
                }
                if (primeCnt > 1)
                {
                    valid = false;
                    break;
                }
            }
            if (!valid)
                continue;
            for (int m = 0; m < mask; ++m)
            {
                if ((curMask & m) != 0)
                    continue;
                dp[curMask | m] = (dp[curMask | m] + dp[m] * cnt[curNum]) % mod;
            }
        }
        long res = 0;
        for(int idx = 1; idx < mask; ++idx)
            res = (res + dp[idx]) % mod;
        for(int idx = 0; idx < cnt[1]; ++idx)
            res = res * 2 % mod;
        return int(res);
    }
};
// @lc code=end
