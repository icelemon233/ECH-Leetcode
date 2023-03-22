/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
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
    // 栈、队列解法参考101.对称二叉树
    bool traversal(TreeNode *left, TreeNode *right)
    {
        if (left != NULL && right == NULL)
        {
            return false;
        }
        if (left == NULL && right != NULL)
        {
            return false;
        }
        if (left == NULL && right == NULL)
        {
            return true;
        }
        if (left->val != right->val)
        {
            return false;
        }
        bool isLeftSame = traversal(left->left, right->left);
        bool isRightSame = traversal(left->right, right->right);
        return isLeftSame && isRightSame;
    }

    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        return traversal(p, q);
    }
};
// @lc code=end
