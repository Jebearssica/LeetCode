/*
    * @lc app=leetcode.cn id=514 lang=cpp
    *
    * [514] 自由之路
    *
    * https://leetcode-cn.com/problems/freedom-trail/description/
    *
    * algorithms
    * Hard (49.96%)
    * Likes:    216
    * Dislikes: 0
    * Total Accepted:    19.8K
    * Total Submissions: 39.8K
    * Testcase Example:  '"godding"\n"gd"'
    *
    * 电子游戏“辐射4”中，任务“通向自由”要求玩家到达名为“Freedom Trail Ring”的金属表盘，并使用表盘拼写特定关键词才能开门。
    * 
    * 给定一个字符串 ring，表示刻在外环上的编码；给定另一个字符串 key，表示需要拼写的关键词。您需要算出能够拼写关键词中所有字符的最少步数。
    * 
    * 最初，ring 的第一个字符与12:00方向对齐。您需要顺时针或逆时针旋转 ring 以使 key 的一个字符在 12:00
    * 方向对齐，然后按下中心按钮，以此逐个拼写完 key 中的所有字符。
    * 
    * 旋转 ring 拼出 key 字符 key[i] 的阶段中：
    * 
    * 
    * 您可以将 ring 顺时针或逆时针旋转一个位置，计为1步。旋转的最终目的是将字符串 ring 的一个字符与 12:00
    * 方向对齐，并且这个字符必须等于字符 key[i] 。
    * 如果字符 key[i] 已经对齐到12:00方向，您需要按下中心按钮进行拼写，这也将算作 1 步。按完之后，您可以开始拼写 key
    * 的下一个字符（下一阶段）, 直至完成所有拼写。
    * 
    * 
    * 示例：
    * 
    * 
    * 
    * 
    * 
    * 
    * 
    * 输入: ring = "godding", key = "gd"
    * 输出: 4
    * 解释:
    * ⁠对于 key 的第一个字符 'g'，已经在正确的位置, 我们只需要1步来拼写这个字符。 
    * ⁠对于 key 的第二个字符 'd'，我们需要逆时针旋转 ring "godding" 2步使它变成 "ddinggo"。
    * ⁠当然, 我们还需要1步进行拼写。
    * ⁠因此最终的输出是 4。
    * 
    * 
    * 提示：
    * 
    * 
    * ring 和 key 的字符串长度取值范围均为 1 至 100；
    * 两个字符串中都只有小写字符，并且均可能存在重复字符；
    * 字符串 key 一定可以由字符串 ring 旋转拼出。
    * 
    * 
    */

// @lc code=start
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int findRotateSteps(string ring, string key)
    {
        unordered_map<char, vector<int>> charToIndex;
        int ringLength = ring.size(), keyLength = key.size();
        vector<vector<int>> dp(ringLength, vector<int>(keyLength, INT_MAX));
        //init: charToIndex
        for (int i = 0; i < ringLength; i++)
            charToIndex[ring[i]].push_back(i);
        //init: dp
        for (auto &idx : charToIndex[key[keyLength - 1]])
            dp[idx][keyLength - 1] = 1;
        for (int j = keyLength - 2; j >= 0; j--)
        {
            for (auto &curPos : charToIndex[key[j]])
            {
                for (auto &nextPos : charToIndex[key[j + 1]])
                {
                    int moveSteps = abs(curPos - nextPos);
                    moveSteps = min(moveSteps, ringLength - moveSteps);
                    dp[curPos][j] = min(dp[curPos][j], 1 + dp[nextPos][j + 1] + moveSteps);
                }
            }
        }
        //switch to the first key
        int curPos = 0;
        for (auto &nextPos : charToIndex[key[0]])
        {
            int moveSteps = abs(curPos - nextPos);
            moveSteps = min(moveSteps, ringLength - moveSteps);
            dp[curPos][0] = min(dp[curPos][0], dp[nextPos][0] + moveSteps);
        }

        return dp[0][0];
    }
};
// @lc code=end
