/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 *
 * https://leetcode-cn.com/problems/subsets/description/
 *
 * algorithms
 * Medium (80.35%)
 * Likes:    1484
 * Dislikes: 0
 * Total Accepted:    373.7K
 * Total Submissions: 465.1K
 * Testcase Example:  '[1,2,3]'
 *
 * 给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。
 *
 * 解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [1,2,3]
 * 输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [0]
 * 输出：[[],[0]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * -10
 * nums 中的所有元素 互不相同
 *
 *
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> res;
    void backtracing(vector<int> &nums, int start, vector<int> &cur)
    {
        res.push_back(cur);
        for (int idx = start; idx < nums.size(); ++idx)
        {
            cur.push_back(nums[idx]);
            backtracing(nums, idx + 1, cur);
            cur.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<int> cur;
        backtracing(nums, 0, cur);
        return res;
    }
};
// @lc code=end
