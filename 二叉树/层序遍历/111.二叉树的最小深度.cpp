/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    // int traversal(TreeNode *node)
    // {
    //     if (node == NULL)
    //     {
    //         return 0;
    //     }
    //     int leftDepth = traversal(node->left);
    //     int rightDepth = traversal(node->right);
    //     if (node->left != NULL && node->right == NULL)
    //     {
    //         return 1 + leftDepth;
    //     }
    //     if (node->left == NULL && node->right != NULL)
    //     {
    //         return 1 + rightDepth;
    //     }
    //     return 1 + min(leftDepth, rightDepth);
    // }

    // int minDepth(TreeNode *root)
    // {
    //     return traversal(root);
    // }

    // 迭代法
    int minDepth(TreeNode *root)
    {
        queue<TreeNode *> que;
        int depth = 0;
        if (root == NULL)
        {
            return depth;
        }
        que.push(root);
        while (!que.empty())
        {
            int qsize = que.size();
            depth++;
            for (int i = 0; i < qsize; i++)
            {
                TreeNode *node = que.front();
                que.pop();
                if (node->left)
                {
                    que.push(node->left);
                }
                if (node->right)
                {
                    que.push(node->right);
                }
                if (!node->left && !node->right)
                {
                    return depth;
                }
            }
        }
        return depth;
    }
};
// @lc code=end
