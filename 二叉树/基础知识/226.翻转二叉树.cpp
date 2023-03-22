/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
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
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == NULL)
        {
            return root;
        }
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }

    // 迭代法(前序遍历)
    // TreeNode *invertTree(TreeNode *root)
    // {
    //     stack<TreeNode *> st;
    //     if (root == NULL)
    //     {
    //         return root;
    //     }
    //     st.push(root);
    //     while (!st.empty())
    //     {
    //         TreeNode *node = st.top();
    //         swap(node->left, node->right);
    //         st.pop();
    //         if (node->left)
    //         {
    //             st.push(node->left);
    //         }
    //         if (node->right)
    //         {
    //             st.push(node->right);
    //         }
    //     }
    //     return root;
    // }

    // 迭代法（层序遍历）
    // TreeNode *invertTree(TreeNode *root)
    // {
    //     queue<TreeNode *> que;
    //     if (root == NULL)
    //     {
    //         return root;
    //     }
    //     que.push(root);
    //     while (!que.empty())
    //     {
    //         int qsize = que.size();
    //         for (int i = 0; i < qsize; i++)
    //         {
    //             TreeNode *node = que.front();
    //             swap(node->left, node->right);
    //             que.pop();
    //             if (node->left)
    //             {
    //                 que.push(node->left);
    //             }
    //             if (node->right)
    //             {
    //                 que.push(node->right);
    //             }
    //         }
    //     }
    //     return root;
    // }
};
// @lc code=end
