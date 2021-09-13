/*
 * @lc app=leetcode.cn id=354 lang=cpp
 *
 * [354] 俄罗斯套娃信封问题
 *
 * https://leetcode-cn.com/problems/russian-doll-envelopes/description/
 *
 * algorithms
 * Hard (45.00%)
 * Likes:    580
 * Dislikes: 0
 * Total Accepted:    68.4K
 * Total Submissions: 151.4K
 * Testcase Example:  '[[5,4],[6,4],[6,7],[2,3]]'
 *
 * 给你一个二维整数数组 envelopes ，其中 envelopes[i] = [wi, hi] ，表示第 i 个信封的宽度和高度。
 * 
 * 当另一个信封的宽度和高度都比这个信封大的时候，这个信封就可以放进另一个信封里，如同俄罗斯套娃一样。
 * 
 * 请计算 最多能有多少个 信封能组成一组“俄罗斯套娃”信封（即可以把一个信封放到另一个信封里面）。
 * 
 * 注意：不允许旋转信封。
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：envelopes = [[5,4],[6,4],[6,7],[2,3]]
 * 输出：3
 * 解释：最多信封的个数为 3, 组合为: [2,3] => [5,4] => [6,7]。
 * 
 * 示例 2：
 * 
 * 
 * 输入：envelopes = [[1,1],[1,1],[1,1]]
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * envelopes[i].length == 2
 * 1 i, hi 
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <algorithm>
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
    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        int length = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), [](auto &env1, auto &env2)
             { return env1[0] < env2[0] || (env1[0] == env2[0] && env1[1] > env2[1]); });
        vector<int> dp(length, 0);
        for (int i = 0; i < length; i++)
        {
            dp[i] = envelopes[i][1];
        }
        return lengthOfLIS(dp);
    }
};
// @lc code=end
