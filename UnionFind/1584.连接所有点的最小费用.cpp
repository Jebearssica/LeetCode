/*
 * @lc app=leetcode.cn id=1584 lang=cpp
 *
 * [1584] 连接所有点的最小费用
 *
 * https://leetcode-cn.com/problems/min-cost-to-connect-all-points/description/
 *
 * algorithms
 * Medium (66.34%)
 * Likes:    181
 * Dislikes: 0
 * Total Accepted:    28.9K
 * Total Submissions: 43.6K
 * Testcase Example:  '[[0,0],[2,2],[3,10],[5,2],[7,0]]'
 *
 * 给你一个points 数组，表示 2D 平面上的一些点，其中 points[i] = [xi, yi] 。
 *
 * 连接点 [xi, yi] 和点 [xj, yj] 的费用为它们之间的 曼哈顿距离 ：|xi - xj| + |yi - yj| ，其中 |val| 表示
 * val 的绝对值。
 *
 * 请你返回将所有点连接的最小总费用。只有任意两点之间 有且仅有 一条简单路径时，才认为所有点都已连接。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入：points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
 * 输出：20
 * 解释：
 *
 * 我们可以按照上图所示连接所有点得到最小总费用，总费用为 20 。
 * 注意到任意两个点之间只有唯一一条路径互相到达。
 *
 *
 * 示例 2：
 *
 *
 * 输入：points = [[3,12],[-2,5],[-4,1]]
 * 输出：18
 *
 *
 * 示例 3：
 *
 *
 * 输入：points = [[0,0],[1,1],[1,0],[-1,1]]
 * 输出：4
 *
 *
 * 示例 4：
 *
 *
 * 输入：points = [[-1000000,-1000000],[1000000,1000000]]
 * 输出：4000000
 *
 *
 * 示例 5：
 *
 *
 * 输入：points = [[0,0]]
 * 输出：0
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= points.length <= 1000
 * -10^6 <= xi, yi <= 10^6
 * 所有点 (xi, yi) 两两不同。
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
    int find(int x)
    {
        while (this->parent[x] != x)
        {
            this->parent[x] = this->parent[this->parent[x]];
            x = this->parent[x];
        }
        return x;
    }
    bool merge(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY)
            return false;
        if (this->size[rootX] < this->size[rootY])
            swap(rootX, rootY);
        this->parent[rootY] = rootX;
        this->size[rootX] += this->size[rootY];
        return true;
    }
    bool isConnect(int x, int y)
    {
        return find(x) == find(y);
    }
    UF(int n)
    {
        this->size.resize(n, 1);
        this->parent.resize(n);
        this->cnt = n;
        for (int idx = 0; idx < n; idx++)
            this->parent[idx] = idx;
    }
    ~UF() {}
};
struct weightEdge
{
    int xIdx, yIdx, weight;
    weightEdge(int x, int y, int w) : xIdx(x), yIdx(y), weight(w)
    {
    }
};

class Solution
{
public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        auto dist = [&](int x, int y) -> int
        {
            return abs(points[x][0] - points[y][0]) + abs(points[x][1] - points[y][1]);
        };

        int length = points.size();
        vector<weightEdge> graph;
        for (int i = 0; i < length; ++i)
            for (int j = i + 1; j < length; ++j)
                graph.emplace_back(i, j, dist(i, j));
        sort(graph.begin(), graph.end(), [](weightEdge g1, weightEdge g2)
             { return g1.weight < g2.weight; });
        int mst = 0, vNum = 1;
        UF uf(length);
        for (auto line : graph)
        {
            if (uf.merge(line.xIdx, line.yIdx))
            {
                mst += line.weight;
                if (++vNum == graph.size())
                    break;
            }
        }
        return mst;
    }
};
// @lc code=end
