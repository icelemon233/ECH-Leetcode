/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    bool ret = false;

public:
    void traversal(TreeNode *node, vector<int> &path, int targetSum)
    {
        if (node == NULL)
        {
            return;
        }
        path.push_back(node->val);
        // 到了叶子节点的时候停下，整理路径
        if (node->left == NULL && node->right == NULL)
        {
            int sum = 0;
            // 到path.size() - 1就要停下，最后一个数字手动再push一次，不然就会出现末尾多出一个"->"的情况
            for (int i = 0; i < path.size(); i++)
            {
                sum += path[i];
            }
            if (sum == targetSum)
            {
                ret = true;
            }
        }
        if (node->left)
        {
            traversal(node->left, path, targetSum);
            path.pop_back();
        }
        if (node->right)
        {
            traversal(node->right, path, targetSum);
            path.pop_back();
        }
    }
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        vector<int> path;
        traversal(root, path, targetSum);
        return ret;
    }
};
// @lc code=end
