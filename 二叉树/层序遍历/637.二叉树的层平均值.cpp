/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
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
    vector<double> averageOfLevels(TreeNode *root)
    {
        queue<TreeNode *> que;
        vector<double> ret;
        if (root == NULL)
        {
            return ret;
        }
        que.push(root);
        while (!que.empty())
        {
            int qsize = que.size();
            double sum = 0;
            for (int i = 0; i < qsize; i++)
            {
                TreeNode *node = que.front();
                sum += node->val;
                que.pop();
                if (node->left)
                {
                    que.push(node->left);
                }
                if (node->right)
                {
                    que.push(node->right);
                }
            }
            ret.push_back(sum / qsize);
        }
        return ret;
    }
};
// @lc code=end
