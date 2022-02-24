/*
 * @lc app=leetcode.cn id=323 lang=cpp
 *
 * [323] 无向图中连通分量的数目
 *
 * https://leetcode-cn.com/problems/number-of-connected-components-in-an-undirected-graph/description/
 *
 * algorithms
 * Medium (63.69%)
 * Likes:    127
 * Dislikes: 0
 * Total Accepted:    13.5K
 * Total Submissions: 21.3K
 * Testcase Example:  '5\n[[0,1],[1,2],[3,4]]'
 *
 * 你有一个包含 n 个节点的图。给定一个整数 n 和一个数组 edges ，其中 edges[i] = [ai, bi] 表示图中 ai 和 bi
 * 之间有一条边。
 *
 * 返回 图中已连接分量的数目 。
 *
 *
 *
 * 示例 1:
 *
 *
 *
 *
 * 输入: n = 5, edges = [[0, 1], [1, 2], [3, 4]]
 * 输出: 2
 *
 *
 * 示例 2:
 *
 *
 *
 *
 * 输入: n = 5, edges = [[0,1], [1,2], [2,3], [3,4]]
 * 输出:  1
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 2000
 * 1 <= edges.length <= 5000
 * edges[i].length == 2
 * 0 <= ai <= bi < n
 * ai != bi
 * edges 中不会出现重复的边
 *
 *
 */

// @lc code=start
#include <vector>
using namespace std;
class UF
{
private:
    int cnt;
    vector<int> parent;
    vector<int> size;

public:
    int count()
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
    void merge(int x, int y)
    {
        int rootX = find(x), rootY = find(y);
        if (rootX == rootY)
            return;
        if (this->size[rootX] > this->size[rootY])
            swap(rootX, rootY);
        this->parent[rootX] = rootY;
        this->size[rootY] += this->size[rootX];
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
    int countComponents(int n, vector<vector<int>> &edges)
    {
        UF uf(n);
        for (auto &info : edges)
            uf.merge(info[0], info[1]);
        return uf.count();
    }
};
// @lc code=end
