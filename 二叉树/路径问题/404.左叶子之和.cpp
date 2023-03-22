/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
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
        int leftValue = traversal(node->left);
        if (node->left != NULL && node->left->left == NULL && node->left->right == NULL)
        {
            leftValue = node->left->val;
        }
        int rightValue = traversal(node->right);
        return leftValue + rightValue;
    }
    int sumOfLeftLeaves(TreeNode *root)
    {
        return traversal(root);
    }

    // 迭代法
    // int sumOfLeftLeaves(TreeNode *root)
    // {
    //     stack<TreeNode *> st;
    //     if (root == NULL)
    //     {
    //         return 0;
    //     }
    //     st.push(root);
    //     int leftLeavesSum = 0;
    //     while (!st.empty())
    //     {
    //         TreeNode *node = st.top();
    //         if (node->left != NULL && node->left->left == NULL && node->left->right == NULL)
    //         {
    //             leftLeavesSum += node->left->val;
    //         }
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
    //     return leftLeavesSum;
    // }
};
// @lc code=end
