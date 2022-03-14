/*
 * @lc app=leetcode.cn id=187 lang=cpp
 *
 * [187] 重复的DNA序列
 *
 * https://leetcode-cn.com/problems/repeated-dna-sequences/description/
 *
 * algorithms
 * Medium (48.40%)
 * Likes:    235
 * Dislikes: 0
 * Total Accepted:    52.7K
 * Total Submissions: 105.2K
 * Testcase Example:  '"AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"'
 *
 * 所有 DNA 都由一系列缩写为 'A'，'C'，'G' 和 'T' 的核苷酸组成，例如："ACGAATTCCG"。在研究 DNA 时，识别 DNA
 * 中的重复序列有时会对研究非常有帮助。
 *
 * 编写一个函数来找出所有目标子串，目标子串的长度为 10，且在 DNA 字符串 s 中出现次数超过一次。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
 * 输出：["AAAAACCCCC","CCCCCAAAAA"]
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "AAAAAAAAAAAAA"
 * 输出：["AAAAAAAAAA"]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0
 * s[i] 为 'A'、'C'、'G' 或 'T'
 *
 *
 */

// @lc code=start
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        vector<string> res;
        int mask = (1 << 10 * 2) - 1, opt = 0;
        unordered_map<int, int> map;
        for (int idx = 0; idx < 9; ++idx)
        {
            opt = (opt << 2) & mask;
            switch (s[idx])
            {
            case 'A':
                opt = opt | 0;
                break;
            case 'T':
                opt = opt | 1;
                break;
            case 'C':
                opt = opt | 2;
                break;
            case 'G':
                opt = opt | 3;
                break;
            }
        }
        for (int idx = 9; idx < s.size(); ++idx)
        {
            opt = (opt << 2) & mask;
            switch (s[idx])
            {
            case 'A':
                opt = opt | 0;
                break;
            case 'T':
                opt = opt | 1;
                break;
            case 'C':
                opt = opt | 2;
                break;
            case 'G':
                opt = opt | 3;
                break;
            }
            if (map[opt] == 1)
                res.push_back(s.substr(idx - 9, 10));
            ++map[opt];
        }
        return res;
    }
};
// @lc code=end
