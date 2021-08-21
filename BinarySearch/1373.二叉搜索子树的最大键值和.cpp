/*
 * @lc app=leetcode.cn id=1373 lang=cpp
 *
 * [1373] 二叉搜索子树的最大键值和
 *
 * https://leetcode-cn.com/problems/maximum-sum-bst-in-binary-tree/description/
 *
 * algorithms
 * Hard (39.63%)
 * Likes:    53
 * Dislikes: 0
 * Total Accepted:    6.3K
 * Total Submissions: 15.8K
 * Testcase Example:  '[1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]'
 *
 * 给你一棵以 root 为根的 二叉树 ，请你返回 任意 二叉搜索子树的最大键值和。
 * 
 * 二叉搜索树的定义如下：
 * 
 * 
 * 任意节点的左子树中的键值都 小于 此节点的键值。
 * 任意节点的右子树中的键值都 大于 此节点的键值。
 * 任意节点的左子树和右子树都是二叉搜索树。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：root = [1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]
 * 输出：20
 * 解释：键值为 3 的子树是和最大的二叉搜索树。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 
 * 输入：root = [4,3,null,1,2]
 * 输出：2
 * 解释：键值为 2 的单节点子树是和最大的二叉搜索树。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：root = [-4,-2,-5]
 * 输出：0
 * 解释：所有节点键值都为负数，和最大的二叉搜索树为空。
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：root = [2,1,3]
 * 输出：6
 * 
 * 
 * 示例 5：
 * 
 * 
 * 输入：root = [5,4,8,3,null,6,3]
 * 输出：7
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 每棵树有 1 到 40000 个节点。
 * 每个节点的键值在 [-4 * 10^4 , 4 * 10^4] 之间。
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
#include <stdint.h>
#include <vector>
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
    int maxSum = 0;
    std::vector<int> traverse(TreeNode *root)
    {
        std::vector<int> finalResult(4, 0);
        if (root == nullptr)
        {
            return std::vector<int>{1, INT_MAX, INT_MIN, 0};
        }
        else
        {
            std::vector<int> leftResult = traverse(root->left);
            std::vector<int> rightResult = traverse(root->right);
            //judge isBST
            if (leftResult[0] == 1 && rightResult[0] == 1 && root->val > leftResult[2] && root->val < rightResult[1])
            {
                //update the data
                finalResult[0] = 1;
                finalResult[2] = (rightResult[2] > root->val) ? rightResult[2] : root->val;
                finalResult[1] = (leftResult[1] < root->val) ? leftResult[1] : root->val;
                finalResult[3] = leftResult[3] + rightResult[3] + root->val;
                maxSum = (maxSum > finalResult[3]) ? maxSum : finalResult[3];
            }
            else
            {
                finalResult[0] = false;
            }
        }
        return finalResult;
    }
    int maxSumBST(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        else
        {
            traverse(root);
            return (maxSum > 0) ? maxSum : 0;
        }
    }
};
// @lc code=end
