/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 *
 * https://leetcode-cn.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (45.84%)
 * Likes:    587
 * Dislikes: 0
 * Total Accepted:    157.3K
 * Total Submissions: 343.1K
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * 给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target
 * 最接近。返回这三个数的和。假定每组输入只存在唯一答案。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：nums = [-1,2,1,-4], target = 1
 * 输出：2
 * 解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 3 <= nums.length <= 10^3
 * -10^3 <= nums[i] <= 10^3
 * -10^4 <= target <= 10^4
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <algorithm>
class Solution
{
public:
    int threeSumClosest(std::vector<int> &nums, int target)
    {
        //很像三数之和, 直接双指针来一发

        //先排个序
        std::sort(nums.begin(), nums.end());
        int length = nums.size();
        int delta = 10000;
        int tempDelta = 0;
        int result = 0;
        //储存临时的三数之和
        int tempSum = 0;
        //left index
        int left = 0;
        //mid index
        int mid = 0;
        //右侧index
        int right = 0;

        while (left < length)
        {
            //mid index
            mid = left + 1;
            right = length - 1;
            while (mid < right)
            {
                tempSum = nums[left] + nums[mid] + nums[right];
                if (tempSum == target)
                    return target;
                tempDelta = abs(tempSum - target);
                //更优解则更新
                if (delta > tempDelta)
                {
                    result = tempSum;
                    delta = tempDelta;
                }
                (tempSum > target) ? right-- : mid++;
                // if (tempSum > target)
                // {
                //     //排除从右侧开始的重复数
                //     while (mid < right - 1 && nums[right - 1] == nums[right])
                //         right--;
                // }
                // else
                // {
                //     //排除mid左侧开始的重复数
                //     while (mid + 1 < right && nums[mid + 1] == nums[mid])
                //         mid++;
                // }
            }
            // //避免和上次的数字重复
            // while (left > 0 && nums[left] == nums[left - 1])
            //     left++;
            left++;
        }
        return result;
    }
};
// @lc code=end
