/*
 * @lc app=leetcode.cn id=924 lang=cpp
 *
 * [924] 尽量减少恶意软件的传播
 *
 * https://leetcode-cn.com/problems/minimize-malware-spread/description/
 *
 * algorithms
 * Hard (35.70%)
 * Likes:    69
 * Dislikes: 0
 * Total Accepted:    7K
 * Total Submissions: 19.6K
 * Testcase Example:  '[[1,1,0],[1,1,0],[0,0,1]]\n[0,1]'
 *
 * 在节点网络中，只有当 graph[i][j] = 1 时，每个节点 i 能够直接连接到另一个节点 j。
 *
 * 一些节点 initial
 * 最初被恶意软件感染。只要两个节点直接连接，且其中至少一个节点受到恶意软件的感染，那么两个节点都将被恶意软件感染。这种恶意软件的传播将继续，直到没有更多的节点可以被这种方式感染。
 *
 * 假设 M(initial) 是在恶意软件停止传播之后，整个网络中感染恶意软件的最终节点数。
 *
 * 如果从初始列表中移除某一节点能够最小化 M(initial)， 返回该节点。如果有多个节点满足条件，就返回索引最小的节点。
 *
 * 请注意，如果某个节点已从受感染节点的列表 initial 中删除，它以后可能仍然因恶意软件传播而受到感染。
 *
 *
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：graph = [[1,1,0],[1,1,0],[0,0,1]], initial = [0,1]
 * 输出：0
 *
 *
 * 示例 2：
 *
 *
 * 输入：graph = [[1,0,0],[0,1,0],[0,0,1]], initial = [0,2]
 * 输出：0
 *
 *
 * 示例 3：
 *
 *
 * 输入：graph = [[1,1,1],[1,1,1],[1,1,1]], initial = [1,2]
 * 输出：1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 < graph.length = graph[0].length <= 300
 * 0 <= graph[i][j] == graph[j][i] <= 1
 * graph[i][i] == 1
 * 1 <= initial.length < graph.length
 * 0 <= initial[i] < graph.length
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
    int retSize(int x)
    {
        int rootX = find(x);
        return this->size[rootX];
    }
    int retCnt()
    {
        return this->cnt;
    }
    int find(int x)
    {
        while (this->parent[x] != x)
        {
            this->parent[x] = this->parent[this->parent[x]];
            x = this->parent[x];
        }
        return x;
    }
    bool isConnect(int x, int y)
    {
        return find(x) == find(y);
    }
    void merge(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY)
            return;
        if (this->size[rootX] > this->size[rootY])
        {
            this->parent[rootY] = rootX;
            this->size[rootX] += this->size[rootY];
        }
        else
        {
            this->parent[rootX] = rootY;
            this->size[rootY] += this->size[rootX];
        }
        --this->cnt;
    }
    UF(int n)
    {
        this->cnt = n;
        this->parent.resize(n);
        this->size.resize(n, 1);
        for (int idx = 0; idx < n; ++idx)
            this->parent[idx] = idx;
    }
    ~UF() {}
};
class Solution
{
public:
    int minMalwareSpread(vector<vector<int>> &graph, vector<int> &initial)
    {
        UF uf(graph.size());
        for (int i = 0; i < graph.size(); i++)
            for (int j = i + 1; j < graph.size(); j++)
                if (graph[i][j] == 1)
                    uf.merge(i, j);
        vector<int> infeCnt(graph.size(), 0);
        for (int node : initial)
            ++infeCnt[uf.find(node)];

        int maxSize = 0, resIdx = graph.size();
        for (int node : initial)
        {
            int root = uf.find(node);
            if (infeCnt[root] != 1)
                continue;
            int curSize = uf.retSize(root);
            if ((maxSize == curSize && resIdx > node) || maxSize < curSize)
            {
                maxSize = curSize;
                resIdx = node;
            }
        }
        if (resIdx == graph.size())
            for (int node : initial)
                if (resIdx > node)
                    resIdx = node;
        return resIdx;
    }
};
// @lc code=end
