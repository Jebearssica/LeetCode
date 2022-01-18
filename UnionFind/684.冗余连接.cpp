/*
 * @lc app=leetcode.cn id=684 lang=cpp
 *
 * [684] 冗余连接
 *
 * https://leetcode-cn.com/problems/redundant-connection/description/
 *
 * algorithms
 * Medium (66.66%)
 * Likes:    423
 * Dislikes: 0
 * Total Accepted:    65.3K
 * Total Submissions: 97.8K
 * Testcase Example:  '[[1,2],[1,3],[2,3]]'
 *
 * 树可以看成是一个连通且 无环 的 无向 图。
 *
 * 给定往一棵 n 个节点 (节点值 1～n) 的树中添加一条边后的图。添加的边的两个顶点包含在 1 到 n
 * 中间，且这条附加的边不属于树中已存在的边。图的信息记录于长度为 n 的二维数组 edges ，edges[i] = [ai, bi] 表示图中在 ai
 * 和 bi 之间存在一条边。
 *
 * 请找出一条可以删去的边，删除后可使得剩余部分是一个有着 n 个节点的树。如果有多个答案，则返回数组 edges 中最后出现的边。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入: edges = [[1,2], [1,3], [2,3]]
 * 输出: [2,3]
 *
 *
 * 示例 2：
 *
 *
 *
 *
 * 输入: edges = [[1,2], [2,3], [3,4], [1,4], [1,5]]
 * 输出: [1,4]
 *
 *
 *
 *
 * 提示:
 *
 *
 * n == edges.length
 * 3
 * edges[i].length == 2
 * 1
 * ai != bi
 * edges 中无重复元素
 * 给定的图是连通的 
 *
 *
 */

// @lc code=start
#include <vector>
using namespace std;
class UF
{
private:
    vector<int> parent;
    vector<int> size;
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
    void unionRelation(int p, int q)
    {
        int rootP = find(p);
        int rootQ = find(q);
        if (rootP == rootQ)
            return;
        if (this->size[rootP] > this->size[rootQ])
        {
            this->parent[rootQ] = rootP;
            this->size[rootP] += this->size[rootQ];
        }
        else
        {
            this->parent[rootP] = rootQ;
            this->size[rootQ] += this->size[rootP];
        }
    }
    bool isConnect(int p, int q)
    {
        return find(p) == find(q);
    }
    UF(int n)
    {
        this->cnt = n;
        this->parent.resize(n);
        this->size.resize(n);
        for (int idx = 0; idx < n; idx++)
        {
            this->parent[idx] = idx;
            this->size[idx] = 1;
        }
    }
    ~UF() {}
};
class Solution
{
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        UF uf(edges.size());
        for (auto edge : edges)
        {
            if (uf.isConnect(edge[0] - 1, edge[1] - 1))
                return edge;
            else
                uf.unionRelation(edge[0] - 1, edge[1] - 1);
        }
        return vector<int>{};
    }
};
// @lc code=end
