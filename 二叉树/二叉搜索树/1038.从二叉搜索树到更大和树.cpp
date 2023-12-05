/*
 * @lc app=leetcode.cn id=1038 lang=cpp
 *
 * [1038] 从二叉搜索树到更大和树
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
    int sum = 0;

public:
    // 遍历顺序：右、中、左
    void traversal(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }

        traversal(root->right);

        // 按遍历顺序计算元素和即可
        sum += root->val;
        root->val = sum;

        traversal(root->left);
    }
    TreeNode *bstToGst(TreeNode *root)
    {
        traversal(root);
        return root;
    }
};
// @lc code=end
