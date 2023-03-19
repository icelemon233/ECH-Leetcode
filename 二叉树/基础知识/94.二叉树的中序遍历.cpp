/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    void traversal(TreeNode *node, vector<int> &vec)
    {
        // 中序：左中右顺序
        if (node == NULL)
        {
            return;
        }
        traversal(node->left, vec);  // 左
        vec.push_back(node->val);    // 中
        traversal(node->right, vec); // 右
    }
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ret;
        traversal(root, ret);
        return ret;
    }

    // 迭代法
    // vector<int> inorderTraversal(TreeNode *root)
    // {
    //     vector<int> ret;
    //     stack<TreeNode *> st;
    //     // 中序：左中右顺序
    //     // 需要多加一个指针来控制先输出左节点
    //     // 此时不需要往栈里提前push一个root
    //     TreeNode *cur = root;
    //     while (cur != NULL || !st.empty())
    //     {
    //         // 非空证明还没到最左节点
    //         if (cur != NULL)
    //         {
    //             st.push(cur);
    //             // 往左探
    //             cur = cur->left;
    //         }
    //         else
    //         {
    //             // 让指针返回到上一层，也就是栈的顶端
    //             cur = st.top();
    //             // 注：这里最先找到的是最底下的叶子节点，再后面是左子树的中间节点，再后面才是右边节点
    //             ret.push_back(cur->val);
    //             st.pop();
    //             // 往右探
    //             cur = cur->right;
    //         }
    //     }
    //     return ret;
    // }
};
// @lc code=end
