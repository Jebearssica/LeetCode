/*
 * @lc app=leetcode.cn id=1185 lang=cpp
 *
 * [1185] 一周中的第几天
 *
 * https://leetcode-cn.com/problems/day-of-the-week/description/
 *
 * algorithms
 * Easy (60.22%)
 * Likes:    74
 * Dislikes: 0
 * Total Accepted:    20.2K
 * Total Submissions: 32.4K
 * Testcase Example:  '31\n8\n2019'
 *
 * 给你一个日期，请你设计一个算法来判断它是对应一周中的哪一天。
 *
 * 输入为三个整数：day、month 和 year，分别表示日、月、年。
 *
 * 您返回的结果必须是这几个值中的一个 {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday",
 * "Friday", "Saturday"}。
 *
 *
 *
 * 示例 1：
 *
 * 输入：day = 31, month = 8, year = 2019
 * 输出："Saturday"
 *
 *
 * 示例 2：
 *
 * 输入：day = 18, month = 7, year = 1999
 * 输出："Sunday"
 *
 *
 * 示例 3：
 *
 * 输入：day = 15, month = 8, year = 1993
 * 输出："Sunday"
 *
 *
 *
 *
 * 提示：
 *
 *
 * 给出的日期一定是在 1971 到 2100 年之间的有效日期。
 *
 *
 */

// @lc code=start
class Solution
{
private:
    static constexpr const char *week[]{"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    static constexpr const int monthDay[] = {
        31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};

public:
    string dayOfTheWeek(int day, int month, int year)
    {
        int deltaD = day;
        // add by year
        deltaD += (year - 1971) * 365;
        // leap year begin with 1968
        deltaD += (year - 1969) / 4;
        // add by month
        for (int idx = 0; idx < month - 1; idx++)
            deltaD += monthDay[idx];
        if ((year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) && month >= 3)
            deltaD++;
        // 1970-12-31 Thusday
        return week[(deltaD + 4) % 7];
    }
};
// @lc code=end
