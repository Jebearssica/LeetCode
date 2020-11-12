/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层次遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * algorithms
 * Medium (55.00%)
 * Likes:    292
 * Dislikes: 0
 * Total Accepted:    78.7K
 * Total Submissions: 142.7K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
 * 
 * 例如：
 * 给定二叉树 [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 返回锯齿形层次遍历如下：
 * 
 * [
 * ⁠ [3],
 * ⁠ [20,9],
 * ⁠ [15,7]
 * ]
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
#include <vector>
#include <queue>
// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };
class Solution
{
public:
    std::vector<std::vector<int>> result;
    std::vector<std::vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        std::queue<TreeNode *> q;
        //先从左往右
        bool goLeft = true;
        if (!root)
            return result;
        else
        {
            q.push(root);
            while (!q.empty())
            {
                size_t step = q.size();
                std::vector<int> currentLayer(step, 0);
                for (size_t i = 0; i < step; i++)
                {
                    auto tempNode = q.front();
                    q.pop();
                    currentLayer[goLeft ? i : step - i - 1] = tempNode->val;
                    if (tempNode->left)
                        q.push(tempNode->left);
                    if (tempNode->right)
                        q.push(tempNode->right);
                }
                result.push_back(currentLayer);
                goLeft = !goLeft;
            }
        }
        return result;
    }
};
// @lc code=end
