/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    // 递归法
    int traversal(TreeNode *node)
    {
        if (node == NULL)
        {
            return 0;
        }
        int leftDepth = traversal(node->left);
        if (leftDepth == -1)
        {
            return -1;
        }
        int rightDepth = traversal(node->right);
        if (rightDepth == -1)
        {
            return -1;
        }
        return abs(leftDepth - rightDepth) > 1 ? -1 : 1 + max(leftDepth, rightDepth);
    }
    bool isBalanced(TreeNode *root)
    {
        return traversal(root) == -1 ? false : true;
    }
};
// @lc code=end
