/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N 叉树的层序遍历
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution
{
public:
    vector<vector<int>> levelOrder(Node *root)
    {
        queue<Node *> que;
        vector<vector<int>> ret;
        if (root == NULL)
        {
            return ret;
        }
        que.push(root);
        while (!que.empty())
        {
            int qsize = que.size();
            vector<int> nowLevel;
            for (int i = 0; i < qsize; i++)
            {
                Node *node = que.front();
                nowLevel.push_back(node->val);
                que.pop();
                // 对于题目所设定的n叉树，node->children以node*方式保存
                for (Node *child : node->children)
                {
                    que.push(child);
                }
            }
            ret.push_back(nowLevel);
        }
        return ret;
    }
};
// @lc code=end
