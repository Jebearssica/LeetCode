/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 *
 * https://leetcode-cn.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (64.53%)
 * Likes:    423
 * Dislikes: 0
 * Total Accepted:    112.4K
 * Total Submissions: 174.1K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * 给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 * 
 * candidates 中的每个数字在每个组合中只能使用一次。
 * 
 * 说明：
 * 
 * 
 * 所有数字（包括目标数）都是正整数。
 * 解集不能包含重复的组合。 
 * 
 * 
 * 示例 1:
 * 
 * 输入: candidates = [10,1,2,7,6,1,5], target = 8,
 * 所求解集为:
 * [
 * ⁠ [1, 7],
 * ⁠ [1, 2, 5],
 * ⁠ [2, 6],
 * ⁠ [1, 1, 6]
 * ]
 * 
 * 
 * 示例 2:
 * 
 * 输入: candidates = [2,5,2,1,2], target = 5,
 * 所求解集为:
 * [
 * [1,2,2],
 * [5]
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
    std::vector<int> current;
    int tempSum = 0;
    void backtracking(std::vector<int> &candidates, int target, int index)
    {
        if (tempSum == target)
        {
            result.push_back(current);
            return;
        }
        for (int i = index; i < candidates.size(); i++)
        {
            if (tempSum + candidates[i] > target)
                return;
            //跳转到下一个非重复项
            if (i > index && candidates[i] == candidates[i - 1])
                continue;
            tempSum += candidates[i];
            current.push_back(candidates[i]);
            backtracking(candidates, target, i + 1);
            current.pop_back();
            tempSum -= candidates[i];
        }
    }
    std::vector<std::vector<int>> combinationSum2(std::vector<int> &candidates, int target)
    {
        //先排个序
        std::sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0);
        return result;
    }
};
// @lc code=end
