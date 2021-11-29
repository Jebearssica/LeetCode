/*
 * @lc app=leetcode.cn id=743 lang=cpp
 *
 * [743] 网络延迟时间
 *
 * https://leetcode-cn.com/problems/network-delay-time/description/
 *
 * algorithms
 * Medium (52.35%)
 * Likes:    457
 * Dislikes: 0
 * Total Accepted:    61.1K
 * Total Submissions: 116.6K
 * Testcase Example:  '[[2,1,1],[2,3,1],[3,4,1]]\n4\n2'
 *
 * 有 n 个网络节点，标记为 1 到 n。
 * 
 * 给你一个列表 times，表示信号经过 有向 边的传递时间。 times[i] = (ui, vi, wi)，其中 ui 是源节点，vi 是目标节点，
 * wi 是一个信号从源节点传递到目标节点的时间。
 * 
 * 现在，从某个节点 K 发出一个信号。需要多久才能使所有节点都收到信号？如果不能使所有节点收到信号，返回 -1 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
 * 输出：2
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：times = [[1,2,1]], n = 2, k = 1
 * 输出：1
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：times = [[1,2,1]], n = 2, k = 2
 * 输出：-1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= k <= n <= 100
 * 1 <= times.length <= 6000
 * times[i].length == 3
 * 1 <= ui, vi <= n
 * ui != vi
 * 0 <= wi <= 100
 * 所有 (ui, vi) 对都 互不相同（即，不含重复边）
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
    vector<int> dijkstra(int start, vector<vector<pair<int, int>>> &adj)
    {
        vector<int> dis(adj.size(), 0x3f3f3f3f);
        dis[start] = 0;
        auto cmp = [&](const pair<int, int> &x, const pair<int, int> &y)
        { return x.second > y.second; };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        pq.push({start, 0});
        while (!pq.empty())
        {
            auto [cur, time] = pq.top();
            pq.pop();
            if (time > dis[cur])
                continue;
            for (auto neighbor : adj[cur])
            {
                if (dis[neighbor.first] > time + neighbor.second)
                {
                    dis[neighbor.first] = time + neighbor.second;
                    pq.push({neighbor.first, time + neighbor.second});
                }
            }
        }
        return dis;
    }
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<vector<pair<int, int>>> adj(n);
        for (auto edge : times)
            adj[edge[0] - 1].push_back({edge[1] - 1, edge[2]});
        vector<int> dist = dijkstra(k - 1, adj);
        int res = 0;
        for (int dis : dist)
        {
            if (dis == 0x3f3f3f3f)
                return -1;
            res = max(res, dis);
        }
        return res;
    }
};
// @lc code=end
