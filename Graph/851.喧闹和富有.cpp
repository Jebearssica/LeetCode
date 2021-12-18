/*
 * @lc app=leetcode.cn id=851 lang=cpp
 *
 * [851] 喧闹和富有
 *
 * https://leetcode-cn.com/problems/loud-and-rich/description/
 *
 * algorithms
 * Medium (49.56%)
 * Likes:    179
 * Dislikes: 0
 * Total Accepted:    23.5K
 * Total Submissions: 37.4K
 * Testcase Example:  '[[1,0],[2,1],[3,1],[3,7],[4,3],[5,3],[6,3]]\n[3,2,5,4,6,1,7,0]'
 *
 * 有一组 n 个人作为实验对象，从 0 到 n - 1
 * 编号，其中每个人都有不同数目的钱，以及不同程度的安静值（quietness）。为了方便起见，我们将编号为 x 的人简称为 "person x "。
 *
 * 给你一个数组 richer ，其中 richer[i] = [ai, bi] 表示 person ai 比 person bi
 * 更有钱。另给你一个整数数组 quiet ，其中 quiet[i] 是 person i 的安静值。richer 中所给出的数据 逻辑自洽（也就是说，在
 * person x 比 person y 更有钱的同时，不会出现 person y 比 person x 更有钱的情况 ）。
 *
 * 现在，返回一个整数数组 answer 作为答案，其中 answer[x] = y 的前提是，在所有拥有的钱肯定不少于 person x
 * 的人中，person y 是最安静的人（也就是安静值 quiet[y] 最小的人）。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：richer = [[1,0],[2,1],[3,1],[3,7],[4,3],[5,3],[6,3]], quiet =
 * [3,2,5,4,6,1,7,0]
 * 输出：[5,5,2,5,4,5,6,7]
 * 解释：
 * answer[0] = 5，
 * person 5 比 person 3 有更多的钱，person 3 比 person 1 有更多的钱，person 1 比 person 0
 * 有更多的钱。
 * 唯一较为安静（有较低的安静值 quiet[x]）的人是 person 7，
 * 但是目前还不清楚他是否比 person 0 更有钱。
 * answer[7] = 7，
 * 在所有拥有的钱肯定不少于 person 7 的人中（这可能包括 person 3，4，5，6 以及 7），
 * 最安静（有较低安静值 quiet[x]）的人是 person 7。
 * 其他的答案也可以用类似的推理来解释。
 *
 *
 * 示例 2：
 *
 *
 * 输入：richer = [], quiet = [0]
 * 输出：[0]
 *
 *
 *
 * 提示：
 *
 *
 * n == quiet.length
 * 1 <= n <= 500
 * 0 <= quiet[i] < n
 * quiet 的所有值 互不相同
 * 0 <= richer.length <= n * (n - 1) / 2
 * 0 <= ai, bi < n
 * ai != bi
 * richer 中的所有数对 互不相同
 * 对 richer 的观察在逻辑上是一致的
 *
 *
 */

// @lc code=start
#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    vector<int> loudAndRich(vector<vector<int>> &richer, vector<int> &quiet)
    {
        // construct the graph
        vector<vector<int>> graph(quiet.size());
        vector<int> inDeg(quiet.size(), 0);
        for (auto relation : richer)
        {
            graph[relation[1]].push_back(relation[0]);
            inDeg[relation[0]]++;
        }
        queue<int> q;
        vector<int> res(quiet.size());
        for (int i = 0; i < quiet.size(); i++)
        {
            if (inDeg[i] == 0)
                q.push(i);
            res[i] = i;
        }
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();

            for (auto child : graph[cur])
            {
                if (quiet[res[cur]] > quiet[res[child]])
                    res[cur] = res[child];
                if (--inDeg[child] == 0)
                    q.push(child);
            }
        }
        return res;
    }
};
// @lc code=end
