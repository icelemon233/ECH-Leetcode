/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    bool compare(TreeNode *left, TreeNode *right)
    {
        if (left == NULL && right != NULL)
        {
            return false;
        }
        if (left != NULL && right == NULL)
        {
            return false;
        }
        if (left == NULL && right == NULL)
        {
            return true;
        }
        if (left->val != right->val)
        {
            return false;
        }

        bool llrr = compare(left->left, right->right);
        bool lrrl = compare(left->right, right->left);
        return llrr && lrrl;
    }

    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
        {
            return true;
        }
        return compare(root->left, root->right);
    }

    // 栈解法
    // bool isSymmetric(TreeNode *root)
    // {
    //     stack<TreeNode *> st;
    //     if (root == NULL)
    //     {
    //         return true;
    //     }
    //     st.push(root->left);
    //     st.push(root->right);
    //     while (!st.empty())
    //     {
    //         TreeNode *left = st.top();
    //         st.pop();
    //         TreeNode *right = st.top();
    //         st.pop();
    //         // 如果均为空指针，继续检测余下节点
    //         if (!left && !right)
    //         {
    //             continue;
    //         }
    //         if (left == NULL && right != NULL)
    //         {
    //             return false;
    //         }
    //         if (left != NULL && right == NULL)
    //         {
    //             return false;
    //         }
    //         if (left->val != right->val)
    //         {
    //             return false;
    //         }

    //         // 左子树左边与右子树右边一组，左子树右边与右子树左边一组
    //         st.push(left->left);
    //         st.push(right->right);
    //         st.push(left->right);
    //         st.push(right->left);
    //     }
    //     return true;
    // }

    // 队列解法
    // bool isSymmetric(TreeNode *root)
    // {
    //     queue<TreeNode *> que;
    //     if (root == NULL)
    //     {
    //         return true;
    //     }
    //     que.push(root->left);
    //     que.push(root->right);
    //     while (!que.empty())
    //     {
    //         int qsize = que.size();
    //         // 注意这里一次pop两个节点，需要2个跳步
    //         for (int i = 0; i < qsize; i += 2)
    //         {
    //             TreeNode *left = que.front();
    //             que.pop();
    //             TreeNode *right = que.front();
    //             que.pop();
    //             // 如果均为空指针，继续检测余下节点
    //             if (!left && !right)
    //             {
    //                 continue;
    //             }
    //             if (left == NULL && right != NULL)
    //             {
    //                 return false;
    //             }
    //             if (left != NULL && right == NULL)
    //             {
    //                 return false;
    //             }
    //             if (left->val != right->val)
    //             {
    //                 return false;
    //             }

    //             // 左子树左边与右子树右边一组，左子树右边与右子树左边一组
    //             que.push(left->left);
    //             que.push(right->right);
    //             que.push(left->right);
    //             que.push(right->left);
    //         }
    //     }
    //     return true;
    // }
};
// @lc code=end
