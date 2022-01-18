/*
 * @lc app=leetcode.cn id=689 lang=cpp
 *
 * [689] 三个无重叠子数组的最大和
 *
 * https://leetcode-cn.com/problems/maximum-sum-of-3-non-overlapping-subarrays/description/
 *
 * algorithms
 * Hard (49.44%)
 * Likes:    278
 * Dislikes: 0
 * Total Accepted:    18K
 * Total Submissions: 31.8K
 * Testcase Example:  '[1,2,1,2,6,7,5,1]\n2'
 *
 * 给你一个整数数组 nums 和一个整数 k ，找出三个长度为 k 、互不重叠、且 3 * k 项的和最大的子数组，并返回这三个子数组。
 *
 * 以下标的数组形式返回结果，数组中的每一项分别指示每个子数组的起始位置（下标从 0 开始）。如果有多个结果，返回字典序最小的一个。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [1,2,1,2,6,7,5,1], k = 2
 * 输出：[0,3,5]
 * 解释：子数组 [1, 2], [2, 6], [7, 5] 对应的起始下标为 [0, 3, 5]。
 * 也可以取 [2, 1], 但是结果 [1, 3, 5] 在字典序上更大。
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [1,2,1,2,1,2,1,2,1], k = 2
 * 输出：[0,2,4]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 2 * 10^4
 * 1 <= nums[i] < 2^16
 * 1 <= k <= floor(nums.length / 3)
 *
 *
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k)
    {
        vector<int> res;
        int sum1 = 0, maxSum1 = 0, maxSum1Idx = 0;
        int sum2 = 0, maxSum2 = 0, maxSum2Idx1 = 0, maxSum2Idx2 = 0;
        int sum3 = 0, maxSum3 = 0;
        for (int idx = 2 * k; idx < nums.size(); idx++)
        {
            sum1 += nums[idx - 2 * k];
            sum2 += nums[idx - k];
            sum3 += nums[idx];
            if (idx >= 3 * k - 1)
            {
                if (sum1 > maxSum1)
                {
                    maxSum1 = sum1;
                    maxSum1Idx = idx - (3 * k - 1);
                }
                if (sum2 + maxSum1 > maxSum2)
                {
                    maxSum2 = sum2 + maxSum1;
                    maxSum2Idx1 = maxSum1Idx;
                    maxSum2Idx2 = idx - (2 * k - 1);
                }
                if (sum3 + maxSum2 > maxSum3)
                {
                    maxSum3 = sum3 + maxSum2;
                    res = {maxSum2Idx1, maxSum2Idx2, idx - (k - 1)};
                }
                sum1 -= nums[idx - (3 * k - 1)];
                sum2 -= nums[idx - (2 * k - 1)];
                sum3 -= nums[idx - (k - 1)];
            }
        }
        return res;
    }
};

// @lc code=end
