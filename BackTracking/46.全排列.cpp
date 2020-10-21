/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 *
 * https://leetcode-cn.com/problems/permutations/description/
 *
 * algorithms
 * Medium (76.99%)
 * Likes:    956
 * Dislikes: 0
 * Total Accepted:    208.3K
 * Total Submissions: 270.4K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个 没有重复 数字的序列，返回其所有可能的全排列。
 * 
 * 示例:
 * 
 * 输入: [1,2,3]
 * 输出:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 */

// @lc code=start
#include <vector>
class Solution
{
public:
    std::vector<std::vector<int>> result;
    int length;
    void backtracking(std::vector<int> &nums, int index)
    {
        //current满了, 则压入result
        if (index == length)
        {
            result.push_back(nums);
            return;
        }

        for (int i = index; i < nums.size(); i++)
        {
            std::swap(nums[i], nums[index]);
            backtracking(nums, index + 1);
            std::swap(nums[i], nums[index]);
        }
    }
    std::vector<std::vector<int>> permute(std::vector<int> &nums)
    {
        length = nums.size();
        backtracking(nums, 0);
        return result;
    }
};
// @lc code=end
