/*
 * @lc app=leetcode.cn id=669 lang=cpp
 *
 * [669] 修剪二叉搜索树
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
    // 递归法
    // TreeNode *traversal(TreeNode *node, int low, int high)
    // {
    //     if (node == NULL)
    //     {
    //         return node;
    //     }
    //     // 根据二叉树特性：左小右大
    //     // 如果比最小值还小，就要往右找符合的
    //     // 如果比最大值还大，就要往左找符合的
    //     if (node->val < low)
    //     {
    //         return traversal(node->right, low, high);
    //     }
    //     if (node->val > high)
    //     {
    //         return traversal(node->left, low, high);
    //     }
    //     node->left = traversal(node->left, low, high);
    //     node->right = traversal(node->right, low, high);
    //     return node;
    // }

    // TreeNode *trimBST(TreeNode *root, int low, int high)
    // {
    //     return traversal(root, low, high);
    // }

    // 迭代法
    TreeNode *trimBST(TreeNode *root, int low, int high)
    {
        if (root == NULL)
        {
            return NULL;
        }

        // 根据二叉树特性：左小右大
        // 如果比最小值还小，就要往右找符合的
        // 如果比最大值还大，就要往左找符合的

        // 1. 处理头节点（如果头节点都不符合要求，自然要寻找新的符合要求的头节点）
        while (root && (root->val < low || root->val > high))
        {
            if (root->val < low)
            {
                root = root->right;
            }
            else
            {
                root = root->left;
            }
        }

        // 2. 处理左孩子：如果左孩子的值比最小的还小，就要往左孩子的右孩子找符合的
        TreeNode *node = root;
        while (node)
        {
            while (node->left && node->left->val < low)
            {
                node->left = node->left->right;
            }
            node = node->left;
        }

        // 3. 处理右孩子：如果右孩子的值比最大的还大，就要往右孩子的左孩子找符合的
        // 记得重新从root开始找
        node = root;
        while (node)
        {
            while (node->right && node->right->val > high)
            {
                node->right = node->right->left;
            }
            node = node->right;
        }

        return root;
    }
};
// @lc code=end
