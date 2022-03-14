/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 *
 * https://leetcode-cn.com/problems/count-primes/description/
 *
 * algorithms
 * Medium (37.71%)
 * Likes:    831
 * Dislikes: 0
 * Total Accepted:    186.1K
 * Total Submissions: 493.5K
 * Testcase Example:  '10'
 *
 * 给定整数 n ，返回 所有小于非负整数 n 的质数的数量 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：n = 10
 * 输出：4
 * 解释：小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
 *
 *
 * 示例 2：
 *
 *
 * 输入：n = 0
 * 输出：0
 *
 *
 * 示例 3：
 *
 *
 * 输入：n = 1
 * 输出：0
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= n <= 5 * 10^6
 *
 *
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    int countPrimes(int n)
    {
        vector<bool> isPrime(n, true);
        vector<int> prime;
        for (int curNum = 2; curNum < n; ++curNum)
        {
            if (isPrime[curNum])
                prime.push_back(curNum);
            for (int primeIdx = 0; primeIdx < prime.size() && curNum * prime[primeIdx] < n; ++primeIdx)
            {
                isPrime[curNum * prime[primeIdx]] = false;
                if (curNum % prime[primeIdx] == 0)
                    break;
            }
        }
        return prime.size();
    }
};
// @lc code=end
