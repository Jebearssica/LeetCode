/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 *
 * https://leetcode-cn.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (71.43%)
 * Likes:    996
 * Dislikes: 0
 * Total Accepted:    171.6K
 * Total Submissions: 240.1K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * 给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 * 
 * candidates 中的数字可以无限制重复被选取。
 * 
 * 说明：
 * 
 * 
 * 所有数字（包括 target）都是正整数。
 * 解集不能包含重复的组合。 
 * 
 * 
 * 示例 1：
 * 
 * 输入：candidates = [2,3,6,7], target = 7,
 * 所求解集为：
 * [
 * ⁠ [7],
 * ⁠ [2,2,3]
 * ]
 * 
 * 
 * 示例 2：
 * 
 * 输入：candidates = [2,3,5], target = 8,
 * 所求解集为：
 * [
 * [2,2,2,2],
 * [2,3,3],
 * [3,5]
 * ]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= candidates.length <= 30
 * 1 <= candidates[i] <= 200
 * candidate 中的每个元素都是独一无二的。
 * 1 <= target <= 500
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <algorithm>
class Solution
{
public:
    //结果
    std::vector<std::vector<int>> result;
    //即将压入结果的数组
    std::vector<int> current;
    int tempTarget = 0;

    void dfs(std::vector<int> &candidates, int target, int index)
    {
        if (tempTarget == target)
        {
            result.push_back(current);
            return;
        }
        for (int i = index; i < candidates.size(); i++)
        {
            //肯定后面的都没戏了, 直接跳出
            if (tempTarget + candidates[i] > target)
                return;
            tempTarget += candidates[i];
            current.push_back(candidates[i]);
            dfs(candidates, target, i);
            tempTarget -= candidates[i];
            current.pop_back();
        }
    }
    std::vector<std::vector<int>> combinationSum(std::vector<int> &candidates, int target)
    {
        //排序方便剪枝
        std::sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0);
        return result;
    }
};
// @lc code=end
