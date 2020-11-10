/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 *
 * https://leetcode-cn.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (53.00%)
 * Likes:    1063
 * Dislikes: 0
 * Total Accepted:    215K
 * Total Submissions: 405.4K
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * 给定一个二叉树，检查它是否是镜像对称的。
 * 
 * 
 * 
 * 例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠/ \ / \
 * 3  4 4  3
 * 
 * 
 * 
 * 
 * 但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠  \   \
 * ⁠  3    3
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 你可以运用递归和迭代两种方法解决这个问题吗？
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
#include <queue>
// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(nullptr), right(NULL) {}
// };
class Solution
{
public:
    std::queue<TreeNode *> Queue;
    bool check(TreeNode *left, TreeNode *right)
    {
        Queue.push(left);
        Queue.push(right);
        while (!Queue.empty())
        {
            left = Queue.front();
            Queue.pop();
            right = Queue.front();
            Queue.pop();
            if (left == nullptr && right == nullptr)
                continue;
            else if ((left == nullptr || right == nullptr) || left->val != right->val)
                return false;
            else
            {
                Queue.push(left->left);
                Queue.push(right->right);
                Queue.push(left->right);
                Queue.push(right->left);
            }
        }
        return true;
    }
    bool isSymmetric(TreeNode *root)
    {
        return check(root, root);
    }
};
// @lc code=end
