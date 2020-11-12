/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
 *
 * https://leetcode-cn.com/problems/recover-binary-search-tree/description/
 *
 * algorithms
 * Hard (61.97%)
 * Likes:    361
 * Dislikes: 0
 * Total Accepted:    41.6K
 * Total Submissions: 67.1K
 * Testcase Example:  '[1,3,null,null,2]'
 *
 * 二叉搜索树中的两个节点被错误地交换。
 * 
 * 请在不改变其结构的情况下，恢复这棵树。
 * 
 * 示例 1:
 * 
 * 输入: [1,3,null,null,2]
 * 
 * 1
 * /
 * 3
 * \
 * 2
 * 
 * 输出: [3,1,null,null,2]
 * 
 * 3
 * /
 * 1
 * \
 * 2
 * 
 * 
 * 示例 2:
 * 
 * 输入: [3,1,4,null,null,2]
 * 
 * ⁠ 3
 * ⁠/ \
 * 1   4
 * /
 * 2
 * 
 * 输出: [2,1,4,null,null,3]
 * 
 * ⁠ 2
 * ⁠/ \
 * 1   4
 * /
 * ⁠ 3
 * 
 * 进阶:
 * 
 * 
 * 使用 O(n) 空间复杂度的解法很容易实现。
 * 你能想出一个只使用常数空间的解决方案吗？
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
#include <algorithm>
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
    void recoverTree(TreeNode *root)
    {
        TreeNode *predecessor = nullptr, *x = nullptr, *y = nullptr, *pred = nullptr;
        while (root != nullptr)
        {
            //有左节点
            if (root->left != nullptr)
            {
                predecessor = root->left;
                //找到左子树的最右节点
                while (predecessor->right != nullptr && predecessor->right != root)
                    predecessor = predecessor->right;
                //predecessor右节点为空, 则指向root, root移到左子树
                if (predecessor->right == nullptr)
                {
                    predecessor->right = root;
                    root = root->left;
                }
                //predecessor右节点指向root, 则指向null, root移到右子树
                else
                {
                    if (pred != nullptr && root->val < pred->val)
                    {
                        y = root;
                        if (x == nullptr)
                            x = pred;
                    }
                    pred = root;
                    predecessor->right = nullptr;
                    root = root->right;
                }
            }
            //已经到左子树的最右节点
            else
            {
                if (pred != nullptr && root->val < pred->val)
                {
                    y = root;
                    if (x == nullptr)
                        x = pred;
                }
                pred = root;
                root = root->right;
            }
        }
        //找到两个需要交换的结点交换值
        std::swap(x->val, y->val);
    }
};
// @lc code=end
