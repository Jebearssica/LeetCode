/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
 *
 * https://leetcode-cn.com/problems/unique-binary-search-trees-ii/description/
 *
 * algorithms
 * Medium (66.68%)
 * Likes:    686
 * Dislikes: 0
 * Total Accepted:    64.4K
 * Total Submissions: 96.4K
 * Testcase Example:  '3'
 *
 * 给定一个整数 n，生成所有由 1 ... n 为节点所组成的 二叉搜索树 。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：3
 * 输出：
 * [
 * [1,null,3,2],
 * [3,2,null,1],
 * [3,1,null,null,2],
 * [2,1,3],
 * [1,null,2,null,3]
 * ]
 * 解释：
 * 以上的输出对应以下 5 种不同结构的二叉搜索树：
 * 
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= n <= 8
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <vector>
// Definition for a binary tree node.
// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };
class Solution
{
public:
    std::vector<TreeNode *> generateTrees(int start, int end)
    {
        //当元素集合使用完毕时, 跳出
        if (start > end)
            return {nullptr};
        std::vector<TreeNode *> allTrees;

        for (int i = start; i <= end; i++)
        {
            //生成左子树, 当前最大的元素肯定做为右节点
            std::vector<TreeNode *> leftTrees = generateTrees(start, i - 1);
            //生成右子树, 当前最小的元素肯定做为左节点
            std::vector<TreeNode *> rightTrees = generateTrees(i + 1, end);

            //从左右子树集中抽取一个子树, 拼接到当前结点, 并压入结果栈
            for (auto &left : leftTrees)
            {
                for (auto &right : rightTrees)
                {
                    TreeNode *currentTree = new TreeNode(i);
                    currentTree->left = left;
                    currentTree->right = right;
                    allTrees.emplace_back(currentTree);
                }
            }
        }
        return allTrees;
    }
    std::vector<TreeNode *> generateTrees(int n)
    {
        if (n == 0)
            return {};
        return generateTrees(1, n);
    }
};
// @lc code=end
