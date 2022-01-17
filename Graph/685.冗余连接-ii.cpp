/*
 * @lc app=leetcode.cn id=685 lang=cpp
 *
 * [685] 冗余连接 II
 *
 * https://leetcode-cn.com/problems/redundant-connection-ii/description/
 *
 * algorithms
 * Hard (42.87%)
 * Likes:    277
 * Dislikes: 0
 * Total Accepted:    21.1K
 * Total Submissions: 49.3K
 * Testcase Example:  '[[1,2],[1,3],[2,3]]'
 *
 * 在本问题中，有根树指满足以下条件的 有向
 * 图。该树只有一个根节点，所有其他节点都是该根节点的后继。该树除了根节点之外的每一个节点都有且只有一个父节点，而根节点没有父节点。
 *
 * 输入一个有向图，该图由一个有着 n 个节点（节点值不重复，从 1 到 n）的树及一条附加的有向边构成。附加的边包含在 1 到 n
 * 中的两个不同顶点间，这条附加的边不属于树中已存在的边。
 *
 * 结果图是一个以边组成的二维数组 edges 。 每个元素是一对 [ui, vi]，用以表示 有向 图中连接顶点 ui 和顶点 vi 的边，其中 ui 是
 * vi 的一个父节点。
 *
 * 返回一条能删除的边，使得剩下的图是有 n 个节点的有根树。若有多个答案，返回最后出现在给定二维数组的答案。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：edges = [[1,2],[1,3],[2,3]]
 * 输出：[2,3]
 *
 *
 * 示例 2：
 *
 *
 * 输入：edges = [[1,2],[2,3],[3,4],[4,1],[1,5]]
 * 输出：[4,1]
 *
 *
 *
 *
 * 提示：
 *
 *
 * n == edges.length
 * 3
 * edges[i].length == 2
 * 1 i, vi
 *
 *
 */

// @lc code=start
#include <vector>
using namespace std;
class UF
{
private:
public:
    vector<int> parent;
    vector<int> indegree;
    int cnt;
    int find(int x)
    {
        while (this->parent[x] != x)
        {
            // this->parent[x] = this->parent[this->parent[x]];
            x = this->parent[x];
        }
        return x;
    }
    int findChild(int start, int target)
    {
        while (this->parent[start] != target)
        {
            // this->parent[start] = this->parent[this->parent[start]];
            // cout << "find child node: " << start << endl;
            start = this->parent[start];
        }
        return start;
    }
    bool unionRelation(int p, int q)
    {
        int rootP = find(p);
        int rootQ = find(q);
        if (rootP == rootQ)
            return false;
        this->parent[p] = q;
        this->indegree[q]++;
        return true;
    }
    bool isConflict(int x)
    {
        return this->indegree[x] == 1;
    }
    bool isConnect(int p, int q)
    {
        return find(p) == find(q);
    }
    UF(int n)
    {
        this->cnt = n;
        this->parent.resize(n);
        this->indegree.resize(n);
        for (int idx = 0; idx < n; idx++)
        {
            this->parent[idx] = idx;
            this->indegree[idx] = 1;
        }
    }
    ~UF() {}
};
class Solution
{
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges)
    {
        UF uf(edges.size() + 1);
        int conflict = -1, cycle = -1, idx = 0;
        for (auto edge : edges)
        {
            // this node's indgree is 2
            if (!uf.isConflict(edge[1]))
                conflict = idx;
            else if (!uf.unionRelation(edge[0], edge[1]))
                cycle = idx;
            ++idx;
        }
        if (conflict < 0)
            return edges[cycle];
        else if (cycle < 0)
            return edges[conflict];
        else
            return vector<int>{uf.findChild(edges[cycle][1], edges[conflict][1]), edges[conflict][1]};
    }
};
// @lc code=end
