/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
    void traversal(TreeNode *node, vector<int> &path, vector<string> &ret)
    {
        path.push_back(node->val);
        // 到了叶子节点的时候停下，整理路径
        if (node->left == NULL && node->right == NULL)
        {
            string s;
            // 到path.size() - 1就要停下，最后一个数字手动再push一次，不然就会出现末尾多出一个"->"的情况
            for (int i = 0; i < path.size() - 1; i++)
            {
                s += to_string(path[i]);
                s += "->";
            }
            s += to_string(path[path.size() - 1]);
            ret.push_back(s);
        }
        if (node->left)
        {
            traversal(node->left, path, ret);
            path.pop_back();
        }
        if (node->right)
        {
            traversal(node->right, path, ret);
            path.pop_back();
        }
    }
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<int> path;
        vector<string> ret;
        traversal(root, path, ret);
        return ret;
    }
};
// @lc code=end
