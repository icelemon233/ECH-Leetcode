/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    // void traversal(TreeNode *node, vector<int> &vec)
    // {
    //     // 后序：左右中顺序
    //     if (node == NULL)
    //     {
    //         return;
    //     }
    //     traversal(node->left, vec);  // 左
    //     traversal(node->right, vec); // 右
    //     vec.push_back(node->val);    // 中
    // }
    // vector<int> postorderTraversal(TreeNode *root)
    // {
    //     vector<int> ret;
    //     traversal(root, ret);
    //     return ret;
    // }

    // 迭代法1
    // 前序遍历是中左右，换成中右左，再调换结果顺序，就是后序遍历的左右中
    // vector<int> postorderTraversal(TreeNode *root)
    // {
    //     vector<int> ret;
    //     stack<TreeNode *> st;
    //     if (root == NULL)
    //     {
    //         return ret;
    //     }
    //     st.push(root);
    //     while (!st.empty())
    //     {
    //         TreeNode *node = st.top();
    //         ret.push_back(node->val);
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
    //     reverse(ret.begin(), ret.end());
    //     return ret;
    // }
};
// @lc code=end
