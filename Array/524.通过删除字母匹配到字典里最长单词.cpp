/*
 * @lc app=leetcode.cn id=524 lang=cpp
 *
 * [524] 通过删除字母匹配到字典里最长单词
 *
 * https://leetcode-cn.com/problems/longest-word-in-dictionary-through-deleting/description/
 *
 * algorithms
 * Medium (47.26%)
 * Likes:    181
 * Dislikes: 0
 * Total Accepted:    43.8K
 * Total Submissions: 91.4K
 * Testcase Example:  '"abpcplea"\n["ale","apple","monkey","plea"]'
 *
 * 给你一个字符串 s 和一个字符串数组 dictionary 作为字典，找出并返回字典中最长的字符串，该字符串可以通过删除 s 中的某些字符得到。
 * 
 * 如果答案不止一个，返回长度最长且字典序最小的字符串。如果答案不存在，则返回空字符串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
 * 输出："apple"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "abpcplea", dictionary = ["a","b","c"]
 * 输出："a"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 1 
 * 1 
 * s 和 dictionary[i] 仅由小写英文字母组成
 * 
 * 
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    bool isMatch(string s, string word)
    {
        int idx = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (idx == word.size())
                return true;
            if (s[i] == word[idx])
                idx++;
        }
        return idx == word.size();
    }
    string findLongestWord(string s, vector<string> &dictionary)
    {
        int maxLength = 0;
        string result = "";
        for (auto &word : dictionary)
        {
            if (isMatch(s, word))
            {
                auto tempLength = word.size();
                if (tempLength > maxLength || (tempLength == maxLength && result > word))
                {
                    maxLength = tempLength;
                    result = word;
                }
            }
        }
        return result;
    }
};
// @lc code=end
