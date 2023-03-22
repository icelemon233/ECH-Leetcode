/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    // TreeNode *traversal(vector<int> &preorder, vector<int> &inorder)
    // {
    //     // 0. 如果得出来的preorder/inorder为空（他们两个一定是同时为空的）
    //     // 证明这一边的子树已经空掉了，可以返回NULL
    //     if (preorder.size() == 0 || inorder.size() == 0)
    //     {
    //         return NULL;
    //     }

    //     // 1. 先序遍历最后一个数字一定是root节点
    //     int rootValue = preorder[0];
    //     TreeNode *root = new TreeNode(rootValue);

    //     // 2. 根据postorder是否被切割完毕判断是否是叶子节点，从而结束递归
    //     if (preorder.size() == 1)
    //     {
    //         return root;
    //     }

    //     // 3. 在中序遍历找到上面找出来的中间节点
    //     int delimiterIndex;
    //     for (delimiterIndex = 0; delimiterIndex < inorder.size(); delimiterIndex++)
    //     {
    //         if (inorder[delimiterIndex] == rootValue)
    //         {
    //             break;
    //         }
    //     }

    //     // 4. 切割中序数组，得到 中序左数组（左子树） 和 中序右数组（右子树）
    //     // 左闭右开原则，下同
    //     vector<int> leftInorder(inorder.begin(), inorder.begin() + delimiterIndex);
    //     vector<int> rightInorder(inorder.begin() + delimiterIndex + 1, inorder.end());
    //     // 5. 切割先序数组，得到 先序左数组（左子树） 和 先序右数组（右子树）
    //     // 先序遍历是中左右，右子树部分一定与中序所切出来的右子树部分大小/数值相同
    //     // 记得先序遍历第一个节点是root节点，不需要了
    //     vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + inorder.size() - rightInorder.size());
    //     vector<int> rightPreorder(preorder.begin() + inorder.size() - rightInorder.size(), preorder.end());

    //     // 6. 递归
    //     root->left = traversal(leftPreorder, leftInorder);
    //     root->right = traversal(rightPreorder, rightInorder);

    //     return root;
    // }

    // 优化vector为下标版本
    TreeNode *traversal(vector<int> &preorder, int preorderBegin, int preorderEnd, vector<int> &inorder, int inorderBegin, int inorderEnd)
    {
        // 0. 如果得出来的postorderBegin与postorderBegin相等（inorderBegin和inorderEnd同理）
        // 证明这一边的子树已经空掉了，可以返回NULL
        if (preorderBegin == preorderEnd)
        {
            return NULL;
        }

        // 1. 后序遍历最后一个数字一定是root节点
        int rootValue = preorder[preorderBegin];
        TreeNode *root = new TreeNode(rootValue);

        // 2. 根据preorder是否被切割完毕判断是否是叶子节点，从而结束递归
        if (preorderEnd - preorderBegin == 1)
        {
            return root;
        }

        // 3. 在中序遍历找到上面找出来的中间节点
        int delimiterIndex;
        for (delimiterIndex = inorderBegin; delimiterIndex < inorder.size(); delimiterIndex++)
        {
            if (inorder[delimiterIndex] == rootValue)
            {
                break;
            }
        }

        // 4. 切割中序数组，得到 中序左数组（左子树） 和 中序右数组（右子树）
        // 左闭右开原则，下同
        int leftInorderBegin = inorderBegin;
        int leftInorderEnd = delimiterIndex;
        int rightInorderBegin = delimiterIndex + 1;
        int rightInorderEnd = inorderEnd;

        // 5. 切割先序数组，得到 先序左数组（左子树） 和 先序右数组（右子树）
        // 先序遍历是中左右，右子树部分一定与中序所切出来的右子树部分大小/数值相同
        // 记得先序遍历第一个节点是root节点，不需要了
        int leftPreorderBegin = preorderBegin + 1;
        int leftPreorderEnd = preorderBegin + 1 + leftInorderEnd - leftInorderBegin;
        int rightPreorderBegin = leftPreorderEnd;
        int rightPreorderEnd = preorderEnd;

        // 6. 递归
        root->left = traversal(preorder, leftPreorderBegin, leftPreorderEnd, inorder, leftInorderBegin, leftInorderEnd);
        root->right = traversal(preorder, rightPreorderBegin, rightPreorderEnd, inorder, rightInorderBegin, rightInorderEnd);

        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (preorder.size() == 0 || inorder.size() == 0)
        {
            return NULL;
        }
        // return traversal(preorder, inorder);
        return traversal(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
};
// @lc code=end
