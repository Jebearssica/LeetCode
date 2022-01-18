/*
 * @lc app=leetcode.cn id=859 lang=cpp
 *
 * [859] 亲密字符串
 *
 * https://leetcode-cn.com/problems/buddy-strings/description/
 *
 * algorithms
 * Easy (30.44%)
 * Likes:    202
 * Dislikes: 0
 * Total Accepted:    41.3K
 * Total Submissions: 125.5K
 * Testcase Example:  '"ab"\n"ba"'
 *
 * 给你两个字符串 s 和 goal ，只要我们可以通过交换 s 中的两个字母得到与 goal 相等的结果，就返回 true ；否则返回 false 。
 * 
 * 交换字母的定义是：取两个下标 i 和 j （下标从 0 开始）且满足 i != j ，接着交换 s[i] 和 s[j] 处的字符。
 * 
 * 
 * 例如，在 "abcd" 中交换下标 0 和下标 2 的元素可以生成 "cbad" 。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "ab", goal = "ba"
 * 输出：true
 * 解释：你可以交换 s[0] = 'a' 和 s[1] = 'b' 生成 "ba"，此时 s 和 goal 相等。
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "ab", goal = "ab"
 * 输出：false
 * 解释：你只能交换 s[0] = 'a' 和 s[1] = 'b' 生成 "ba"，此时 s 和 goal 不相等。
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "aa", goal = "aa"
 * 输出：true
 * 解释：你可以交换 s[0] = 'a' 和 s[1] = 'a' 生成 "aa"，此时 s 和 goal 相等。
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：s = "aaaaaaabc", goal = "aaaaaaacb"
 * 输出：true
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length, goal.length <= 2 * 10^4
 * s 和 goal 由小写英文字母组成
 * 
 * 
 */

// @lc code=start
#include <string>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    bool buddyStrings(string s, string goal)
    {
        if (s.size() != goal.size())
            return false;
        else
        {
            unordered_map<char, int> charCnt;
            vector<int> diffIdx;
            for (int idx = 0; idx < s.size(); idx++)
            {
                if (s[idx] == goal[idx])
                    charCnt[s[idx]]++;
                else
                    diffIdx.push_back(idx);
            }
            if (diffIdx.size() > 2 || diffIdx.size() == 1)
                return false;
            else if (diffIdx.size() == 2)
                return s[diffIdx[0]] == goal[diffIdx[1]] && s[diffIdx[1]] == goal[diffIdx[0]];
            else
            {
                int cnt = 0;
                for (auto [key, val] : charCnt)
                    if (val >= 2)
                        return true;
                return false;
            }
        }
    }
};
// @lc code=end
