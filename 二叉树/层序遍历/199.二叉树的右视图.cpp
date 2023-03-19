/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
    vector<int> rightSideView(TreeNode *root)
    {
        // BFS+queue后出队
        queue<TreeNode *> que;
        vector<int> ret;
        if (root == NULL)
        {
            return ret;
        }
        que.push(root);
        while (!que.empty())
        {
            int qsize = que.size();
            for (int i = 0; i < qsize; i++)
            {
                TreeNode *node = que.front();
                // 倒数最后一个节点push到ret中
                if (i == size - 1)
                {
                    ret.push_back(node->val);
                }
                que.pop();
                // 放入该节点下一层节点
                if (node->left)
                {
                    que.push(node->left);
                }
                if (node->right)
                {
                    que.push(node->right);
                }
            }
        }
        return ret;
    }
};
// @lc code=end
