/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
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
private:
    // 递归法和迭代法都需要
    int pre = 0;

public:
    // 递归法
    void traversal(TreeNode *node)
    {
        if (node == NULL)
            return;
        traversal(node->right);
        node->val += pre;
        pre = node->val;
        traversal(node->left);
    }

    // 反先序遍历：右中左
    TreeNode *convertBST(TreeNode *root)
    {
        traversal(root);
        return root;
    }

    // 迭代法
    // TreeNode *convertBST(TreeNode *root)
    // {
    //     stack<TreeNode *> st;
    //     if (root == NULL)
    //     {
    //         return root;
    //     }
    //     TreeNode *cur = root;
    //     while (cur || !st.empty())
    //     {
    //         if (cur)
    //         {
    //             st.push(cur);
    //             cur = cur->right;
    //         }
    //         else
    //         {
    //             cur = st.top(); // 中
    //             st.pop();
    //             cur->val += pre;
    //             pre = cur->val;
    //             cur = cur->left; // 左
    //         }
    //     }
    //     return root;
    // }
};
// @lc code=end
