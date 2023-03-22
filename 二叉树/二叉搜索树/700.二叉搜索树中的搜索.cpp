/*
 * @lc app=leetcode.cn id=700 lang=cpp
 *
 * [700] 二叉搜索树中的搜索
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
    TreeNode *traversal(TreeNode *node, int target)
    {
        if (node == NULL || node->val == target)
        {
            return node;
        }
        // 二叉搜索树特性
        //  对于任一节点，总是左小右大
        if (node->val > target)
        {
            return traversal(node->left, target);
        }
        else if (node->val < target)
        {
            return traversal(node->right, target);
        }
        return NULL;
    }
    TreeNode *searchBST(TreeNode *root, int val)
    {
        return traversal(root, val);
    }

    // 迭代法
    // TreeNode *searchBST(TreeNode *root, int val)
    // {
    //     while (root != NULL)
    //     {
    //         if (root->val > val)
    //         {
    //             root = root->left;
    //         }
    //         else if (root->val < val)
    //         {
    //             root = root->right;
    //         }
    //         else
    //         {
    //             return root;
    //         }
    //     }
    //     return NULL;
    // }
};
// @lc code=end
