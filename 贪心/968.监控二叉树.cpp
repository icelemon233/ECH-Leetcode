/*
 * @lc app=leetcode.cn id=968 lang=cpp
 *
 * [968] 监控二叉树
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
    int result = 0;
    // 节点存在三种状态（以下代码中的状态以序号代替）
    // 1. 摄像头覆盖的地方
    // 2. 摄像头不能覆盖的地方
    // 3. 摄像头自己
    int traversal(TreeNode *node)
    {
        // 叶子节点的两个空子节点设置为摄像头可覆盖，叶子节点才能被视为不能覆盖的地方，叶子节点的父节点才能设置为摄像头自己
        if (node == NULL)
        {
            return 1;
        }
        // 从下到上遍历，就是后序遍历
        int leftTree = traversal(node->left);
        int rightTree = traversal(node->right);
        // 中间节点的处理
        // 1. 存在一边的子节点为摄像头不可覆盖，那么该节点就要设置为摄像头
        if (leftTree == 2 || rightTree == 2)
        {
            result++;
            return 3;
        }
        // 2.子节点均可覆盖，这个节点设置为不可覆盖
        if (leftTree == 1 && rightTree == 1)
        {
            return 2;
        }
        // 3.子节点存在一个摄像头，这个节点设置为可覆盖
        if (leftTree == 3 || rightTree == 3)
        {
            return 1;
        }
        // 满足函数运行的返回条件，并不会执行
        return -1;
    }
    int minCameraCover(TreeNode *root)
    {
        // root没有任何子节点 或 子节点均为摄像头可覆盖，那么root就会被设置为摄像头不可覆盖，需要加一个摄像头
        if (traversal(root) == 2)
        {
            result++;
        }
        return result;
    }
};
// @lc code=end
