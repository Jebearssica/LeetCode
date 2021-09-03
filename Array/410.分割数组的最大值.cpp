/*
 * @lc app=leetcode.cn id=410 lang=cpp
 *
 * [410] 分割数组的最大值
 *
 * https://leetcode-cn.com/problems/split-array-largest-sum/description/
 *
 * algorithms
 * Hard (56.09%)
 * Likes:    543
 * Dislikes: 0
 * Total Accepted:    37.7K
 * Total Submissions: 67.1K
 * Testcase Example:  '[7,2,5,10,8]\n2'
 *
 * 给定一个非负整数数组 nums 和一个整数 m ，你需要将这个数组分成 m 个非空的连续子数组。
 * 
 * 设计一个算法使得这 m 个子数组各自和的最大值最小。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [7,2,5,10,8], m = 2
 * 输出：18
 * 解释：
 * 一共有四种方法将 nums 分割为 2 个子数组。 其中最好的方式是将其分为 [7,2,5] 和 [10,8] 。
 * 因为此时这两个子数组各自的和的最大值为18，在所有情况中最小。
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,2,3,4,5], m = 2
 * 输出：9
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [1,4,4], m = 3
 * 输出：4
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 0 
 * 1 
 * 
 * 
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    int split(vector<int> &nums, int max)
    {
        int splitCount = 1;
        int sum = 0;
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (sum + nums[i] > max)
            {
                sum = nums[i];
                splitCount++;
            }
            else
            {
                sum += nums[i];
            }
        }
        return splitCount;
    }
    int splitArray(vector<int> &nums, int m)
    {
        int left = 0, right = 0;
        //get left -> max value in vector
        //get right -> sum in vector
        for (auto &info : nums)
        {
            left = left > info ? left : info;
            right += info;
        }
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (split(nums, mid) <= m)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};
// @lc code=end
