/*
 * @lc app=leetcode.cn id=2203 lang=cpp
 *
 * [2203] 得到要求路径的最小带权子图
 *
 * https://leetcode-cn.com/problems/minimum-weighted-subgraph-with-the-required-paths/description/
 *
 * algorithms
 * Hard (32.41%)
 * Likes:    22
 * Dislikes: 0
 * Total Accepted:    2.2K
 * Total Submissions: 6.7K
 * Testcase Example:  '6\n[[0,2,2],[0,5,6],[1,0,3],[1,4,5],[2,1,1],[2,3,3],[2,3,4],[3,4,2],[4,5,1]]\n0\n1\n5'
 *
 * 给你一个整数 n ，它表示一个 带权有向 图的节点数，节点编号为 0 到 n - 1 。
 *
 * 同时给你一个二维整数数组 edges ，其中 edges[i] = [fromi, toi, weighti] ，表示从 fromi 到 toi
 * 有一条边权为 weighti 的 有向 边。
 *
 * 最后，给你三个 互不相同 的整数 src1 ，src2 和 dest ，表示图中三个不同的点。
 *
 * 请你从图中选出一个 边权和最小 的子图，使得从 src1 和 src2 出发，在这个子图中，都 可以 到达 dest 。如果这样的子图不存在，请返回
 * -1 。
 *
 * 子图 中的点和边都应该属于原图的一部分。子图的边权和定义为它所包含的所有边的权值之和。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入：n = 6, edges =
 * [[0,2,2],[0,5,6],[1,0,3],[1,4,5],[2,1,1],[2,3,3],[2,3,4],[3,4,2],[4,5,1]],
 * src1 = 0, src2 = 1, dest = 5
 * 输出：9
 * 解释：
 * 上图为输入的图。
 * 蓝色边为最优子图之一。
 * 注意，子图 [[1,0,3],[0,5,6]] 也能得到最优解，但无法在满足所有限制的前提下，得到更优解。
 *
 *
 * 示例 2：
 *
 *
 *
 *
 * 输入：n = 3, edges = [[0,1,1],[2,1,1]], src1 = 0, src2 = 1, dest = 2
 * 输出：-1
 * 解释：
 * 上图为输入的图。
 * 可以看到，不存在从节点 1 到节点 2 的路径，所以不存在任何子图满足所有限制。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 3 <= n <= 10^5
 * 0 <= edges.length <= 10^5
 * edges[i].length == 3
 * 0 <= fromi, toi, src1, src2, dest <= n - 1
 * fromi != toi
 * src1 ，src2 和 dest 两两不同。
 * 1 <= weight[i] <= 10^5
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
    static constexpr long long MAX = 1e10 + 1;
    vector<long long> dijkstra(int start, vector<vector<pair<int, int>>> &G)
    {
        vector<long long> dist(G.size(), MAX);
        dist[start] = 0;
        auto cmp = [&](const pair<int, long long> &x, const pair<int, long long> &y)
        { return x.second > y.second; };
        priority_queue<pair<int, long long>, vector<pair<int, long long>>, decltype(cmp)> pq(cmp);
        pq.emplace(start, 0);
        while (!pq.empty())
        {
            auto [cur, weight] = pq.top();
            pq.pop();
            if (weight > dist[cur])
                continue;
            for (auto &[adj, adjW] : G[cur])
            {
                if (dist[adj] > adjW + weight)
                {
                    dist[adj] = adjW + weight;
                    pq.emplace(adj, dist[adj]);
                }
            }
        }
        return dist;
    }
    long long minimumWeight(int n, vector<vector<int>> &edges, int src1, int src2, int dest)
    {
        vector<vector<pair<int, int>>> G(n), reverseG(n);
        for (auto &e : edges)
        {
            G[e[0]].emplace_back(e[1], e[2]);
            reverseG[e[1]].emplace_back(e[0], e[2]);
        }
        vector<long long> src1ToAll = dijkstra(src1, G), src2ToAll = dijkstra(src2, G), dstToAll = dijkstra(dest, reverseG);
        long long res = MAX;
        for (int idx = 0; idx < n; ++idx)
        {
            res = min(res, src1ToAll[idx] + src2ToAll[idx] + dstToAll[idx]);
        }
        if (res >= MAX)
            return -1;
        return res;
    }
};
// @lc code=end
