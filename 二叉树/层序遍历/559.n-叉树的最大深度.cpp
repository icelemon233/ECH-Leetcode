/*
 * @lc app=leetcode.cn id=559 lang=cpp
 *
 * [559] N 叉树的最大深度
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
    // 递归法
    // int maxDepth(Node *root)
    // {
    //     // 递归法时，要用全局变量表示
    //     int depth = 0;
    //     if (root == NULL)
    //     {
    //         return depth;
    //     }
    //     for (Node *child : root->children)
    //     {
    //         // depth++;
    //         depth = max(depth, maxDepth(child));
    //     }
    //     return depth + 1;
    // }

    // 迭代法
    int maxDepth(Node *root)
    {
        queue<Node *> que;
        int depth = 0;
        if (root == NULL)
        {
            return depth;
        }
        que.push(root);
        while (!que.empty())
        {
            int qsize = que.size();
            depth++;
            for (int i = 0; i < qsize; i++)
            {
                Node *node = que.front();
                que.pop();
                for (Node *child : node->children)
                {
                    que.push(child);
                }
            }
        }
        return depth;
    }
};
// @lc code=end
