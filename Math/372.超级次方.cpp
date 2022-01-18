/*
 * @lc app=leetcode.cn id=372 lang=cpp
 *
 * [372] 超级次方
 *
 * https://leetcode-cn.com/problems/super-pow/description/
 *
 * algorithms
 * Medium (54.45%)
 * Likes:    240
 * Dislikes: 0
 * Total Accepted:    34.3K
 * Total Submissions: 59.7K
 * Testcase Example:  '2\n[3]'
 *
 * 你的任务是计算 a^b 对 1337 取模，a 是一个正整数，b 是一个非常大的正整数且会以数组形式给出。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：a = 2, b = [3]
 * 输出：8
 *
 *
 * 示例 2：
 *
 *
 * 输入：a = 2, b = [1,0]
 * 输出：1024
 *
 *
 * 示例 3：
 *
 *
 * 输入：a = 1, b = [4,3,3,8,5,2]
 * 输出：1
 *
 *
 * 示例 4：
 *
 *
 * 输入：a = 2147483647, b = [2,0,0]
 * 输出：1198
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * 1
 * 0
 * b 不含前导 0
 *
 *
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
private:
    const int MOD = 1337;

public:
    int myPow(int x, int n)
    {
        int res = 1, base = x;
        int exp = n;
        while (exp != 0)
        {
            if (exp % 2 != 0)
                res = (long)res * base % MOD;
            base = (long)base * base % MOD;
            exp /= 2;
        }
        return n >= 0 ? res : 1 / res;
    }
    int superPow(int a, vector<int> &b)
    {
        int res = 1;
        for (int idx = b.size() - 1; idx >= 0; --idx)
        {
            res = (long)res * myPow(a, b[idx]) % MOD;
            a = myPow(a, 10);
        }
        return res;
    }
};
// @lc code=end
