/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (63.41%)
 * Likes:    689
 * Dislikes: 0
 * Total Accepted:    214.6K
 * Total Submissions: 337.2K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。
 * 
 * 
 * 
 * 示例：
 * 二叉树：[3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 返回其层次遍历结果：
 * 
 * [
 * ⁠ [3],
 * ⁠ [9,20],
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
    std::vector<int> currentLayer;
    std::queue<TreeNode *> q;
    std::vector<std::vector<int>> levelOrder(TreeNode *root)
    {
        if (root == nullptr)
            return result;
        q.push(root);
        while (!q.empty())
        {
            int step = q.size();
            for (int i = 0; i < step; i++)
            {
                auto tempNode = q.front();
                q.pop();
                currentLayer.push_back(tempNode->val);
                if (tempNode->left)
                {
                    q.push(tempNode->left);
                }
                if (tempNode->right)
                {
                    q.push(tempNode->right);
                }
            }
            result.push_back(currentLayer);
            currentLayer.clear();
        }
        return result;
    }
};
// @lc code=end
