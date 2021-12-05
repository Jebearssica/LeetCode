/*
 * @lc app=leetcode.cn id=5944 lang=cpp
 *
 * [5944] 从二叉树一个节点到另一个节点每一步的方向
 *
 * https://leetcode-cn.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/description/
 *
 * algorithms
 * Medium (32.45%)
 * Likes:    13
 * Dislikes: 0
 * Total Accepted:    2.6K
 * Total Submissions: 7.2K
 * Testcase Example:  '[5,1,2,3,null,6,4]\n3\n6'
 *
 * 给你一棵 二叉树 的根节点 root ，这棵二叉树总共有 n 个节点。每个节点的值为 1 到 n 中的一个整数，且互不相同。给你一个整数
 * startValue ，表示起点节点 s 的值，和另一个不同的整数 destValue ，表示终点节点 t 的值。
 *
 * 请找到从节点 s 到节点 t 的 最短路径 ，并以字符串的形式返回每一步的方向。每一步用 大写 字母 'L' ，'R' 和 'U'
 * 分别表示一种方向：
 *
 *
 * 'L' 表示从一个节点前往它的 左孩子 节点。
 * 'R' 表示从一个节点前往它的 右孩子 节点。
 * 'U' 表示从一个节点前往它的 父 节点。
 *
 *
 * 请你返回从 s 到 t 最短路径 每一步的方向。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：root = [5,1,2,3,null,6,4], startValue = 3, destValue = 6
 * 输出："UURL"
 * 解释：最短路径为：3 → 1 → 5 → 2 → 6 。
 *
 *
 * 示例 2：
 *
 *
 *
 * 输入：root = [2,1], startValue = 2, destValue = 1
 * 输出："L"
 * 解释：最短路径为：2 → 1 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点数目为 n 。
 * 2 <= n <= 10^5
 * 1 <= Node.val <= n
 * 树中所有节点的值 互不相同 。
 * 1 <= startValue, destValue <= n
 * startValue != destValue
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
class Solution
{
public:
    bool backtracing(TreeNode *root, int target, string &res)
    {
        if (root->val == target)
            return true;
        if (root->left != nullptr)
        {
            res.push_back('L');
            if (backtracing(root->left, target, res))
                return true;
            res.pop_back();
        }
        if (root->right != nullptr)
        {
            res.push_back('R');
            if (backtracing(root->right, target, res))
                return true;
            res.pop_back();
        }
        return false;
    }
    string getDirections(TreeNode *root, int startValue, int destValue)
    {
        // 无法通过子结点访问父节点, 因此只能一开始就从root找路径
        // BFS find start & dest point, then combine the start->root->dest
        string resToStart, resToDest;
        backtracing(root, startValue, resToStart);
        backtracing(root, destValue, resToDest);
        bool isStartDeeper = resToStart.size() > resToDest.size();
        string res;
        int changeIdx = 0;
        for (; changeIdx < min(resToStart.size(), resToDest.size()); changeIdx++)
        {
            if (resToStart[changeIdx] == resToDest[changeIdx])
                continue;
            else
                break;
        }
        // 查看是否前面的路完全一致
        if (changeIdx == min(resToStart.size(), resToDest.size()))
        {
            if (isStartDeeper)
                for (int i = changeIdx; i < resToStart.size(); i++)
                    res.push_back('U');
            else
                for (int i = changeIdx; i < resToDest.size(); i++)
                    res.push_back(resToDest[i]);
        }
        // 当前结点开始 出现差异
        else
        {
            //将起始点返回至差异点
            for (int i = changeIdx; i < resToStart.size(); i++)
                res.push_back('U');
            for (int i = changeIdx; i < resToDest.size(); i++)
                res.push_back(resToDest[i]);
        }
        return res;
    }
};
// @lc code=end
