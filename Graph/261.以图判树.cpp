/*
 * @lc app=leetcode.cn id=261 lang=cpp
 *
 * [261] 以图判树
 *
 * https://leetcode-cn.com/problems/graph-valid-tree/description/
 *
 * algorithms
 * Medium (50.20%)
 * Likes:    159
 * Dislikes: 0
 * Total Accepted:    10.8K
 * Total Submissions: 21.6K
 * Testcase Example:  '5\n[[0,1],[0,2],[0,3],[1,4]]'
 *
 * 给定编号从 0 到 n - 1 的 n 个结点。给定一个整数 n 和一个 edges 列表，其中 edges[i] = [ai, bi] 表示图中节点
 * ai 和 bi 之间存在一条无向边。
 *
 * 如果这些边能够形成一个合法有效的树结构，则返回 true ，否则返回 false 。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入: n = 5, edges = [[0,1],[0,2],[0,3],[1,4]]
 * 输出: true
 *
 * 示例 2:
 *
 *
 *
 *
 * 输入: n = 5, edges = [[0,1],[1,2],[2,3],[1,3],[1,4]]
 * 输出: false
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 2000
 * 0 <= edges.length <= 5000
 * edges[i].length == 2
 * 0 <= ai, bi < n
 * ai != bi
 * 不存在自循环或重复的边
 *
 *
 */

// @lc code=start
#include <vector>
using namespace std;
class UF
{
private:
    vector<int> size;
    int cnt;
    vector<int> parent;

public:
    int connectCount()
    {
        return this->cnt;
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
    bool merge(int nodeX, int nodeY)
    {
        int rootX = find(nodeX), rootY = find(nodeY);
        if (rootX == rootY)
            return false;
        if (this->size[rootX] < this->size[rootY])
            swap(rootX, rootY);
        this->parent[rootY] = rootX;
        this->size[rootX] += this->size[rootY];
        --this->cnt;
        return true;
    }
    UF(int nodeNumber)
    {
        this->cnt = nodeNumber;
        this->size.resize(nodeNumber, 0);
        this->parent.resize(nodeNumber);
        for (int idx = 0; idx < nodeNumber; ++idx)
            this->parent[idx] = idx;
    }
    ~UF() {}
};
class Solution
{
public:
    bool validTree(int n, vector<vector<int>> &edges)
    {
        UF uf(n);
        for (auto &e : edges)
            if (!uf.merge(e[0], e[1]))
                return false;
        return uf.connectCount() == 1;
    }
};
// @lc code=end
