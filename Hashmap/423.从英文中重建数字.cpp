/*
 * @lc app=leetcode.cn id=423 lang=cpp
 *
 * [423] 从英文中重建数字
 *
 * https://leetcode-cn.com/problems/reconstruct-original-digits-from-english/description/
 *
 * algorithms
 * Medium (56.87%)
 * Likes:    93
 * Dislikes: 0
 * Total Accepted:    12.8K
 * Total Submissions: 21.6K
 * Testcase Example:  '"owoztneoer"'
 *
 * 给你一个字符串 s ，其中包含字母顺序打乱的用英文单词表示的若干数字（0-9）。按 升序 返回原始的数字。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "owoztneoer"
 * 输出："012"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "fviefuro"
 * 输出："45"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 10^5
 * s[i] 为 ["e","g","f","i","h","o","n","s","r","u","t","w","v","x","z"]
 * 这些字符之一
 * s 保证是一个符合题目要求的字符串
 * 
 * 
 */

// @lc code=start
#include <unordered_map>
class Solution
{
public:
    string originalDigits(string s)
    {
        std::unordered_map<char, int> charFreq;
        std::string res;
        for (char ch : s)
            charFreq[ch]++;
        std::vector<int> digitCnt(10, 0);
        /*
        * check the first level letter(Can be out of order):
        * zero 0: z
        * two 2: w
        * four 4: u
        * six 6: x
        * eight 8: g
        */
        digitCnt[0] = charFreq['z'];
        digitCnt[2] = charFreq['w'];
        digitCnt[4] = charFreq['u'];
        digitCnt[6] = charFreq['x'];
        digitCnt[8] = charFreq['g'];

        /*
        * check the second level letter:
        * three 3: -eight: h
        * five 5: -four: f
        * seven 7: -six: s
        */
        digitCnt[3] = charFreq['h'] - digitCnt[8];
        digitCnt[5] = charFreq['f'] - digitCnt[4];
        digitCnt[7] = charFreq['s'] - digitCnt[6];

        /*
        * check the third level letter:
        * one 1: --zero -two -four: o
        * nine 9: -five -six -eight: i
        */
        digitCnt[1] = charFreq['o'] - digitCnt[0] - digitCnt[2] - digitCnt[4];
        digitCnt[9] = charFreq['i'] - digitCnt[5] - digitCnt[6] - digitCnt[8];
        for (int digit = 0; digit < 10; digit++)
        {
            for (int idx = 0; idx < digitCnt[digit]; idx++)
            {
                res += char(digit + '0');
            }
        }
        return res;
    }
};
// @lc code=end
