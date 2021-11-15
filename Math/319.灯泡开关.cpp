/*
 * @lc app=leetcode.cn id=319 lang=cpp
 *
 * [319] 灯泡开关
 *
 * https://leetcode-cn.com/problems/bulb-switcher/description/
 *
 * algorithms
 * Medium (51.93%)
 * Likes:    255
 * Dislikes: 0
 * Total Accepted:    38.2K
 * Total Submissions: 68.3K
 * Testcase Example:  '3'
 *
 * 初始时有 n 个灯泡处于关闭状态。第一轮，你将会打开所有灯泡。接下来的第二轮，你将会每两个灯泡关闭一个。
 * 
 * 第三轮，你每三个灯泡就切换一个灯泡的开关（即，打开变关闭，关闭变打开）。第 i 轮，你每 i 个灯泡就切换一个灯泡的开关。直到第 n
 * 轮，你只需要切换最后一个灯泡的开关。
 * 
 * 找出并返回 n 轮后有多少个亮着的灯泡。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：n = 3
 * 输出：1 
 * 解释：
 * 初始时, 灯泡状态 [关闭, 关闭, 关闭].
 * 第一轮后, 灯泡状态 [开启, 开启, 开启].
 * 第二轮后, 灯泡状态 [开启, 关闭, 开启].
 * 第三轮后, 灯泡状态 [开启, 关闭, 关闭]. 
 * 
 * 你应该返回 1，因为只有一个灯泡还亮着。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 0
 * 输出：0
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：n = 1
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= n <= 10^9
 * 
 * 
 */

// @lc code=start
#include <math.h>
using namespace std;
class Solution
{
public:
    int bulbSwitch(int n)
    {
        return (int)floor(sqrt(n));
    }
};
// @lc code=end
