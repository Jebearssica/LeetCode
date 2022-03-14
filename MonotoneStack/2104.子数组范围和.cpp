/*
 * @lc app=leetcode.cn id=2104 lang=cpp
 *
 * [2104] 子数组范围和
 *
 * https://leetcode-cn.com/problems/sum-of-subarray-ranges/description/
 *
 * algorithms
 * Medium (56.33%)
 * Likes:    166
 * Dislikes: 0
 * Total Accepted:    32.8K
 * Total Submissions: 52.3K
 * Testcase Example:  '[1,2,3]'
 *
 * 给你一个整数数组 nums 。nums 中，子数组的 范围 是子数组中最大元素和最小元素的差值。
 *
 * 返回 nums 中 所有 子数组范围的 和 。
 *
 * 子数组是数组中一个连续 非空 的元素序列。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [1,2,3]
 * 输出：4
 * 解释：nums 的 6 个子数组如下所示：
 * [1]，范围 = 最大 - 最小 = 1 - 1 = 0
 * [2]，范围 = 2 - 2 = 0
 * [3]，范围 = 3 - 3 = 0
 * [1,2]，范围 = 2 - 1 = 1
 * [2,3]，范围 = 3 - 2 = 1
 * [1,2,3]，范围 = 3 - 1 = 2
 * 所有范围的和是 0 + 0 + 0 + 1 + 1 + 2 = 4
 *
 * 示例 2：
 *
 *
 * 输入：nums = [1,3,3]
 * 输出：4
 * 解释：nums 的 6 个子数组如下所示：
 * [1]，范围 = 最大 - 最小 = 1 - 1 = 0
 * [3]，范围 = 3 - 3 = 0
 * [3]，范围 = 3 - 3 = 0
 * [1,3]，范围 = 3 - 1 = 2
 * [3,3]，范围 = 3 - 3 = 0
 * [1,3,3]，范围 = 3 - 1 = 2
 * 所有范围的和是 0 + 0 + 0 + 2 + 0 + 2 = 4
 *
 *
 * 示例 3：
 *
 *
 * 输入：nums = [4,-2,-3,4,1]
 * 输出：59
 * 解释：nums 中所有子数组范围的和是 59
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 1000
 * -10^9 <= nums[i] <= 10^9
 *
 *
 *
 *
 * 进阶：你可以设计一种时间复杂度为 O(n) 的解决方案吗？
 *
 */

// @lc code=start
#include <vector>
#include <stack>
using namespace std;
class Solution
{
public:
    long long subArrayRanges(vector<int> &nums)
    {
        int length = nums.size();
        vector<pair<int, int>> preLeft(length), preRight(length);
        stack<int> minStack, maxStack;
        for (int idx = 0; idx < length; ++idx)
        {
            while (!minStack.empty() && nums[minStack.top()] > nums[idx])
                minStack.pop();
            while (!maxStack.empty() && nums[maxStack.top()] <= nums[idx])
                maxStack.pop();
            preLeft[idx] = {minStack.empty() ? -1 : minStack.top(), maxStack.empty() ? -1 : maxStack.top()};
            minStack.push(idx), maxStack.push(idx);
        }
        minStack = stack<int>(), maxStack = stack<int>();
        for (int idx = length - 1; idx >= 0; --idx)
        {
            while (!minStack.empty() && nums[minStack.top()] >= nums[idx])
                minStack.pop();
            while (!maxStack.empty() && nums[maxStack.top()] < nums[idx])
                maxStack.pop();
            preRight[idx] = {minStack.empty() ? length : minStack.top(), maxStack.empty() ? length : maxStack.top()};
            minStack.push(idx), maxStack.push(idx);
        }

        long long sumMax = 0, sumMin = 0;
        for (int idx = 0; idx < length; ++idx)
        {
            sumMin += (long long)(preRight[idx].first - idx) * (idx - preLeft[idx].first) * nums[idx];
            sumMax += (long long)(preRight[idx].second - idx) * (idx - preLeft[idx].second) * nums[idx];
        }
        return sumMax - sumMin;
    }
};
// @lc code=end
