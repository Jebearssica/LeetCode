/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 *
 * https://leetcode-cn.com/problems/4sum/description/
 *
 * algorithms
 * Medium (38.44%)
 * Likes:    578
 * Dislikes: 0
 * Total Accepted:    110.5K
 * Total Submissions: 287.7K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * 给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c
 * + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
 * 
 * 注意：
 * 
 * 答案中不可以包含重复的四元组。
 * 
 * 示例：
 * 
 * 给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
 * 
 * 满足要求的四元组集合为：
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <algorithm>
class Solution
{
public:
    std::vector<std::vector<int>> fourSum(std::vector<int> &nums, int target)
    {
        int length = nums.size();
        //四个index
        int right = length - 1, midLeft, midRight;
        int tempSum = 0;
        //结果
        std::vector<std::vector<int>> result;
        //先排序
        std::sort(nums.begin(), nums.end());
        //注意中间应该足够放下四个数
        //一定要从length-2做为判断, 如果使用right第一重循环过后就会跳出, 并且重初始化也会困难
        for (int left = 0; left < length - 3; left++)
        {
            for (right = length - 1; right > left + 2; right--)
            {
                midLeft = left + 1;
                midRight = right - 1;
                while (midLeft < midRight)
                {
                    tempSum = nums[left] + nums[right] + nums[midLeft] + nums[midRight];
                    //根据结果判断中间的双指针移动方向
                    if (tempSum != target)
                        (tempSum > target) ? midRight-- : midLeft++;
                    else
                    {
                        result.push_back({nums[left], nums[midLeft], nums[midRight], nums[right]});
                        //两侧指针避开重复值向中间逼近
                        while (midLeft < midRight && nums[midLeft + 1] == nums[midLeft])
                            midLeft++;
                        while (midRight > midLeft && nums[midRight - 1] == nums[midRight])
                            midRight--;
                        midLeft++;
                        midRight--;
                    }
                }
                //做完第一次后排除重复项
                while (right > left + 2 && nums[right - 1] == nums[right])
                    right--;
            }
            //做完第一次后排除重复项
            while (left < length - 3 && nums[left + 1] == nums[left])
                left++;
        }
        return result;
    }
};
// @lc code=end
