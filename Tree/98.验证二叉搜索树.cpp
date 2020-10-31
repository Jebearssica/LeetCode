/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 *
 * https://leetcode-cn.com/problems/validate-binary-search-tree/description/
 *
 * algorithms
 * Medium (32.46%)
 * Likes:    794
 * Dislikes: 0
 * Total Accepted:    177.6K
 * Total Submissions: 546.2K
 * Testcase Example:  '[2,1,3]'
 *
 * 给定一个二叉树，判断其是否是一个有效的二叉搜索树。
 * 
 * 假设一个二叉搜索树具有如下特征：
 * 
 * 
 * 节点的左子树只包含小于当前节点的数。
 * 节点的右子树只包含大于当前节点的数。
 * 所有左子树和右子树自身必须也是二叉搜索树。
 * 
 * 
 * 示例 1:
 * 
 * 输入:
 * ⁠   2
 * ⁠  / \
 * ⁠ 1   3
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * ⁠   5
 * ⁠  / \
 * ⁠ 1   4
 * / \
 * 3   6
 * 输出: false
 * 解释: 输入为: [5,1,4,null,null,3,6]。
 * 根节点的值为 5 ，但是其右子节点值为 4 。
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <cstdint>
#include <stack>
// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };
class Solution
{
public:
    bool isValidBST(TreeNode *root)
    {
        //储存的栈
        std::stack<TreeNode *> stack;
        //当前结点的值
        int64_t tempNumber = INT64_MIN;

        while (!stack.empty() || root != nullptr)
        {
            while (root != nullptr)
            {
                stack.push(root);
                root = root->left;
            }

            root = stack.top();
            stack.pop();

            //如果得到结点的值不是升序排列, 则不是二叉搜索树
            if (root->val <= tempNumber)
            {
                return false;
            }

            tempNumber = root->val;
            root = root->right;
        }

        return true;
        
    }
};
// @lc code=end
