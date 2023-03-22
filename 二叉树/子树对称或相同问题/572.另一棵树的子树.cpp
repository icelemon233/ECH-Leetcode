/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一棵树的子树
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
    // 层序遍历root，遇到与subRoot的第一个节点值相同的节点，用递归方法检查是否为子树
    bool isSametree(TreeNode *node, TreeNode *subNode)
    {
        if (node != NULL && subNode == NULL)
        {
            return false;
        }
        if (node == NULL && subNode != NULL)
        {
            return false;
        }
        if (node == NULL && subNode == NULL)
        {
            return true;
        }
        if (node->val != subNode->val)
        {
            return false;
        }
        bool isLeftSame = isSametree(node->left, subNode->left);
        bool isRightSame = isSametree(node->right, subNode->right);
        return isLeftSame && isRightSame;
    }

    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        queue<TreeNode *> que;
        bool ret = false;
        if (root == NULL)
        {
            return false;
        }
        que.push(root);
        while (!que.empty())
        {
            int qsize = que.size();
            for (int i = 0; i < qsize; i++)
            {
                TreeNode *node = que.front();
                if (node->val == subRoot->val)
                {
                    ret = isSametree(node, subRoot);
                    if (ret)
                    {
                        return true;
                    }
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

    // // 另一种简短的代码，即递归法
    // bool isSubtree(TreeNode *root, TreeNode *subRoot)
    // {
    //     // 主树root遍历完毕，没有匹配的
    //     if (root == null)
    //     {
    //         return false;
    //     }
    //     return isSameTree(root, subRoot) || isSubtree(root.left, t) || isSubtree(root.right, subRoot);
    // }
};
// @lc code=end
