/*
 * @lc app=leetcode.cn id=166 lang=cpp
 *
 * [166] 分数到小数
 *
 * https://leetcode-cn.com/problems/fraction-to-recurring-decimal/description/
 *
 * algorithms
 * Medium (29.88%)
 * Likes:    270
 * Dislikes: 0
 * Total Accepted:    28.1K
 * Total Submissions: 92.8K
 * Testcase Example:  '1\n2'
 *
 * 给定两个整数，分别表示分数的分子 numerator 和分母 denominator，以 字符串形式返回小数 。
 * 
 * 如果小数部分为循环小数，则将循环的部分括在括号内。
 * 
 * 如果存在多个答案，只需返回 任意一个 。
 * 
 * 对于所有给定的输入，保证 答案字符串的长度小于 10^4 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：numerator = 1, denominator = 2
 * 输出："0.5"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：numerator = 2, denominator = 1
 * 输出："2"
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：numerator = 2, denominator = 3
 * 输出："0.(6)"
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：numerator = 4, denominator = 333
 * 输出："0.(012)"
 * 
 * 
 * 示例 5：
 * 
 * 
 * 输入：numerator = 1, denominator = 5
 * 输出："0.2"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * -2^31 
 * denominator != 0
 * 
 * 
 */

// @lc code=start
#include <string>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    string fractionToDecimal(int numerator, int denominator)
    {
        long long numer = (long long)numerator, denom = (long long)denominator;
        if (numer % denom == 0)
            return to_string(numer / denom);
        else
        {
            string res;

            //jugde sign
            if (numer * denom < 0)
                res.push_back('-');

            //following Vertical Division from high to low
            //use / to straightly calculate the integer part
            numer = abs(numer);
            denom = abs(denom);
            res += to_string(numer / denom) + '.';

            //calculate decimal part
            numer = numer % denom;
            //hash map to store the loop's positions
            unordered_map<long long, int> map;
            while (numer != 0)
            {
                map[numer] = res.size();
                numer *= 10;
                res += to_string(numer / denom);
                numer = numer % denom;
                //find the loop
                if (map.find(numer) != map.end())
                    return res.substr(0, map[numer]) + '(' + res.substr(map[numer]) + ')';
            }
            return res;
        }
    }
};
// @lc code=end
