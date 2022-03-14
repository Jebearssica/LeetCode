/*
 * @lc app=leetcode.cn id=928 lang=cpp
 *
 * [928] 尽量减少恶意软件的传播 II
 *
 * https://leetcode-cn.com/problems/minimize-malware-spread-ii/description/
 *
 * algorithms
 * Hard (42.26%)
 * Likes:    44
 * Dislikes: 0
 * Total Accepted:    2.4K
 * Total Submissions: 5.7K
 * Testcase Example:  '[[1,1,0],[1,1,0],[0,0,1]]\n[0,1]'
 *
 * (这个问题与 尽量减少恶意软件的传播 是一样的，不同之处用粗体表示。)
 *
 * 在节点网络中，只有当 graph[i][j] = 1 时，每个节点 i 能够直接连接到另一个节点 j。
 *
 * 一些节点 initial
 * 最初被恶意软件感染。只要两个节点直接连接，且其中至少一个节点受到恶意软件的感染，那么两个节点都将被恶意软件感染。这种恶意软件的传播将继续，直到没有更多的节点可以被这种方式感染。
 *
 * 假设 M(initial) 是在恶意软件停止传播之后，整个网络中感染恶意软件的最终节点数。
 *
 * 我们可以从初始列表中删除一个节点，并完全移除该节点以及从该节点到任何其他节点的任何连接。如果移除这一节点将最小化 M(initial)，
 * 则返回该节点。如果有多个节点满足条件，就返回索引最小的节点。
 *
 *
 *
 *
 *
 *
 * 示例 1：
 *
 * 输出：graph = [[1,1,0],[1,1,0],[0,0,1]], initial = [0,1]
 * 输入：0
 *
 *
 * 示例 2：
 *
 * 输入：graph = [[1,1,0],[1,1,1],[0,1,1]], initial = [0,1]
 * 输出：1
 *
 *
 * 示例 3：
 *
 * 输入：graph = [[1,1,0,0],[1,1,1,0],[0,1,1,1],[0,0,1,1]], initial = [0,1]
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
 * graph[i][i] = 1
 * 1 <= initial.length < graph.length
 * 0 <= initial[i] < graph.length
 *
 *
 */

// @lc code=start
#include <vector>
#include <unordered_set>
#include <unordered_map>
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
    int retSize(int x)
    {
        return this->size[find(x)];
    }
    void merge(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY)
            return;
        if (this->size[rootY] > this->size[rootX])
            swap(rootX, rootY);
        this->parent[rootY] = rootX;
        this->size[rootX] += this->size[rootY];
        --this->cnt;
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
        unordered_set<int> initNode;
        for (auto node : initial)
            initNode.insert(node);
        UF uf(graph.size());
        for (int i = 0; i < graph.size(); i++)
            if (!initNode.count(i))
                for (int j = i + 1; j < graph.size(); j++)
                    if (!initNode.count(j) && graph[i][j] == 1)
                        uf.merge(i, j);
        vector<int> infeCnt(graph.size(), 0);
        unordered_map<int, unordered_set<int>> nodeToRoot;
        for (auto node : initial)
        {
            unordered_set<int> infeNode;
            for (int i = 0; i < graph.size(); i++)
                if (!initNode.count(i) && graph[node][i] == 1)
                    infeNode.insert(uf.find(i));
            nodeToRoot[node] = infeNode;
            for (int infeRoot : infeNode)
                ++infeCnt[infeRoot];
        }
        int maxSize = -1, resIdx = -1;
        for (auto [key, val] : nodeToRoot)
        {
            int size = 0;
            for (int c : val)
                if (infeCnt[c] == 1)
                    size += uf.retSize(c);
            if (size > maxSize || (size == maxSize && resIdx > key))
            {
                maxSize = size;
                resIdx = key;
            }
        }
        return resIdx;
    }
};
// @lc code=end
