/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (69.42%)
 * Likes:    944
 * Dislikes: 0
 * Total Accepted:    168.7K
 * Total Submissions: 243K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * 根据一棵树的前序遍历与中序遍历构造二叉树。
 * 
 * 注意:
 * 你可以假设树中没有重复的元素。
 * 
 * 例如，给出
 * 
 * 前序遍历 preorder = [3,9,20,15,7]
 * 中序遍历 inorder = [9,3,15,20,7]
 * 
 * 返回如下的二叉树：
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
    std::unordered_map<int, int> maxMapIndex;
public:
    TreeNode *buildSubTree(std::vector<int> &preorder, std::vector<int> &inorder, int preStart, int preEnd, int inStart, int inEnd)
    {
        if (preStart > preEnd)
            return nullptr;

        int rootValue = preorder[preStart], rootIndex = 0;
        rootIndex = maxMapIndex[rootValue];
        int numSubLeftNodes = rootIndex - inStart;
        TreeNode *root = new TreeNode(rootValue);
        root->left = buildSubTree(preorder, inorder, preStart + 1, preStart + numSubLeftNodes, inStart, rootIndex - 1);
        root->right = buildSubTree(preorder, inorder, preStart + 1 + numSubLeftNodes, preEnd, rootIndex + 1, inEnd);
        return root;
    }
    TreeNode *buildTree(std::vector<int> &preorder, std::vector<int> &inorder)
    {
        for (int i = 0; i < preorder.size(); i++)
            maxMapIndex[inorder[i]] = i;
        
        return buildSubTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};
// @lc code=end
