/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
 *
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/description/
 *
 * algorithms
 * Medium (69.47%)
 * Likes:    469
 * Dislikes: 0
 * Total Accepted:    156.8K
 * Total Submissions: 225.6K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，返回其节点值自底向上的层序遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
 * 
 * 例如：
 * 给定二叉树 [3,9,20,null,null,15,7],
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 返回其自底向上的层序遍历为：
 * 
 * 
 * [
 * ⁠ [15,7],
 * ⁠ [9,20],
 * ⁠ [3]
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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };
#include <vector>
using namespace std;
class Solution
{
public:
    void traverse(TreeNode *root, int depth, vector<vector<int>> &result)
    {
        if (root == nullptr)
            return;
        traverse(root->left, depth + 1, result);
        traverse(root->right, depth + 1, result);
        result[result.size() - depth].push_back(root->val);
    }
    int getDepth(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int leftDepth = getDepth(root->left);
        int rightDepth = getDepth(root->right);
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        int depth = getDepth(root);
        vector<vector<int>> result(depth, vector<int>());
        traverse(root, 1, result);
        return result;
    }
};
// @lc code=end
