/*
 * @lc app=leetcode.cn id=1631 lang=cpp
 *
 * [1631] 最小体力消耗路径
 *
 * https://leetcode-cn.com/problems/path-with-minimum-effort/description/
 *
 * algorithms
 * Medium (49.38%)
 * Likes:    257
 * Dislikes: 0
 * Total Accepted:    26.6K
 * Total Submissions: 53.9K
 * Testcase Example:  '[[1,2,2],[3,8,2],[5,3,5]]'
 *
 * 你准备参加一场远足活动。给你一个二维 rows x columns 的地图 heights ，其中 heights[row][col] 表示格子
 * (row, col) 的高度。一开始你在最左上角的格子 (0, 0) ，且你希望去最右下角的格子 (rows-1, columns-1) （注意下标从
 * 0 开始编号）。你每次可以往 上，下，左，右 四个方向之一移动，你想要找到耗费 体力 最小的一条路径。
 *
 * 一条路径耗费的 体力值 是路径上相邻格子之间 高度差绝对值 的 最大值 决定的。
 *
 * 请你返回从左上角走到右下角的最小 体力消耗值 。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入：heights = [[1,2,2],[3,8,2],[5,3,5]]
 * 输出：2
 * 解释：路径 [1,3,5,3,5] 连续格子的差值绝对值最大为 2 。
 * 这条路径比路径 [1,2,2,2,5] 更优，因为另一条路径差值最大值为 3 。
 *
 *
 * 示例 2：
 *
 *
 *
 *
 * 输入：heights = [[1,2,3],[3,8,4],[5,3,5]]
 * 输出：1
 * 解释：路径 [1,2,3,4,5] 的相邻格子差值绝对值最大为 1 ，比路径 [1,3,5,3,5] 更优。
 *
 *
 * 示例 3：
 *
 *
 * 输入：heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
 * 输出：0
 * 解释：上图所示路径不需要消耗任何体力。
 *
 *
 *
 *
 * 提示：
 *
 *
 * rows == heights.length
 * columns == heights[i].length
 * 1
 * 1
 *
 *
 */

// @lc code=start
#include <vector>
#include <queue>
using namespace std;
class Solution
{
private:
    static constexpr int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        vector<vector<int>> adj(heights.size(), vector<int>(heights[0].size(), 0x3f3f3f3f));
        adj[0][0] = 0;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        pq.push({0, 0, 0});
        while (!pq.empty())
        {
            tuple<int, int, int> curEdge = pq.top();
            pq.pop();
            // arrive the target
            if (get<0>(curEdge) == heights.size() - 1 && get<1>(curEdge) == heights[0].size() - 1)
                return get<2>(curEdge);
            if (get<2>(curEdge) > adj[get<0>(curEdge)][get<1>(curEdge)])
                continue;
            // search the up/down/left/right neighbors
            for (int idx = 0; idx < 4; idx++)
            {
                int nextX = dir[idx][0] + get<0>(curEdge), nextY = dir[idx][1] + get<1>(curEdge);
                if (nextX >= heights.size() || nextX < 0 || nextY >= heights[0].size() || nextY < 0)
                    continue;
                int nextWeight = max(abs(adj[get<0>(curEdge)][get<1>(curEdge)]), abs(heights[get<0>(curEdge)][get<1>(curEdge)] - heights[nextX][nextY]));
                if (adj[nextX][nextY] > nextWeight)
                {
                    adj[nextX][nextY] = nextWeight;
                    pq.push({nextX, nextY, nextWeight});
                }
            }
        }
        return -1;
    }
};
// @lc code=end
