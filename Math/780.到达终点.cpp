/*
 * @lc app=leetcode.cn id=780 lang=cpp
 *
 * [780] 到达终点
 *
 * https://leetcode-cn.com/problems/reaching-points/description/
 *
 * algorithms
 * Hard (29.61%)
 * Likes:    246
 * Dislikes: 0
 * Total Accepted:    23.3K
 * Total Submissions: 61K
 * Testcase Example:  '1\n1\n3\n5'
 *
 * 给定四个整数 sx , sy ，tx 和 ty，如果通过一系列的转换可以从起点 (sx, sy) 到达终点 (tx, ty)，则返回 true，否则返回
 * false。
 *
 * 从点 (x, y) 可以转换到 (x, x+y)  或者 (x+y, y)。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: sx = 1, sy = 1, tx = 3, ty = 5
 * 输出: true
 * 解释:
 * 可以通过以下一系列转换从起点转换到终点：
 * (1, 1) -> (1, 2)
 * (1, 2) -> (3, 2)
 * (3, 2) -> (3, 5)
 *
 *
 * 示例 2:
 *
 *
 * 输入: sx = 1, sy = 1, tx = 2, ty = 2
 * 输出: false
 *
 *
 * 示例 3:
 *
 *
 * 输入: sx = 1, sy = 1, tx = 1, ty = 1
 * 输出: true
 *
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= sx, sy, tx, ty <= 10^9
 *
 *
 */

// @lc code=start
class Solution
{
public:
    bool reachingPoints(int sx, int sy, int tx, int ty)
    {
        while (tx > sx && ty > sy)
            if (tx < ty)
                ty %= tx;
            else
                tx %= ty;
        if (tx < sx || ty < sy)
            return false;
        return tx == sx ? (ty - sy) % tx == 0 : (tx - sx) % ty == 0;
    }
};
// @lc code=end
