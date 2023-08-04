/*
 * @lc app=leetcode.cn id=701 lang=cpp
 *
 * [701] 二叉搜索树中的插入操作
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
    TreeNode *traversal(TreeNode *node, int val)
    {
        if (node == NULL)
        {
            TreeNode *newNode = new TreeNode(val);
            return newNode;
        }
        if (node->val > val)
        {
            node->left = traversal(node->left, val);
        }
        if (node->val < val)
        {
            node->right = traversal(node->right, val);
        }
        return node;
    }
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        return traversal(root, val);
    }

    // 迭代法
    // TreeNode *insertIntoBST(TreeNode *root, int val)
    // {
    //     // 如果树为空，直接新建一个树
    //     if (root == NULL)
    //     {
    //         TreeNode *newNode = new TreeNode(val);
    //         return newNode;
    //     }
    //     TreeNode *parent = NULL;
    //     TreeNode *node = root;
    //     while (node)
    //     {
    //         parent = node;
    //         if (node->val > val)
    //         {
    //             node = node->left;
    //         }
    //         else
    //         {
    //             node = node->right;
    //         }
    //     }
    //     // while结束时一定是找到位置了，且上一节点就是parent
    //     TreeNode *newNode = new TreeNode(val);
    //     if (val < parent->val)
    //     {

    //         parent->left = newNode;
    //     }
    //     else
    //     {
    //         parent->right = newNode;
    //     }
    //     return root;
    // }
};
// @lc code=end
