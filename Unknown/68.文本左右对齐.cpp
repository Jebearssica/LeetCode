/*
 * @lc app=leetcode.cn id=68 lang=cpp
 *
 * [68] 文本左右对齐
 *
 * https://leetcode-cn.com/problems/text-justification/description/
 *
 * algorithms
 * Hard (46.95%)
 * Likes:    171
 * Dislikes: 0
 * Total Accepted:    21.8K
 * Total Submissions: 44.8K
 * Testcase Example:  '["This", "is", "an", "example", "of", "text", "justification."]\n16'
 *
 * 给定一个单词数组和一个长度 maxWidth，重新排版单词，使其成为每行恰好有 maxWidth 个字符，且左右两端对齐的文本。
 * 
 * 你应该使用“贪心算法”来放置给定的单词；也就是说，尽可能多地往每行中放置单词。必要时可用空格 ' ' 填充，使得每行恰好有 maxWidth 个字符。
 * 
 * 要求尽可能均匀分配单词间的空格数量。如果某一行单词间的空格不能均匀分配，则左侧放置的空格数要多于右侧的空格数。
 * 
 * 文本的最后一行应为左对齐，且单词之间不插入额外的空格。
 * 
 * 说明:
 * 
 * 
 * 单词是指由非空格字符组成的字符序列。
 * 每个单词的长度大于 0，小于等于 maxWidth。
 * 输入单词数组 words 至少包含一个单词。
 * 
 * 
 * 示例:
 * 
 * 输入:
 * words = ["This", "is", "an", "example", "of", "text", "justification."]
 * maxWidth = 16
 * 输出:
 * [
 * "This    is    an",
 * "example  of text",
 * "justification.  "
 * ]
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * words = ["What","must","be","acknowledgment","shall","be"]
 * maxWidth = 16
 * 输出:
 * [
 * "What   must   be",
 * "acknowledgment  ",
 * "shall be        "
 * ]
 * 解释: 注意最后一行的格式应为 "shall be    " 而不是 "shall     be",
 * 因为最后一行应为左对齐，而不是左右两端对齐。       
 * ⁠    第二行同样为左对齐，这是因为这行只包含一个单词。
 * 
 * 
 * 示例 3:
 * 
 * 输入:
 * words =
 * ["Science","is","what","we","understand","well","enough","to","explain",
 * "to","a","computer.","Art","is","everything","else","we","do"]
 * maxWidth = 20
 * 输出:
 * [
 * "Science  is  what we",
 * ⁠ "understand      well",
 * "enough to explain to",
 * "a  computer.  Art is",
 * "everything  else  we",
 * "do                  "
 * ]
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    vector<string> results;
    void pushFullJustify(vector<string> &words, int left, int right, int spaceLength)
    {
        string s;
        float gap = right - left;
        int remainSpace = spaceLength + gap;
        for (int i = left; i < right; i++)
        {
            int blank = ceil(remainSpace / gap);
            s += (words[i] + string(blank, ' '));
            remainSpace -= blank;
            gap--;
        }
        s += words[right];
        results.push_back(s);
    }
    void pushLeftJustify(vector<string> &words, int left, int right, int spaceLength)
    {
        string s;
        for (int i = left; i < right; i++)
        {
            s += (words[i] + " ");
        }
        s += (words[right] + string(spaceLength, ' '));
        results.push_back(s);
    }
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        int tempLength = 0, counter = 0, left = 0, right = 0;

        while (right <= words.size())
        {
            //the first word adds straightly in temp
            if (tempLength == 0)
            {
                tempLength += words[right].size();
                right++;
                counter++;
                continue;
            }
            else
            {
                if (right == words.size())
                {
                    pushLeftJustify(words, left, right - 1, maxWidth - tempLength);
                    break;
                }
                //at least one space between each words(beginning with 2nd word)
                if (tempLength + words[right].size() + 1 <= maxWidth)
                {
                    tempLength += (words[right].size() + 1);
                    right++;
                    counter++;
                }
                //push result
                else
                {
                    //one word or the last line
                    if (counter == 1)
                    {
                        pushLeftJustify(words, left, right - 1, maxWidth - tempLength);
                    }
                    else
                    {
                        pushFullJustify(words, left, right - 1, maxWidth - tempLength);
                    }
                    left = right;
                    tempLength = 0;
                    counter = 0;
                }
            }
        }
        return results;
    }
};
// @lc code=end
