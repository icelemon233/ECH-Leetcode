/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    // 二叉搜索树中，从上往下遍历，一旦出现两个指定节点之内的值，就可以直接判定为他们的最近公共祖先
    // 原理：二叉搜索树有序，左小右大
    TreeNode *traversal(TreeNode *node, TreeNode *p, TreeNode *q)
    {
        if (node == NULL)
        {
            return NULL;
        }
        if (node->val >= p->val && node->val <= q->val)
        {
            return node;
        }
        if (node->val > q->val)
        {
            return traversal(node->left, p, q);
        }
        if (node->val < p->val)
        {
            return traversal(node->right, p, q);
        }
        return NULL;
    }
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // 调整为p较小，q较大
        if (p->val > q->val)
        {
            swap(p, q);
        }
        return traversal(root, p, q);
    }

    // 另一种递归方式
    // TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    // {
    //     if (root->val > p->val && root->val > q->val)
    //     {
    //         return lowestCommonAncestor(root->left, p, q);
    //     }
    //     else if (root->val < p->val && root->val < q->val)
    //     {
    //         return lowestCommonAncestor(root->right, p, q);
    //     }
    //     else
    //         return root;
    // }

    // 迭代法
    // TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    // {
    //     while (root)
    //     {
    //         if (root->val > p->val && root->val > q->val)
    //         {
    //             root = root->left;
    //         }
    //         else if (root->val < p->val && root->val < q->val)
    //         {
    //             root = root->right;
    //         }
    //         else
    //             return root;
    //     }
    //     return NULL;
    // }
};
// @lc code=end
