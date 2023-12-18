/*
 * @lc app=leetcode.cn id=2415 lang=cpp
 *
 * [2415] 反转二叉树的奇数层
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
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
    TreeNode *reverseOddLevels(TreeNode *root)
    {
        // 层序遍历（队列方法）
        queue<TreeNode *> que;
        que.emplace(root);
        bool isOdd = false;    //记录本层是否是奇数层
        while (!que.empty())
        {
            int nodeNum = que.size();
            vector<TreeNode *> vec;    // 记录奇数层的节点
            for (int i = 0; i < nodeNum; ++i)
            {
                TreeNode *node = que.front();
                que.pop();
                if (isOdd)
                {
                    vec.push_back(node);
                }
                //由于为完美二叉树，只需要判断左边或右边是否有子节点即可
                if (node->left)
                {
                    que.push(node->left);
                    que.push(node->right);
                }
            }
            if (isOdd)
            {
                // 反转第一个和最后一个，接着是第二个和倒数第二个，以此类推就是相当于按顺序反转
                for (int i = 0, j = vec.size() - 1; i < j; ++i, --j)
                {
                    swap(vec[i]->val, vec[j]->val);
                }
            }
            isOdd = !isOdd;
        }
        return root;
    }
};

// @lc code=end
