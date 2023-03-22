/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    // 前序遍历法：中左右
    // public:
    //     bool traversal(TreeNode *node, long left, long right)
    //     {
    //         if (node == NULL)
    //             return true;
    //         // 首层满足条件：左小右大
    //         // 且接下来的左右子树也满足条件
    //         // 左子树：最大不超过root->val
    //         // 右子树：最小不超过root->val
    //         return left < node->val && node->val < right &&
    //                traversal(node->left, left, node->val) &&
    //                traversal(node->right, node->val, right);
    //     }

    //     bool isValidBST(TreeNode *root)
    //     {
    //         long left = LONG_MIN;
    //         long right = LONG_MAX;
    //         return traversal(root, left, right);
    //     }

    // 中序遍历法：左中右三
private:
    TreeNode *pre = NULL; // 用来记录前一个节点
public:
    bool traversal(TreeNode *node)
    {
        if (node == NULL)
        {
            return true;
        }
        bool left = traversal(node->left);
        // 判断当前节点是否大于中序遍历的前一个节点
        // 利用特性：二叉搜索树的中序遍历是单调升序
        if (pre != NULL && pre->val >= node->val)
        {
            return false;
        }
        pre = node;
        bool right = traversal(node->right);
        return left && right;
    }
    bool isValidBST(TreeNode *root)
    {
        return traversal(root);
    }

    // 后序遍历法：左右中
    // 思想较难理解，待补充
    //     pair<long, long> dfs(TreeNode *node)
    //     {
    //         if (node == NULL)
    //             return {LONG_MAX, LONG_MIN};
    //         auto [l_min, l_max] = dfs(node->left);
    //         auto [r_min, r_max] = dfs(node->right);
    //         if (node->val <= l_max || node->val >= r_min)
    //             return {LONG_MIN, LONG_MAX};
    //         return {min(l_min, x), max(r_max, x)};
    //     }

    // public:
    //     bool isValidBST(TreeNode *root)
    //     {
    //         return dfs(root).second != LONG_MAX;
    //     }
};
// @lc code=end
