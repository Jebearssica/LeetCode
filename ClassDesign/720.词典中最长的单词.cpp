/*
 * @lc app=leetcode.cn id=720 lang=cpp
 *
 * [720] 词典中最长的单词
 *
 * https://leetcode-cn.com/problems/longest-word-in-dictionary/description/
 *
 * algorithms
 * Easy (48.30%)
 * Likes:    246
 * Dislikes: 0
 * Total Accepted:    40K
 * Total Submissions: 78.2K
 * Testcase Example:  '["w","wo","wor","worl","world"]'
 *
 * 给出一个字符串数组 words 组成的一本英语词典。返回 words 中最长的一个单词，该单词是由 words 词典中其他单词逐步添加一个字母组成。
 *
 * 若其中有多个可行的答案，则返回答案中字典序最小的单词。若无答案，则返回空字符串。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：words = ["w","wo","wor","worl", "world"]
 * 输出："world"
 * 解释： 单词"world"可由"w", "wo", "wor", 和 "worl"逐步添加一个字母组成。
 *
 *
 * 示例 2：
 *
 *
 * 输入：words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
 * 输出："apple"
 * 解释："apply" 和 "apple" 都能由词典中的单词组成。但是 "apple" 的字典序小于 "apply"
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= words.length <= 1000
 * 1 <= words[i].length <= 30
 * 所有输入的字符串 words[i] 都只包含小写字母。
 *
 *
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;
class Trie
{
private:
    int maxRange;
    char startOffset;
    struct TrieNode
    {
        int val = 0;
        vector<TrieNode *> children;
        TrieNode()
        {
            val = 0;
            this->children.resize(26, nullptr);
        }
        TrieNode(int v)
        {
            val = v;
            this->children.resize(26, nullptr);
        }
    };
    TrieNode *root;

public:
    void insert(string word)
    {
        TrieNode *temp = this->root;
        for (char ch : word)
        {
            if (temp->children[ch - this->startOffset] == nullptr)
                temp->children[ch - this->startOffset] = new TrieNode();
            temp = temp->children[ch - this->startOffset];
        }
        ++temp->val;
    }
    bool isValid(string word)
    {
        TrieNode *temp = this->root;
        for (char ch : word)
        {
            temp = temp->children[ch - this->startOffset];
            if (temp == nullptr || temp->val == 0)
                return false;
        }
        return true;
    }
    Trie()
    {
        this->maxRange = 26;
        this->startOffset = 'a';
        this->root = new TrieNode(1);
    }
    ~Trie() {}
};
class Solution
{
public:
    string longestWord(vector<string> &words)
    {
        Trie trie;
        for (auto &w : words)
            trie.insert(w);
        string res = "";
        for (auto &w : words)
        {
            if (res.size() > w.size() || (res.size() == w.size() && res < w))
                continue;
            if (trie.isValid(w))
                res = w;
        }
        return res;
    }
};
// @lc code=end
