/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 *
 * https://leetcode-cn.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (38.79%)
 * Likes:    3246
 * Dislikes: 0
 * Total Accepted:    265.2K
 * Total Submissions: 683.5K
 * Testcase Example:  '[1,3]\n[2]'
 *
 * 给定两个大小为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的中位数。
 * 
 * 进阶：你能设计一个时间复杂度为 O(log (m+n)) 的算法解决此问题吗？
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums1 = [1,3], nums2 = [2]
 * 输出：2.00000
 * 解释：合并数组 = [1,2,3] ，中位数 2
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums1 = [1,2], nums2 = [3,4]
 * 输出：2.50000
 * 解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
 * 
 * 
 * 示例 3：
 * 
 * 输入：nums1 = [0,0], nums2 = [0,0]
 * 输出：0.00000
 * 
 * 
 * 示例 4：
 * 
 * 输入：nums1 = [], nums2 = [1]
 * 输出：1.00000
 * 
 * 
 * 示例 5：
 * 
 * 输入：nums1 = [2], nums2 = []
 * 输出：2.00000
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * nums1.length == m
 * nums2.length == n
 * 0 <= m <= 1000
 * 0 <= n <= 1000
 * 1 <= m + n <= 2000
 * -10^6 <= nums1[i], nums2[i] <= 10^6
 * 
 * 
 */

// @lc code=start
#include <vector>
#define min(a, b) ((a) < (b) ? (a) : (b))
class Solution
{
public:
    double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2)
    {
        //考虑到O(log(m+n)), 使用二分法
        int totalLength = nums1.size() + nums2.size();
        int length1 = nums1.size(), length2 = nums2.size();
        int index1 = 0, index2 = 0;
        //如果不能整除, 则结果为1个数, isOne为1, true
        bool isOne = totalLength % 2;
        int location = int(totalLength / 2) - 1;
        while (true)
        {
            //判断nums1与nums2为0
            if (index1 == length1)
                return isOne ? nums2[location] : (nums2[location] + nums2[location + 1]) / 2;
            if (index2 == length2)
                return isOne ? nums1[location] : (nums1[location] + nums1[location + 1]) / 2;

            if (location == 1)
            {
                return min(nums1[index1], nums2[index2]);
            }
            int half = int(location / 2);
            int newIndex1 = min(index1 + half, length1) - 1;
            int newIndex2 = min(index2 + half, length2) - 1;
            int select1 = nums1[newIndex1];
            int select2 = nums2[newIndex2];
            if (select1 <= select2)
            {
                location -= newIndex1 - index1 + 1;
                index1 = newIndex1 + 1;
            }
            else
            {
                location -= newIndex2 - index2 + 1;
                index2 = newIndex2 + 1;
            }
        }
    }
};
// @lc code=end
