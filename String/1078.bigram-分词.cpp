/*
 * @lc app=leetcode.cn id=1078 lang=cpp
 *
 * [1078] Bigram 分词
 *
 * https://leetcode-cn.com/problems/occurrences-after-bigram/description/
 *
 * algorithms
 * Easy (61.95%)
 * Likes:    34
 * Dislikes: 0
 * Total Accepted:    15.6K
 * Total Submissions: 24.4K
 * Testcase Example:  '"alice is a good girl she is a good student"\n"a"\n"good"'
 *
 * 给出第一个词 first 和第二个词 second，考虑在某些文本 text 中可能以 "first second third" 形式出现的情况，其中
 * second 紧随 first 出现，third 紧随 second 出现。
 *
 * 对于每种这样的情况，将第三个词 "third" 添加到答案中，并返回答案。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：text = "alice is a good girl she is a good student", first = "a", second
 * = "good"
 * 输出：["girl","student"]
 *
 *
 * 示例 2：
 *
 *
 * 输入：text = "we will we will rock you", first = "we", second = "will"
 * 输出：["we","rock"]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= text.length <= 1000
 * text 由小写英文字母和空格组成
 * text 中的所有单词之间都由 单个空格字符 分隔
 * 1 <= first.length, second.length <= 10
 * first 和 second 由小写英文字母组成
 *
 *
 */

// @lc code=start
#include <vector>
#include <string>
#include <sstream>
using namespace std;
class Solution
{
public:
    vector<string> findOcurrences(string text, string first, string second)
    {
        vector<string> words;
        stringstream ss(text);
        string w;
        while (ss >> w)
            words.push_back(w);
        int length = words.size();
        vector<string> res;
        for (int idx = 2; idx < length; ++idx)
        {
            if (words[idx - 2] == first && words[idx - 1] == second)
                res.push_back(words[idx]);
        }
        return res;
    }
};
// @lc code=end
