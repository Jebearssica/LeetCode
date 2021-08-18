/*
 * @lc app=leetcode.cn id=797 lang=cpp
 *
 * [797] 所有可能的路径
 *
 * https://leetcode-cn.com/problems/all-paths-from-source-to-target/description/
 *
 * algorithms
 * Medium (73.85%)
 * Likes:    143
 * Dislikes: 0
 * Total Accepted:    16.3K
 * Total Submissions: 22.1K
 * Testcase Example:  '[[1,2],[3],[3],[]]'
 *
 * 给一个有 n 个结点的有向无环图，找到所有从 0 到 n-1 的路径并输出（不要求按顺序）
 * 
 * 二维数组的第 i 个数组中的单元都表示有向图中 i 号结点所能到达的下一些结点（译者注：有向图是有方向的，即规定了 a→b 你就不能从 b→a
 * ）空就是没有下一个结点了。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：graph = [[1,2],[3],[3],[]]
 * 输出：[[0,1,3],[0,2,3]]
 * 解释：有两条路径 0 -> 1 -> 3 和 0 -> 2 -> 3
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 
 * 输入：graph = [[4,3,1],[3,2,4],[3],[4],[]]
 * 输出：[[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：graph = [[1],[]]
 * 输出：[[0,1]]
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：graph = [[1,2,3],[2],[3],[]]
 * 输出：[[0,1,2,3],[0,2,3],[0,3]]
 * 
 * 
 * 示例 5：
 * 
 * 
 * 输入：graph = [[1,3],[2],[3],[]]
 * 输出：[[0,1,2,3],[0,3]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == graph.length
 * 2 
 * 0 
 * graph[i][j] != i 
 * 保证输入为有向无环图 (GAD)
 * 
 * 
 */

// @lc code=start
#include <vector>
class Solution
{
public:
    std::vector<std::vector<int>> resultList;
    void traverse(std::vector<std::vector<int>> &graph, int start, int end, std::vector<int> currentPath)
    {
        currentPath.push_back(start);
        if (start == end)
        {
            resultList.push_back(currentPath);
            currentPath.pop_back();
            return;
        }
        else
            for (int nextVertex : graph[start])
            {
                traverse(graph, nextVertex, end, currentPath);
            }
        currentPath.pop_back();
    }
    std::vector<std::vector<int>> allPathsSourceTarget(std::vector<std::vector<int>> &graph)
    {
        std::vector<int> currentPath;
        int end = graph.size() - 1;
        traverse(graph, 0, end, currentPath);
        return resultList;
    }
};
// @lc code=end
