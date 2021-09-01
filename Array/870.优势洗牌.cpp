/*
 * @lc app=leetcode.cn id=870 lang=cpp
 *
 * [870] 优势洗牌
 *
 * https://leetcode-cn.com/problems/advantage-shuffle/description/
 *
 * algorithms
 * Medium (42.29%)
 * Likes:    143
 * Dislikes: 0
 * Total Accepted:    13.8K
 * Total Submissions: 32.6K
 * Testcase Example:  '[2,7,11,15]\n[1,10,4,11]'
 *
 * 给定两个大小相等的数组 A 和 B，A 相对于 B 的优势可以用满足 A[i] > B[i] 的索引 i 的数目来描述。
 * 
 * 返回 A 的任意排列，使其相对于 B 的优势最大化。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：A = [2,7,11,15], B = [1,10,4,11]
 * 输出：[2,11,7,15]
 * 
 * 
 * 示例 2：
 * 
 * 输入：A = [12,24,8,32], B = [13,25,32,11]
 * 输出：[24,32,8,12]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= A.length = B.length <= 10000
 * 0 <= A[i] <= 10^9
 * 0 <= B[i] <= 10^9
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> advantageCount(vector<int> &nums1, vector<int> &nums2)
    {
        int length = nums1.size();
        vector<int> &nums2Temp = nums2;
        sort(nums1.begin(), nums1.end(), greater<int>());
        vector<pair<int, int>> sortedNums2(length);
        for (size_t i = 0; i < length; i++)
        {
            sortedNums2[i] = {nums2[i], i};
        }
        sort(sortedNums2.begin(), sortedNums2.end(), [](pair<int, int> a, pair<int, int> b)
             { return a.first > b.first; });
        vector<int> results(length);
        int idxSmall = length - 1, idxLarge = 0;
        for (int i = 0; i < length; i++)
        {
            results[sortedNums2[i].second] = nums1[idxLarge] <= sortedNums2[i].first ? nums1[idxSmall--] : nums1[idxLarge++];
        }
        return results;
    }
};
// @lc code=end
