/*
 * @lc app=leetcode.cn id=990 lang=cpp
 *
 * [990] 等式方程的可满足性
 *
 * https://leetcode-cn.com/problems/satisfiability-of-equality-equations/description/
 *
 * algorithms
 * Medium (50.79%)
 * Likes:    213
 * Dislikes: 0
 * Total Accepted:    36.1K
 * Total Submissions: 70.9K
 * Testcase Example:  '["a==b","b!=a"]'
 *
 * 给定一个由表示变量之间关系的字符串方程组成的数组，每个字符串方程 equations[i] 的长度为 4，并采用两种不同的形式之一："a==b" 或
 * "a!=b"。在这里，a 和 b 是小写字母（不一定不同），表示单字母变量名。
 *
 * 只有当可以将整数分配给变量名，以便满足所有给定的方程时才返回 true，否则返回 false。 
 *
 *
 *
 *
 *
 *
 * 示例 1：
 *
 * 输入：["a==b","b!=a"]
 * 输出：false
 * 解释：如果我们指定，a = 1 且 b = 1，那么可以满足第一个方程，但无法满足第二个方程。没有办法分配变量同时满足这两个方程。
 *
 *
 * 示例 2：
 *
 * 输入：["b==a","a==b"]
 * 输出：true
 * 解释：我们可以指定 a = 1 且 b = 1 以满足满足这两个方程。
 *
 *
 * 示例 3：
 *
 * 输入：["a==b","b==c","a==c"]
 * 输出：true
 *
 *
 * 示例 4：
 *
 * 输入：["a==b","b!=c","c==a"]
 * 输出：false
 *
 *
 * 示例 5：
 *
 * 输入：["c==c","b==d","x!=z"]
 * 输出：true
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= equations.length <= 500
 * equations[i].length == 4
 * equations[i][0] 和 equations[i][3] 是小写字母
 * equations[i][1] 要么是 '='，要么是 '!'
 * equations[i][2] 是 '='
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
        this->cnt--;
    }
    bool isConnnect(int p, int q)
    {
        int rootP = find(p);
        int rootQ = find(q);
        return rootP == rootQ;
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
    int count()
    {
        return this->cnt;
    }
    UF(int n)
    {
        this->cnt = n;
        this->parent.resize(n);
        this->size.resize(n);
        // construct UF
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
    bool equationsPossible(vector<string> &equations)
    {
        UF uf(26);
        for (string eq : equations)
            if (eq[1] == '=')
                uf.unionRelation(eq[0] - 'a', eq[3] - 'a');
        for (string eq : equations)
            if (eq[1] == '!')
                if (uf.isConnnect(eq[0] - 'a', eq[3] - 'a'))
                    return false;
        return true;
    }
};
// @lc code=end
