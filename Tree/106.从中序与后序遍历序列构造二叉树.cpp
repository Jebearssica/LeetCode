/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (71.47%)
 * Likes:    469
 * Dislikes: 0
 * Total Accepted:    95.7K
 * Total Submissions: 133.9K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * 根据一棵树的中序遍历与后序遍历构造二叉树。
 * 
 * 注意:
 * 你可以假设树中没有重复的元素。
 * 
 * 例如，给出
 * 
 * 中序遍历 inorder = [9,3,15,20,7]
 * 后序遍历 postorder = [9,15,7,20,3]
 * 
 * 返回如下的二叉树：
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
#include <unordered_map>
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
private:
    std::unordered_map<int, int> map;

public:
    TreeNode *buildSubTree(std::vector<int> &inorder, std::vector<int> &postorder, int inStart, int inEnd, int postStart, int postEnd)
    {
        if (inStart > inEnd)
            return nullptr;
        int maxValue = postorder[postEnd], rootIndex = map[maxValue];
        TreeNode *root = new TreeNode(maxValue);
        int numSubLeftNodes = rootIndex - inStart;
        root->left = buildSubTree(inorder, postorder, inStart, rootIndex - 1, postStart, postStart + numSubLeftNodes - 1);
        root->right = buildSubTree(inorder, postorder, rootIndex + 1, inEnd, postStart + numSubLeftNodes, postEnd - 1);
        return root;
    }
    TreeNode *buildTree(std::vector<int> &inorder, std::vector<int> &postorder)
    {
        for (int i = postorder.size() - 1; i >= 0; i--)
            map[inorder[i]] = i;
        return buildSubTree(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
};
// @lc code=end
