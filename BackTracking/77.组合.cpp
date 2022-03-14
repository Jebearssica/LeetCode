/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 *
 * https://leetcode-cn.com/problems/combinations/description/
 *
 * algorithms
 * Medium (76.95%)
 * Likes:    867
 * Dislikes: 0
 * Total Accepted:    280.8K
 * Total Submissions: 364.9K
 * Testcase Example:  '4\n2'
 *
 * 给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。
 *
 * 你可以按 任何顺序 返回答案。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：n = 4, k = 2
 * 输出：
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 *
 * 示例 2：
 *
 *
 * 输入：n = 1, k = 1
 * 输出：[[1]]
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
using namespace std;
class Solution
{
public:
    vector<vector<int>> res;
    void backtracing(vector<int> &cur, int start, int end, int k)
    {
        if(cur.size() == k)
        {
            res.push_back(cur);
            return;
        }
        for(int i = start; i <= end; ++i)
        {
            cur.push_back(i);
            backtracing(cur, i + 1, end, k);
            cur.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k)
    {
        vector<int> cur;
        backtracing(cur, 1, n, k);
        return res;
    }
};
// @lc code=end
