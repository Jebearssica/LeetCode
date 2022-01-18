/*
 * @lc app=leetcode.cn id=1524 lang=cpp
 *
 * [1524] 和为奇数的子数组数目
 *
 * https://leetcode-cn.com/problems/number-of-sub-arrays-with-odd-sum/description/
 *
 * algorithms
 * Medium (43.38%)
 * Likes:    35
 * Dislikes: 0
 * Total Accepted:    5.5K
 * Total Submissions: 12.6K
 * Testcase Example:  '[1,3,5]'
 *
 * 给你一个整数数组 arr 。请你返回和为 奇数 的子数组数目。
 *
 * 由于答案可能会很大，请你将结果对 10^9 + 7 取余后返回。
 *
 *
 *
 * 示例 1：
 *
 * 输入：arr = [1,3,5]
 * 输出：4
 * 解释：所有的子数组为 [[1],[1,3],[1,3,5],[3],[3,5],[5]] 。
 * 所有子数组的和为 [1,4,9,3,8,5].
 * 奇数和包括 [1,9,3,5] ，所以答案为 4 。
 *
 *
 * 示例 2 ：
 *
 * 输入：arr = [2,4,6]
 * 输出：0
 * 解释：所有子数组为 [[2],[2,4],[2,4,6],[4],[4,6],[6]] 。
 * 所有子数组和为 [2,6,12,4,10,6] 。
 * 所有子数组和都是偶数，所以答案为 0 。
 *
 *
 * 示例 3：
 *
 * 输入：arr = [1,2,3,4,5,6,7]
 * 输出：16
 *
 *
 * 示例 4：
 *
 * 输入：arr = [100,100,99,99]
 * 输出：4
 *
 *
 * 示例 5：
 *
 * 输入：arr = [7]
 * 输出：1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= arr.length <= 10^5
 * 1 <= arr[i] <= 100
 *
 *
 */

// @lc code=start
#include <vector>
using namespace std;
const int MOD = 1000000007;
class Solution
{
public:
    int numOfSubarrays(vector<int> &arr)
    {
        vector<int> dp(arr.size(), 0);
        // init: dp[0]
        if (arr[0] % 2 == 1)
            dp[0] = 1;
        int res = dp[0];
        for (int idx = 1; idx < arr.size(); idx++)
        {
            if (arr[idx] % 2 == 1)
                dp[idx] = 1 + idx - dp[idx - 1];
            else
                dp[idx] = dp[idx - 1];
            res = (res + dp[idx]) % MOD;
        }
        return res;
    }
};
// @lc code=end
