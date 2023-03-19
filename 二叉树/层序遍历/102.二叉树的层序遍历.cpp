/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    // 递归法（推荐迭代法）
    // void traversal(TreeNode *node, vector<vector<int>> &vec, int depth)
    // {
    //     if (node == NULL)
    //     {
    //         return;
    //     }
    //     // 每次进入新的层，都要创建vec[depth]这一层，否则后面push_back报错
    //     if (vec.size() == depth)
    //     {
    //         vec.push_back(vector<int>());
    //     }
    //     vec[depth].push_back(node->val);        // 中
    //     traversal(node->left, vec, depth + 1);  // 左
    //     traversal(node->right, vec, depth + 1); // 右
    // }
    // vector<vector<int>> levelOrder(TreeNode *root)
    // {
    //     vector<vector<int>> ret;
    //     int depth = 0;
    //     // 需要设置一个depth，便于每一层放入对应的ret[depth]
    //     traversal(root, ret, depth);
    //     return ret;
    // }

    // 迭代法
    vector<vector<int>> levelOrder(TreeNode *root)
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
        return ret;
    }
};
// @lc code=end
