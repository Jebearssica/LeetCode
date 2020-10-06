/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 *
 * https://leetcode-cn.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (39.05%)
 * Likes:    990
 * Dislikes: 0
 * Total Accepted:    177.8K
 * Total Submissions: 454.7K
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
 * 
 * ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
 * 
 * 搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。
 * 
 * 你可以假设数组中不存在重复的元素。
 * 
 * 你的算法时间复杂度必须是 O(log n) 级别。
 * 
 * 示例 1:
 * 
 * 输入: nums = [4,5,6,7,0,1,2], target = 0
 * 输出: 4
 * 
 * 
 * 示例 2:
 * 
 * 输入: nums = [4,5,6,7,0,1,2], target = 3
 * 输出: -1
 * 
 */

// @lc code=start
#include <vector>
class Solution
{
public:
    int search(std::vector<int> &nums, int target)
    {
        int right = nums.size() - 1, left = 0, index;

        while (left <= right)
        {
            index = (left + right) / 2;
            //找到target
            if (nums[index] == target)
                return index;
            else
                //正常二分 ^ 左侧必定找不到 ^ 拐点在左侧
                (nums[index] < target) ^ (nums[0] > target) ^ (nums[0] > nums[index])
                    ? left = index + 1
                    : right = index - 1;
        }
        //没找到
        return -1;
    }
};
// @lc code=end
