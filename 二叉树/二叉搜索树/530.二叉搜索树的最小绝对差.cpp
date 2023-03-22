/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
    // 数组转换法
    // private:
    //     vector<int> vec;

    // public:
    //     void treeToVector(TreeNode *node)
    //     {
    //         if (node == NULL)
    //         {
    //             return;
    //         }
    //         treeToVector(node->left);
    //         vec.push_back(node->val);
    //         treeToVector(node->right);
    //     }
    //     int getMinimumDifference(TreeNode *root)
    //     {
    //         int ret = INT_MAX;
    //         treeToVector(root);
    //         if (vec.size() < 2)
    //         {
    //             return 0;
    //         }
    //         for (int i = 0; i < vec.size() - 1; i++)
    //         {
    //             ret = min(ret, vec[i + 1] - vec[i]);
    //         }
    //         return ret;
    //     }

    // 中序递归法
private:
    int ret = INT_MAX;
    TreeNode *pre;

public:
    void traversal(TreeNode *node)
    {
        if (node == NULL)
        {
            return;
        }
        traversal(node->left);
        if (pre != NULL)
        {
            ret = min(ret, abs(pre->val - node->val));
        }
        pre = node;
        traversal(node->right);
    }
    int getMinimumDifference(TreeNode *root)
    {
        traversal(root);
        return ret;
    }

    // 迭代法（实际上就是中序遍历的迭代法）
    // public:
    //     int getMinimumDifference(TreeNode *root)
    //     {
    //         stack<TreeNode *> st;
    //         int ret = INT_MAX;
    //         if (root == NULL)
    //         {
    //             return 0;
    //         }
    //         // 中序遍历的上一个节点
    //         TreeNode *pre = NULL;
    //         // 需要多加一个指针来控制先输出左节点
    //         TreeNode *cur = root;
    //         while (cur != NULL || !st.empty())
    //         {
    //             if (cur != NULL)
    //             {
    //                 st.push(cur);
    //                 cur = cur->left;
    //             }
    //             else
    //             {
    //                 cur = st.top();
    //                 if (pre != NULL)
    //                 {
    //                     // 中序遍历的cur的值一定比pre大
    //                     ret = min(ret, cur->val - pre->val);
    //                 }
    //                 pre = cur;
    //                 st.pop();
    //                 cur = cur->right;
    //             }
    //         }
    //         return ret;
    //     }
};
// @lc code=end
