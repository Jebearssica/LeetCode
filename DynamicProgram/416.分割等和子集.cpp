/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 *
 * https://leetcode-cn.com/problems/partition-equal-subset-sum/description/
 *
 * algorithms
 * Medium (50.79%)
 * Likes:    978
 * Dislikes: 0
 * Total Accepted:    178.2K
 * Total Submissions: 350.9K
 * Testcase Example:  '[1,5,11,5]'
 *
 * 给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,5,11,5]
 * 输出：true
 * 解释：数组可以分割成 [1, 5, 5] 和 [11] 。
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,2,3,5]
 * 输出：false
 * 解释：数组不能分割成两个元素和相等的子集。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 1 
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <numeric>
using namespace std;
class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0)
            return false;
        else
        {
            vector<bool> dp((int)(sum / 2 + 1), false);
            //init
            dp[0] = true;
            for (int i = 1; i <= nums.size(); i++)
                for (int j = sum / 2; j >= nums[i - 1]; j--)
                    dp[j] = dp[j] || dp[j - nums[i - 1]];
            return dp[sum / 2];
        }
    }
};
// @lc code=end
