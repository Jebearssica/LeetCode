/*
 * @lc app=leetcode.cn id=698 lang=cpp
 *
 * [698] 划分为k个相等的子集
 *
 * https://leetcode-cn.com/problems/partition-to-k-equal-sum-subsets/description/
 *
 * algorithms
 * Medium (45.11%)
 * Likes:    495
 * Dislikes: 0
 * Total Accepted:    36.4K
 * Total Submissions: 81.8K
 * Testcase Example:  '[4,3,2,3,5,2,1]\n4'
 *
 * 给定一个整数数组  nums 和一个正整数 k，找出是否有可能把这个数组分成 k 个非空子集，其总和都相等。
 *
 * 示例 1：
 *
 * 输入： nums = [4, 3, 2, 3, 5, 2, 1], k = 4
 * 输出： True
 * 说明： 有可能将其分成 4 个子集（5），（1,4），（2,3），（2,3）等于总和。
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= k <= len(nums) <= 16
 * 0 < nums[i] < 10000
 *
 *
 */

// @lc code=start
#include <vector>
#include <numeric>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    unordered_map<vector<bool>, bool> memo;
    bool backtracing(int remainGroups, int start, int curSum, vector<int> &nums, vector<bool> &used, int target)
    {
        if (remainGroups == 0)
            return true;
        if (curSum == target)
        {
            bool res = backtracing(remainGroups - 1, 0, 0, nums, used, target);
            memo[used] = res;
            return res;
        }
        if(memo.count(used))
            return memo[used];
        for (int idx = start; idx < nums.size(); ++idx)
        {
            if (!used[idx] && nums[idx] + curSum <= target)
            {
                used[idx] = true;
                curSum += nums[idx];
                if (backtracing(remainGroups, idx + 1, curSum, nums, used, target))
                    return true;
                used[idx] = false;
                curSum -= nums[idx];
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int> &nums, int k)
    {
        if (k > nums.size())
            return false;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0)
            return false;

        vector<bool> used(nums.size(), false);
        int target = sum / k;

        return backtracing(k, 0, 0, nums, used, target);
    }
};
// @lc code=end
