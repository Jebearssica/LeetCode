/*
 * @lc app=leetcode.cn id=318 lang=cpp
 *
 * [318] 最大单词长度乘积
 *
 * https://leetcode-cn.com/problems/maximum-product-of-word-lengths/description/
 *
 * algorithms
 * Medium (68.61%)
 * Likes:    277
 * Dislikes: 0
 * Total Accepted:    43.1K
 * Total Submissions: 58.8K
 * Testcase Example:  '["abcw","baz","foo","bar","xtfn","abcdef"]'
 *
 * 给定一个字符串数组 words，找到 length(word[i]) * length(word[j])
 * 的最大值，并且这两个单词不含有公共字母。你可以认为每个单词只包含小写字母。如果不存在这样的两个单词，返回 0。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: ["abcw","baz","foo","bar","xtfn","abcdef"]
 * 输出: 16 
 * 解释: 这两个单词为 "abcw", "xtfn"。
 * 
 * 示例 2:
 * 
 * 
 * 输入: ["a","ab","abc","d","cd","bcd","abcd"]
 * 输出: 4 
 * 解释: 这两个单词为 "ab", "cd"。
 * 
 * 示例 3:
 * 
 * 
 * 输入: ["a","aa","aaa","aaaa"]
 * 输出: 0 
 * 解释: 不存在这样的两个单词。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 
 * 1 
 * words[i] 仅包含小写字母
 * 
 * 
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    int maxProduct(vector<string> &words)
    {
        vector<int> charCache(words.size());
        //load char cache
        for (int i = 0; i < words.size(); i++)
        {
            int word = 0;
            for (char ch : words[i])
                word |= (1 << (ch - 'a'));
            charCache[i] = word;
        }
        int res = 0;
        for (int i = 0; i < words.size(); i++)
        {
            for (int j = i + 1; j < words.size(); j++)
            {
                if ((charCache[i] & charCache[j]) == 0)
                    res = max(res, (int)(words[i].size() * words[j].size()));
            }
        }
        return res;
    }
};
// @lc code=end
