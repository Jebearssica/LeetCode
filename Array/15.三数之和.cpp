/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 *
 * https://leetcode-cn.com/problems/3sum/description/
 *
 * algorithms
 * Medium (29.59%)
 * Likes:    2635
 * Dislikes: 0
 * Total Accepted:    336.8K
 * Total Submissions: 1.1M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0
 * ？请你找出所有满足条件且不重复的三元组。
 * 
 * 注意：答案中不可以包含重复的三元组。
 * 
 * 
 * 
 * 示例：
 * 
 * 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
 * 
 * 满足要求的三元组集合为：
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 * 
 */

// @lc code=start
#include <unordered_map>
#include <algorithm>
class Solution
{
public:
    std::vector<std::vector<int>> threeSum(std::vector<int> &nums)
    {
        //结果
        std::vector<std::vector<int>> result;

        //先排个序
        std::sort(nums.begin(), nums.end());
        int length = nums.size();

        for (int left = 0; left < length; left++)
        {
            //避免和上次的数字重复
            if (left > 0 && nums[left] == nums[left - 1])
                continue;
            //右侧index
            int right = length - 1;
            int target = -nums[left];
            for (int mid = left + 1; mid < length; mid++)
            {
                //确保第二个数字不重复, 即整个不重复
                if (mid > left + 1 && nums[mid] == nums[mid - 1])
                    continue;

                //寻找符合条件的第三个数
                while (mid < right && nums[mid] + nums[right] > target)
                    right--;

                //检测完毕 跳出
                if (mid == right)
                    break;

                //结果push
                if (nums[mid] + nums[right] == target)
                    result.push_back({nums[left], nums[mid], nums[right]});
            }
        }
        return result;
    }
};
// @lc code=end
