/*
 * @lc app=leetcode.cn id=659 lang=cpp
 *
 * [659] 分割数组为连续子序列
 *
 * https://leetcode-cn.com/problems/split-array-into-consecutive-subsequences/description/
 *
 * algorithms
 * Medium (54.23%)
 * Likes:    364
 * Dislikes: 0
 * Total Accepted:    30.3K
 * Total Submissions: 55.9K
 * Testcase Example:  '[1,2,3,3,4,5]'
 *
 * 给你一个按升序排序的整数数组 num（可能包含重复数字），请你将它们分割成一个或多个长度至少为 3 的子序列，其中每个子序列都由连续整数组成。
 *
 * 如果可以完成上述分割，则返回 true ；否则，返回 false 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入: [1,2,3,3,4,5]
 * 输出: True
 * 解释:
 * 你可以分割出这样两个连续子序列 :
 * 1, 2, 3
 * 3, 4, 5
 *
 *
 * 示例 2：
 *
 *
 * 输入: [1,2,3,3,4,4,5,5]
 * 输出: True
 * 解释:
 * 你可以分割出这样两个连续子序列 :
 * 1, 2, 3, 4, 5
 * 3, 4, 5
 *
 *
 * 示例 3：
 *
 *
 * 输入: [1,2,3,4,4,5]
 * 输出: False
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 *
 *
 */

// @lc code=start
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    bool isPossible(vector<int> &nums)
    {
        unordered_map<int, int> freq, need;
        for (auto &n : nums)
            ++freq[n];
        for (auto &n : nums)
        {
            if (freq[n] == 0)
                continue;
            if (need.find(n) != need.end() && need[n] > 0)
            {
                --freq[n];
                --need[n];
                ++need[n + 1];
            }
            else if (freq[n] > 0 && freq[n + 1] > 0 && freq[n + 2] > 0)
            {
                --freq[n], --freq[n + 1], --freq[n + 2];
                ++need[n + 3];
            }
            else
                return false;
        }
        return true;
    }
};
// @lc code=end
