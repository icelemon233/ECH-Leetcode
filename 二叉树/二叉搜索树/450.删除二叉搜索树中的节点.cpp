/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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
    TreeNode *traversal(TreeNode *node, int key)
    {

        if (node == NULL)
        {
            return node;
        }
        // 找到节点且需要删除的4种情况
        // 1. 左右孩子均为空，直接返回NULL为根节点
        // 2. 左孩子为空右孩子不为空，返回右孩子补位
        // 3. 右孩子为空左孩子不为空，返回左孩子补位
        // 4. 左右孩子均不为空，有两种选择
        // 4.1 左孩子补位顶上，右孩子接到以左孩子为根节点的子树的最右边节点
        // 4.2 右孩子补位顶上，左孩子接到以右孩子为根节点的子树的最左边节点
        if (node->val == key)
        {
            if (!node->left && !node->right)
            {
                return NULL;
            }
            else if (!node->left)
            {
                TreeNode *newNode = node->right;
                delete node;
                return newNode;
            }
            else if (!node->right)
            {
                TreeNode *newNode = node->left;
                delete node;
                return newNode;
            }
            else
            {
                // 左边顶上的例子
                TreeNode *newNode = node->left;
                // 找左子树的最右边节点
                TreeNode *cur = newNode;
                while (cur->right)
                {
                    cur = cur->right;
                }
                // 原节点的右子树接到这个最右边节点上
                cur->right = node->right;
                return newNode;

                // // 右边顶上的例子
                // TreeNode *newNode = node->right;
                // // 找右子树的最左边节点
                // TreeNode *cur = newNode;
                // while (cur->left)
                // {
                //     cur = cur->left;
                // }
                // // 原节点的左子树接到这个最左边节点上
                // cur->left = node->left;
                // return newNode;
            }
        }
        if (key < node->val)
        {
            node->left = traversal(node->left, key);
        }
        if (key > node->val)
        {
            node->right = traversal(node->right, key);
        }
        return node;
    }
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        return traversal(root, key);
    }
};
// @lc code=end
