/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
    // int traversal(TreeNode *node, int depth)
    // {
    //     if (node == NULL)
    //     {
    //         return depth;
    //     }
    //     int leftDepth = traversal(node->left, depth + 1);
    //     int rightDepth = traversal(node->right, depth + 1);
    //     return max(leftDepth, rightDepth);
    // }
    // int maxDepth(TreeNode *root)
    // {
    //     return traversal(root, 0);
    // }

    // 迭代法
    int maxDepth(TreeNode *root)
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
            }
        }
        return depth;
    }
};
// @lc code=end
