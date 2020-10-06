/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 *
 * https://leetcode-cn.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (34.54%)
 * Likes:    680
 * Dislikes: 0
 * Total Accepted:    92K
 * Total Submissions: 266.2K
 * Testcase Example:  '[1,2,3]'
 *
 * 实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
 * 
 * 如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
 * 
 * 必须原地修改，只允许使用额外常数空间。
 * 
 * 以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 * 
 */

// @lc code=start
#include <vector>
#include <algorithm>
class Solution
{
public:
    void nextPermutation(std::vector<int> &nums)
    {
        //一个返回nums的迭代器
        std::vector<int>::iterator numsIt = nums.begin();
        int length = nums.size();
        int right = length - 2;
        //先判断是否已经为逆序数组, 从后往前查
        while (right >= 0 && nums[right + 1] <= nums[right])
            right--;
        //已经为逆序了
        if (right >= 0)
        {
            //此时的nums[right]为需要交换的元素之一
            //与后方[right+1,length-1]之间最小的大于它的数交换
            int midRight = length - 1;
            //再次从后往前找
            while (midRight >= 0 && nums[midRight] <= nums[right])
                midRight--;
            std::swap(nums[right], nums[midRight]);
        }
        //[right+1,end()]之间逆序, 从而使得后面的数最小
        std::reverse(numsIt + right + 1, nums.end());
    }
};
// @lc code=end
