/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
public:
    Node *connect(Node *root)
    {
        queue<Node *> que;
        vector<int> ret;
        if (root == NULL)
        {
            return root;
        }
        que.push(root);
        while (!que.empty())
        {
            int qsize = que.size();
            Node *lastNode;
            for (int i = 0; i < qsize; i++)
            {
                Node *node = que.front();
                if (i == 0)
                {
                    lastNode = node;
                }
                else
                {
                    lastNode->next = node;
                    lastNode = node;
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
        return root;
    }
};
// @lc code=end
