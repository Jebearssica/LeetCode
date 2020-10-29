/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Medium (73.66%)
 * Likes:    759
 * Dislikes: 0
 * Total Accepted:    290.5K
 * Total Submissions: 392.6K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的中序 遍历。
 * 
 * 示例:
 * 
 * 输入: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * 输出: [1,3,2]
 * 
 * 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
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
#include <stack>
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
    std::vector<int> inorderTraversal(TreeNode *root)
    {
        TreeNode *predecessor = nullptr;
        std::vector<int> result;
        while (root != nullptr)
        {
            //有左节点
            if (root->left != nullptr)
            {
                predecessor = root->left;
                //寻找到左子树中的最右节点记为predecessor
                while (predecessor->right != nullptr && predecessor->right != root)
                    predecessor = predecessor->right;
                //如果predecessor右节点为空, 则指向root, root向左移动
                if (predecessor->right == nullptr)
                {
                    predecessor->right = root;
                    root = root->left;
                }
                //如果predecessor右节点指向root, 则指向null, root向右移动
                //说明了左子树遍历完毕, 当前root的值应该入栈
                else
                {
                    result.push_back(root->val);
                    predecessor->right = nullptr;
                    root = root->right;
                }
            }
            //如果无左节点, 则输出结果并移动到右节点
            else
            {
                result.push_back(root->val);
                root = root->right;
            }
                }
        return result;
    }
};
// @lc code=end
