/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 *
 * https://leetcode-cn.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (64.70%)
 * Likes:    1532
 * Dislikes: 0
 * Total Accepted:    557.8K
 * Total Submissions: 862.1K
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * 给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
 *
 * 请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: [3,2,1,5,6,4] 和 k = 2
 * 输出: 5
 *
 *
 * 示例 2:
 *
 *
 * 输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
 * 输出: 4
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * -10^4 
 *
 *
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    void sort(vector<int> &nums, int left, int right)
    {
        if (left >= right)
            return;
        int p = partition(nums, left, right);
        sort(nums, left, p - 1);
        sort(nums, p + 1, right);
    }
    int partition(vector<int> &nums, int left, int right)
    {
        if (left == right)
            return left;
        int p = nums[left];
        // i - > [i+1, j]
        int i = left, j = right + 1;
        while (true)
        {
            while (nums[++i] < p)
            {
                if (i == right)
                    break;
            }
            while (nums[--j] > p)
            {
                if (j == left)
                    break;
            }
            if (i >= j)
                break;
            swap(nums[i], nums[j]);
        }
        swap(nums[j], nums[left]);
        return j;
    }
    void shuffle(vector<int> &nums)
    {
        int length = nums.size();
        for (int idx = 0; idx < length; ++idx)
        {
            int r = idx + rand() % (length - idx);
            swap(nums[idx], nums[r]);
        }
    }
    int findKthLargest(vector<int> &nums, int k)
    {
        shuffle(nums);
        int left = 0, right = nums.size() - 1;
        // 升序对应的索引
        k = nums.size() - k;
        while (left <= right)
        {
            int p = partition(nums, left, right);
            if (p < k)
                left = p + 1;
            else if (p > k)
                right = p - 1;
            else
                return nums[p];
        }
        return -1;
    }
};
// @lc code=end
