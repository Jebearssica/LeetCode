/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
 *
 * https://leetcode-cn.com/problems/same-tree/description/
 *
 * algorithms
 * Easy (60.16%)
 * Likes:    503
 * Dislikes: 0
 * Total Accepted:    153.2K
 * Total Submissions: 254.4K
 * Testcase Example:  '[1,2,3]\n[1,2,3]'
 *
 * 给定两个二叉树，编写一个函数来检验它们是否相同。
 * 
 * 如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
 * 
 * 示例 1:
 * 
 * 输入:       1         1
 * ⁠         / \       / \
 * ⁠        2   3     2   3
 * 
 * ⁠       [1,2,3],   [1,2,3]
 * 
 * 输出: true
 * 
 * 示例 2:
 * 
 * 输入:      1          1
 * ⁠         /           \
 * ⁠        2             2
 * 
 * ⁠       [1,2],     [1,null,2]
 * 
 * 输出: false
 * 
 * 
 * 示例 3:
 * 
 * 输入:       1         1
 * ⁠         / \       / \
 * ⁠        2   1     1   2
 * 
 * ⁠       [1,2,1],   [1,1,2]
 * 
 * 输出: false
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
#include <stack>
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
    std::stack<TreeNode *> StackP;
    std::stack<TreeNode *> StackQ;
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr && q == nullptr)
            return true;
        else if (p == nullptr || q == nullptr)
            return false;
        else
        {
            TreeNode *tempP = p;
            TreeNode *tempQ = q;
            StackP.push(tempP);
            StackQ.push(tempQ);
            while (!StackP.empty() && !StackQ.empty())
            {
                tempP = StackP.top();
                tempQ = StackQ.top();
                StackP.pop();
                StackQ.pop();
                if (tempP->val != tempQ->val)
                    return false;
                else
                {
                    if (tempP->right != nullptr && tempQ->right != nullptr)
                    {
                        StackP.push(tempP->right);
                        StackQ.push(tempQ->right);
                    }
                    else if (tempP->right != nullptr || tempQ->right != nullptr)
                    {
                        return false;
                    }
                    if (tempP->left != nullptr && tempQ->left != nullptr)
                    {
                        StackP.push(tempP->left);
                        StackQ.push(tempQ->left);
                    }
                    else if (tempP->left != nullptr || tempQ->left != nullptr)
                    {
                        return false;
                    }
                }
            }
            return (StackQ.empty() && StackP.empty());
        }
    }
};
// @lc code=end
