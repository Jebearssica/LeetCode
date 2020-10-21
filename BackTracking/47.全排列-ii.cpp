/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 *
 * https://leetcode-cn.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (61.95%)
 * Likes:    501
 * Dislikes: 0
 * Total Accepted:    116.1K
 * Total Submissions: 187K
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个可包含重复数字的序列，返回所有不重复的全排列。
 * 
 * 示例:
 * 
 * 输入: [1,1,2]
 * 输出:
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
 * ]
 * 
 */

// @lc code=start
#include <vector>
#include <algorithm>
class Solution
{
public:
    std::vector<std::vector<int>> result;
    std::vector<int> isVisted;
    std::vector<int> current;
    int length;
    void backtracking(std::vector<int> &nums, int index)
    {
        //current满了, 则压入result
        if (index == length)
        {
            result.push_back(current);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (isVisted[i] || (i > 0 && nums[i] == nums[i - 1] && !isVisted[i - 1]))
                continue;
            current.push_back(nums[i]);
            isVisted[i] = 1;
            backtracking(nums, index + 1);
            isVisted[i] = 0;
            current.pop_back();
        }
    }
    std::vector<std::vector<int>> permuteUnique(std::vector<int> &nums)
    {
        length = nums.size();
        isVisted.resize(nums.size());
        std::sort(nums.begin(), nums.end());
        backtracking(nums, 0);
        return result;
    }
};
// @lc code=end
