/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
    //     unordered_map<int, int> map;
    //     // 提前定义排序：较大的放前面
    //     bool static compare(const pair<int, int> &a, const pair<int, int> &b)
    //     {
    //         return a.second > b.second; // 按照频率从大到小排序
    //     }

    // public:
    //     void treeToVector(TreeNode *node)
    //     {
    //         if (node == NULL)
    //         {
    //             return;
    //         }
    //         map[node->val]++;
    //         treeToVector(node->left);
    //         treeToVector(node->right);
    //     }
    //     vector<int> findMode(TreeNode *root)
    //     {
    //         if (root == NULL)
    //         {
    //             return {};
    //         }

    //         treeToVector(root);
    //         vector<pair<int, int>> vec(map.begin(), map.end());
    //         sort(vec.begin(), vec.end(), compare);
    //         vector<int> ret;
    //         ret.push_back(vec[0].first);
    //         for (int i = 1; i < vec.size(); i++)
    //         {
    //             if (vec[i].second == vec[0].second)
    //             {
    //                 ret.push_back(vec[i].first);
    //             }
    //             else
    //             {
    //                 break;
    //             }
    //         }
    //         return ret;
    //     }

    // 递归法
    // 二叉搜索树的中序遍历一定是单调升序
    // 所以遇到不同的数只要重新算一遍出现次数
    // 就能得到众数
private:
    int count = 0;
    int maxCount = 0;
    TreeNode *pre;
    vector<int> ret;

public:
    void traversal(TreeNode *node)
    {
        if (node == NULL)
        {
            return;
        }
        traversal(node->left);
        // 第一个节点
        if (pre == NULL)
        {
            count = 1;
        }
        // 与前一个节点数值相同，继续计算
        else if (pre->val == node->val)
        {
            count++;
        }
        // 遇到一个新的数，重新计算
        else
        {
            count = 1;
        }
        // 更新上一个节点
        pre = node;
        // 如果和最大值相同，放进result中
        if (count == maxCount)
        {
            ret.push_back(node->val);
        }
        // 如果count大于maxCount，则需要把maxCount更新一下，同时把之前ret的结果都删掉（因为都比现在这个数的出现次数小了）
        if (count > maxCount)
        {
            maxCount = count;
            ret.clear();
            ret.push_back(node->val);
        }
        traversal(node->right);
    }

    vector<int> findMode(TreeNode *root)
    {
        if (root == NULL)
        {
            return {};
        }
        traversal(root);
        return ret;
    }
};
// @lc code=end
