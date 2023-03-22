/*
 * @lc app=leetcode.cn id=617 lang=cpp
 *
 * [617] 合并二叉树
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
    // 以root1为主树，将root2加到root1中
    TreeNode *traversal(TreeNode *node1, TreeNode *node2)
    {
        if (node1 && !node2)
        {
            return node1;
        }
        if (!node1 && node2)
        {
            return node2;
        }
        if (!node1 && !node2)
        {
            return NULL;
        }
        // if (node1 == NULL)
        // {
        //     return node2;
        // }
        // if (node2 == NULL)
        // {
        //     return node1;
        // }

        node1->val += node2->val;
        node1->left = traversal(node1->left, node2->left);
        node1->right = traversal(node1->right, node2->right);
        return node1;
    }
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        return traversal(root1, root2);
    }
};
// @lc code=end
