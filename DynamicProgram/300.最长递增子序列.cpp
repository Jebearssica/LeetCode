/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 *
 * https://leetcode-cn.com/problems/longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (50.95%)
 * Likes:    1861
 * Dislikes: 0
 * Total Accepted:    346.2K
 * Total Submissions: 674.8K
 * Testcase Example:  '[10,9,2,5,3,7,101,18]'
 *
 * 给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
 * 
 * 子序列是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7]
 * 的子序列。
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [10,9,2,5,3,7,101,18]
 * 输出：4
 * 解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [0,1,0,3,2,3]
 * 输出：4
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [7,7,7,7,7,7,7]
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * -10^4 
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 
 * 你可以设计时间复杂度为 O(n^2) 的解决方案吗？
 * 你能将算法的时间复杂度降低到 O(n log(n)) 吗?
 * 
 * 
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int length = nums.size(), piles = 0;
        vector<int> top(length, 1);
        for (int i = 0; i < length; i++)
        {
            int cur = nums[i];
            int left = 0, right = piles;
            while (left < right)
            {
                int mid = left + (right - left) / 2;
                if (top[mid] >= cur)
                    right = mid;
                else
                    left = mid + 1;
            }
            if (left == piles)
                piles++;
            top[left] = cur;
        }
        return piles;
    }
};
// @lc code=end
