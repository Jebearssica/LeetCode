/*
 * @lc app=leetcode.cn id=212 lang=cpp
 *
 * [212] 单词搜索 II
 *
 * https://leetcode-cn.com/problems/word-search-ii/description/
 *
 * algorithms
 * Hard (45.57%)
 * Likes:    485
 * Dislikes: 0
 * Total Accepted:    48.6K
 * Total Submissions: 106.6K
 * Testcase Example:  '[["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]]\n["oath","pea","eat","rain"]'
 *
 * 给定一个 m x n 二维字符网格 board 和一个单词（字符串）列表 words，找出所有同时在二维网格和字典中出现的单词。
 * 
 * 单词必须按照字母顺序，通过 相邻的单元格
 * 内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母在一个单词中不允许被重复使用。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：board =
 * [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]],
 * words = ["oath","pea","eat","rain"]
 * 输出：["eat","oath"]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：board = [["a","b"],["c","d"]], words = ["abcb"]
 * 输出：[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == board.length
 * n == board[i].length
 * 1 
 * board[i][j] 是一个小写英文字母
 * 1 
 * 1 
 * words[i] 由小写英文字母组成
 * words 中的所有字符串互不相同
 * 
 * 
 */

// @lc code=start
#include <vector>
using namespace std;

class Trie
{
private:
public:
    vector<Trie *> children;
    bool isEnd;
    Trie *searchPrefix(string prefix)
    {
        Trie *node = this;
        for (char ch : prefix)
        {
            ch -= 'a';
            if (node->children[ch] == nullptr)
                return nullptr;
            node = node->children[ch];
        }
        return node;
    }
    Trie() : children(26), isEnd(false)
    {
    }
    void insert(string word)
    {
        Trie *node = this;
        for (char ch : word)
        {
            ch -= 'a';
            if (node->children[ch] == nullptr)
                node->children[ch] = new Trie();
            node = node->children[ch];
        }
        node->isEnd = true;
    }
    bool search(string word)
    {
        Trie *node = this->searchPrefix(word);
        return node == nullptr && node->isEnd;
    }
    bool startsWith(string prefix)
    {
        return this->searchPrefix(prefix);
    }
};
class Solution
{
public:
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<string> result;
    void backTrace(vector<vector<char>> &board, int row, int col, Trie *root, string current)
    {
        auto ch = board[row][col];
        if (!root->children[(ch - 'a')])
            return;
        root = root->children[(ch - 'a')];
        current.push_back(ch);
        if (root->isEnd)
        {
            result.push_back(current);
            root->isEnd = false;
        }
        board[row][col] = '#';

        for (int i = 0; i < 4; i++)
        {
            int tempRow = row + dir[i][0];
            int tempCol = col + dir[i][1];
            if (tempRow >= 0 && tempRow < board.size() && tempCol >= 0 && tempCol < board[0].size() && board[tempRow][tempCol] != '#')
                backTrace(board, tempRow, tempCol, root, current);
        }

        board[row][col] = ch;
        current.pop_back();
    }
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        //init trie
        Trie *root = new Trie();
        for (auto &word : words)
        {
            root->insert(word);
        }

        string current = "";
        for (int row = 0; row < board.size(); row++)
        {
            for (int col = 0; col < board[0].size(); col++)
            {
                backTrace(board, row, col, root, current);
            }
        }

        return result;
    }
};
// @lc code=end
