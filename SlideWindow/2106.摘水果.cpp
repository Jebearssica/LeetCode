/*
 * @lc app=leetcode.cn id=2106 lang=cpp
 *
 * [2106] 摘水果
 *
 * https://leetcode-cn.com/problems/maximum-fruits-harvested-after-at-most-k-steps/description/
 *
 * algorithms
 * Hard (28.83%)
 * Likes:    13
 * Dislikes: 0
 * Total Accepted:    2K
 * Total Submissions: 7.1K
 * Testcase Example:  '[[2,8],[6,3],[8,6]]\n5\n4'
 *
 * 在一个无限的 x 坐标轴上，有许多水果分布在其中某些位置。给你一个二维整数数组 fruits ，其中 fruits[i] = [positioni,
 * amounti] 表示共有 amounti 个水果放置在 positioni 上。fruits 已经按 positioni 升序排列 ，每个
 * positioni 互不相同 。
 *
 * 另给你两个整数 startPos 和 k 。最初，你位于 startPos 。从任何位置，你可以选择 向左或者向右 走。在 x 轴上每移动 一个单位
 * ，就记作 一步 。你总共可以走 最多 k 步。你每达到一个位置，都会摘掉全部的水果，水果也将从该位置消失（不会再生）。
 *
 * 返回你可以摘到水果的 最大总数 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：fruits = [[2,8],[6,3],[8,6]], startPos = 5, k = 4
 * 输出：9
 * 解释：
 * 最佳路线为：
 * - 向右移动到位置 6 ，摘到 3 个水果
 * - 向右移动到位置 8 ，摘到 6 个水果
 * 移动 3 步，共摘到 3 + 6 = 9 个水果
 *
 *
 * 示例 2：
 *
 * 输入：fruits = [[0,9],[4,1],[5,7],[6,2],[7,4],[10,9]], startPos = 5, k = 4
 * 输出：14
 * 解释：
 * 可以移动最多 k = 4 步，所以无法到达位置 0 和位置 10 。
 * 最佳路线为：
 * - 在初始位置 5 ，摘到 7 个水果
 * - 向左移动到位置 4 ，摘到 1 个水果
 * - 向右移动到位置 6 ，摘到 2 个水果
 * - 向右移动到位置 7 ，摘到 4 个水果
 * 移动 1 + 3 = 4 步，共摘到 7 + 1 + 2 + 4 = 14 个水果
 *
 *
 * 示例 3：
 *
 * 输入：fruits = [[0,3],[6,4],[8,5]], startPos = 3, k = 2
 * 输出：0
 * 解释：
 * 最多可以移动 k = 2 步，无法到达任一有水果的地方
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= fruits.length <= 10^5
 * fruits[i].length == 2
 * 0 <= startPos, positioni <= 2 * 10^5
 * 对于任意 i > 0 ，positioni-1 < positioni 均成立（下标从 0 开始计数）
 * 1 <= amounti <= 10^4
 * 0 <= k <= 2 * 10^5
 *
 *
 */

// @lc code=start
#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    int maxTotalFruits(vector<vector<int>> &fruits, int startPos, int k)
    {
        deque<vector<int>> q;
        int res = 0, idx = 0, maxSize = fruits.size();
        while (idx < maxSize && fruits[idx][0] <= startPos)
        {
            if (abs(fruits[idx][0] - startPos) <= k)
            {
                res += fruits[idx][1];
                q.push_back(fruits[idx]);
            }
            idx++;
        }
        int cur = res;
        while (idx < maxSize && fruits[idx][0] - startPos <= k)
        {
            while (!q.empty() && q.front()[0] < startPos && fruits[idx][0] - q.front()[0] + min(startPos - q.front()[0], fruits[idx][0] - startPos) > k)
            {
                cur -= q.front()[1];
                q.pop_front();
            }
            cur += fruits[idx++][1];
            res = max(res, cur);
        }
        return res;
    }
};
// @lc code=end
