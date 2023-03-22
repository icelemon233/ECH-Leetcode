/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
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
    // 递归法
    // private:
    //     int maxDepth = INT_MIN;
    //     int ret = 0;

    // public:
    //     void traversal(TreeNode *node, int depth)
    //     {
    //         if (node == NULL)
    //         {
    //             return;
    //         }
    //         if (node->left == NULL && node->right == NULL)
    //         {
    //             if (depth > maxDepth)
    //             {
    //                 maxDepth = depth;
    //                 ret = node->val;
    //             }
    //             return;
    //         }
    //         traversal(node->left, depth + 1);
    //         traversal(node->right, depth + 1);
    //     }
    //     int findBottomLeftValue(TreeNode *root)
    //     {
    //         traversal(root, 0);
    //         return ret;
    //     }

    // 遍历法
public:
    int findBottomLeftValue(TreeNode *root)
    {
        queue<TreeNode *> que;
        int depth = 0;
        if (root == NULL)
        {
            return depth;
        }
        que.push(root);
        int ret = 0;
        while (!que.empty())
        {
            int qsize = que.size();
            for (int i = 0; i < qsize; i++)
            {
                TreeNode *node = que.front();
                // 每一次的第一个都记录，最后返回的一定是最后一层的第一个
                if (i == 0)
                {
                    ret = node->val;
                }
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
        }
        return ret;
    }
};

// @lc code=end
