/*
 * @lc app=leetcode.cn id=886 lang=cpp
 *
 * [886] 可能的二分法
 *
 * https://leetcode-cn.com/problems/possible-bipartition/description/
 *
 * algorithms
 * Medium (43.92%)
 * Likes:    149
 * Dislikes: 0
 * Total Accepted:    10.8K
 * Total Submissions: 24.2K
 * Testcase Example:  '4\n[[1,2],[1,3],[2,4]]'
 *
 * 给定一组 N 人（编号为 1, 2, ..., N）， 我们想把每个人分进任意大小的两组。
 *
 * 每个人都可能不喜欢其他人，那么他们不应该属于同一组。
 *
 * 形式上，如果 dislikes[i] = [a, b]，表示不允许将编号为 a 和 b 的人归入同一组。
 *
 * 当可以用这种方法将所有人分进两组时，返回 true；否则返回 false。
 *
 *
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：N = 4, dislikes = [[1,2],[1,3],[2,4]]
 * 输出：true
 * 解释：group1 [1,4], group2 [2,3]
 *
 *
 * 示例 2：
 *
 *
 * 输入：N = 3, dislikes = [[1,2],[1,3],[2,3]]
 * 输出：false
 *
 *
 * 示例 3：
 *
 *
 * 输入：N = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
 * 输出：false
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * 0
 * dislikes[i].length == 2
 * 1
 * dislikes[i][0] < dislikes[i][1]
 * 对于 dislikes[i] == dislikes[j] 不存在 i != j
 *
 *
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
private:
    bool isB = true;
    vector<bool> color;
    vector<bool> isVisited;

public:
    void traverse(vector<vector<int>> &graph, int idx)
    {
        if (!isB)
            return;
        isVisited[idx] = true;
        for (int neighbor : graph[idx])
        {
            if (!isVisited[neighbor])
            {
                color[neighbor] = !color[idx];
                traverse(graph, neighbor);
            }
            else
            {
                if (color[neighbor] == color[idx])
                    isB = false;
            }
        }
    }
    bool possibleBipartition(int n, vector<vector<int>> &dislikes)
    {
        color.resize(n, false);
        isVisited.resize(n, false);
        vector<vector<int>> graph(n);
        // build graph
        for (auto line : dislikes)
        {
            graph[line[0] - 1].push_back(line[1] - 1);
            graph[line[1] - 1].push_back(line[0] - 1);
        }
        // traverse
        for (int idx = 0; idx < n; idx++)
        {
            if (!isVisited[idx])
                traverse(graph, idx);
        }
        return isB;
    }
};
// @lc code=end
