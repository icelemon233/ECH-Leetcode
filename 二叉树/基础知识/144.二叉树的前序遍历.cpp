/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
    void traversal(TreeNode *node, vector<int> &vec)
    {
        // 前序：中左右顺序
        if (node == NULL)
        {
            return;
        }
        vec.push_back(node->val);    // 中
        traversal(node->left, vec);  // 左
        traversal(node->right, vec); // 右
    }
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ret;
        traversal(root, ret);
        return ret;
    }

    // 迭代法
    // vector<int> preorderTraversal(TreeNode *root)
    // {
    //     vector<int> ret;
    //     stack<TreeNode *> st;
    //     if (root == NULL)
    //     {
    //         return ret;
    //     }
    //     // 前序：中左右顺序
    //     st.push(root);
    //     while (!st.empty())
    //     {
    //         TreeNode *node = st.top();
    //         st.pop();
    //         ret.push_back(node->val);
    //         // 注意入栈顺序先右后左，pop结果才是先左右后
    //         if (node->right)
    //         {
    //             st.push(node->right);
    //         }
    //         if (node->left)
    //         {
    //             st.push(node->left);
    //         }
    //     }
    //     return ret;
    // }
};
// @lc code=end
