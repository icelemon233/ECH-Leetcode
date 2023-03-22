/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    // 由题意，自底向上自然使用后序遍历
    //  由于节点一定出现且值唯一，那么可以有以下规则：
    //  如果p和q出现在某个节点，节点回传到祖先节点时就直接回传p/q的值，说明p和q出现在“我”这棵子树上
    //  如果没有出现p和q出现在某个节点，节点回传到祖先节点时就直接回传NULL，说明p和q没有出现在“我”这棵子树上
    TreeNode *traversal(TreeNode *node, TreeNode *p, TreeNode *q)
    {
        // 如果节点为空或节点不是p和q，都回传NULL
        if (node == p || node == q || node == NULL)
        {
            return node;
        }

        // 后序遍历
        TreeNode *leftTree = traversal(node->left, p, q);
        TreeNode *rightTree = traversal(node->right, p, q);
        // 如果左右子树返回都不为空，证明p和q分属两边，最近公共祖先就是最原本的root
        if (leftTree && rightTree)
        {
            return node;
        }
        // 如果任一子树不为空，证明p和q在同一边，最近公共祖先就在那一边找
        if (leftTree && !rightTree)
        {
            return leftTree;
        }
        if (!leftTree && rightTree)
        {
            return rightTree;
        }
        // 如果左右子树均为空，随便返回一个都可以
        return leftTree;
    }
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        return traversal(root, p, q);
    }
};
// @lc code=end
