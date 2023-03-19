/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
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
    // 迭代法
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        // 核心思想：队列先进先出，把当前节点入队，队列非空时排空，再放左右孩子入队
        queue<TreeNode *> que;
        vector<vector<int>> ret;
        if (root == NULL)
        {
            return ret;
        }
        que.push(root);
        while (!que.empty())
        {
            int qsize = que.size();
            vector<int> nowLevel;
            for (int i = 0; i < qsize; i++)
            {
                TreeNode *node = que.front();
                nowLevel.push_back(node->val);
                if (node->left)
                {
                    que.push(node->left);
                }
                if (node->right)
                {
                    que.push(node->right);
                }
                que.pop();
            }
            ret.push_back(nowLevel);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
// @lc code=end
