/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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
    TreeNode *traversal(vector<int> &nums)
    {
        // 0. 当nums为空，说明下面没有子树了，返回NULL
        if (nums.size() == 0)
        {
            return NULL;
        }

        // 1. 找到最大值
        //  数组中最小值是0，所以这里设置为-1
        int maxNum = -1;
        int maxNumIndex = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > maxNum)
            {
                maxNum = nums[i];
                maxNumIndex = i;
            }
        }

        // 2. 找到最大值后，建立root节点，左边是左子树，右边是右子树
        TreeNode *root = new TreeNode(maxNum);

        // 3. 如果nums只剩下一个值，说明这里只剩下一个没有左右子树的root节点了，可以直接返回
        if (nums.size() == 1)
        {
            return root;
        }

        vector<int> leftMaxTree(nums.begin(), nums.begin() + maxNumIndex);
        vector<int> rightMaxTree(nums.begin() + maxNumIndex + 1, nums.end());

        // 开始递归
        root->left = traversal(leftMaxTree);
        root->right = traversal(rightMaxTree);

        return root;
    }
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        return traversal(nums);
    }
};
// @lc code=end
