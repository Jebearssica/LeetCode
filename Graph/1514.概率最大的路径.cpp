/*
 * @lc app=leetcode.cn id=1514 lang=cpp
 *
 * [1514] 概率最大的路径
 *
 * https://leetcode-cn.com/problems/path-with-maximum-probability/description/
 *
 * algorithms
 * Medium (33.06%)
 * Likes:    79
 * Dislikes: 0
 * Total Accepted:    8.6K
 * Total Submissions: 25.9K
 * Testcase Example:  '3\n[[0,1],[1,2],[0,2]]\n[0.5,0.5,0.2]\n0\n2'
 *
 * 给你一个由 n 个节点（下标从 0 开始）组成的无向加权图，该图由一个描述边的列表组成，其中 edges[i] = [a, b] 表示连接节点 a 和
 * b 的一条无向边，且该边遍历成功的概率为 succProb[i] 。
 *
 * 指定两个节点分别作为起点 start 和终点 end ，请你找出从起点到终点成功概率最大的路径，并返回其成功概率。
 *
 * 如果不存在从 start 到 end 的路径，请 返回 0 。只要答案与标准答案的误差不超过 1e-5 ，就会被视作正确答案。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.2], start = 0,
 * end = 2
 * 输出：0.25000
 * 解释：从起点到终点有两条路径，其中一条的成功概率为 0.2 ，而另一条为 0.5 * 0.5 = 0.25
 *
 *
 * 示例 2：
 *
 *
 *
 * 输入：n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.3], start = 0,
 * end = 2
 * 输出：0.30000
 *
 *
 * 示例 3：
 *
 *
 *
 * 输入：n = 3, edges = [[0,1]], succProb = [0.5], start = 0, end = 2
 * 输出：0.00000
 * 解释：节点 0 和 节点 2 之间不存在路径
 *
 *
 *
 *
 * 提示：
 *
 *
 * 2 <= n <= 10^4
 * 0 <= start, end < n
 * start != end
 * 0 <= a, b < n
 * a != b
 * 0 <= succProb.length == edges.length <= 2*10^4
 * 0 <= succProb[i] <= 1
 * 每两个节点之间最多有一条边
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
    double dijkstra(int start, int end, vector<vector<pair<int, double>>> &graph)
    {
        vector<double> maxProb(graph.size(), -1);
        maxProb[start] = 1;
        auto cmp = [&](const pair<int, double> &x, const pair<int, double> &y)
        { return x.second < y.second; };
        priority_queue<pair<int, double>, vector<pair<int, double>>, decltype(cmp)> pq(cmp);
        pq.push({start, 1.0});
        while (!pq.empty())
        {
            auto cur = pq.top();
            pq.pop();
            if (cur.first == end)
                return cur.second;
            if (cur.second < maxProb[cur.first])
                continue;
            for (auto neighbor : graph[cur.first])
            {
                double nextProb = neighbor.second * maxProb[cur.first];
                if (maxProb[neighbor.first] < nextProb)
                {
                    maxProb[neighbor.first] = nextProb;
                    pq.push({neighbor.first, nextProb});
                }
            }
        }
        return 0;
    }
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end)
    {
        // construct double link graph
        vector<vector<pair<int, double>>> graph(n);
        for (int idx = 0; idx < edges.size(); idx++)
        {
            graph[edges[idx][0]].push_back({edges[idx][1], succProb[idx]});
            graph[edges[idx][1]].push_back({edges[idx][0], succProb[idx]});
        }
        return dijkstra(start, end, graph);
    }
};
// @lc code=end
