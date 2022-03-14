/*
 * @lc app=leetcode.cn id=1135 lang=cpp
 *
 * [1135] 最低成本联通所有城市
 *
 * https://leetcode-cn.com/problems/connecting-cities-with-minimum-cost/description/
 *
 * algorithms
 * Medium (54.87%)
 * Likes:    79
 * Dislikes: 0
 * Total Accepted:    7.8K
 * Total Submissions: 14.3K
 * Testcase Example:  '3\n[[1,2,5],[1,3,6],[2,3,1]]'
 *
 * 想象一下你是个城市基建规划者，地图上有 n 座城市，它们按以 1 到 n 的次序编号。
 *
 * 给你整数 n 和一个数组 conections，其中 connections[i] = [xi, yi, costi] 表示将城市 xi 和城市 yi
 * 连接所要的costi（连接是双向的）。
 *
 * 返回连接所有城市的最低成本，每对城市之间至少有一条路径。如果无法连接所有 n 个城市，返回 -1
 *
 * 该 最小成本 应该是所用全部连接成本的总和。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入：n = 3, conections = [[1,2,5],[1,3,6],[2,3,1]]
 * 输出：6
 * 解释：选出任意 2 条边都可以连接所有城市，我们从中选取成本最小的 2 条。
 *
 *
 * 示例 2：
 *
 *
 *
 *
 * 输入：n = 4, conections = [[1,2,3],[3,4,4]]
 * 输出：-1
 * 解释：即使连通所有的边，也无法连接所有城市。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 10^4
 * 1 <= connections.length <= 10^4
 * connections[i].length == 3
 * 1 <= xi, yi <= n
 * xi != yi
 * 0 <= costi <= 10^5
 *
 *
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class UF
{
private:
    vector<int> size;
    vector<int> parent;
    int cnt;

public:
    int retCount()
    {
        return this->cnt;
    }
    bool merge(int nodeX, int nodeY)
    {
        int rootX = find(nodeX), rootY = find(nodeY);
        if (rootX == rootY)
            return false;
        if (this->size[rootX] < this->size[rootY])
            swap(nodeX, nodeY);
        this->parent[rootY] = rootX;
        this->size[rootX] += this->size[rootY];
        --this->cnt;
        return true;
    }
    int find(int node)
    {
        while (node != this->parent[node])
        {
            this->parent[node] = this->parent[this->parent[node]];
            node = this->parent[node];
        }
        return node;
    }
    bool isConnect(int nodeX, int nodeY)
    {
        return find(nodeX) == find(nodeY);
    }
    UF(int nodeNumber) : cnt(nodeNumber)
    {
        this->parent.resize(nodeNumber);
        this->size.resize(nodeNumber, 0);
        for (int idx = 0; idx < nodeNumber; ++idx)
            this->parent[idx] = idx;
    }
    ~UF() {}
};
class Solution
{
public:
    int minimumCost(int n, vector<vector<int>> &connections)
    {
        UF uf(n);
        sort(connections.begin(), connections.end(), [&](vector<int> &a, vector<int> &b)
             { return a[2] < b[2]; });
        int minWeight = 0;
        for (auto &edge : connections)
        {
            if (!uf.merge(edge[0] - 1, edge[1] - 1))
                continue;
            minWeight += edge[2];
            if (uf.retCount() == 1)
                return minWeight;
        }
        return -1;
    }
};
// @lc code=end
