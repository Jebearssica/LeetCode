/*
 * @lc app=leetcode.cn id=405 lang=cpp
 *
 * [405] 数字转换为十六进制数
 *
 * https://leetcode-cn.com/problems/convert-a-number-to-hexadecimal/description/
 *
 * algorithms
 * Easy (52.25%)
 * Likes:    174
 * Dislikes: 0
 * Total Accepted:    33K
 * Total Submissions: 61K
 * Testcase Example:  '26'
 *
 * 给定一个整数，编写一个算法将这个数转换为十六进制数。对于负整数，我们通常使用 补码运算 方法。
 * 
 * 注意:
 * 
 * 
 * 十六进制中所有字母(a-f)都必须是小写。
 * 
 * 十六进制字符串中不能包含多余的前导零。如果要转化的数为0，那么以单个字符'0'来表示；对于其他情况，十六进制字符串中的第一个字符将不会是0字符。 
 * 给定的数确保在32位有符号整数范围内。
 * 不能使用任何由库提供的将数字直接转换或格式化为十六进制的方法。
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入:
 * 26
 * 
 * 输出:
 * "1a"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入:
 * -1
 * 
 * 输出:
 * "ffffffff"
 * 
 * 
 */

// @lc code=start
#include <string>
using namespace std;
class Solution
{
public:
    string toHex(int num)
    {
        if (num == 0)
            return "0";
        else
        {
            string res;
            //16进制最多就8位
            for (int i = 7; i >= 0; i--)
            {
                //取得从低至高第i组(4-bit)数据与1111进行与操作, 从而得到HEX中第i位的val
                int val = (num >> (4 * i)) & 0xf;
                //若num>0 则存在最高位res.size()==0且val==0的情况, 此时直接跳过确保不出现前导零的发生
                if (res.size() > 0 || val > 0)
                {
                    char digit = val < 10 ? (char)(val + '0') : (char)(val + 'a' - 10);
                    res.push_back(digit);
                }
            }
            return res;
        }
    }
};
// @lc code=end
