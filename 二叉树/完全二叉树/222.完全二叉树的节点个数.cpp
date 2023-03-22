/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
    //     int leftNodeNum = traversal(node->left);
    //     int rightNodeNum = traversal(node->right);
    //     return 1 + leftNodeNum + rightNodeNum;
    // }

    // int countNodes(TreeNode *root)
    // {
    //     return traversal(root);
    // }

    // 迭代法
    int countNodes(TreeNode *root)
    {
        int ret = 0;
        queue<TreeNode *> que;
        if (root == NULL)
        {
            return 0;
        }
        que.push(root);
        while (!que.empty())
        {
            int qsize = que.size();
            for (int i = 0; i < qsize; i++)
            {
                TreeNode *node = que.front();
                ret++;
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
        return ret;
    }
};
// @lc code=end
