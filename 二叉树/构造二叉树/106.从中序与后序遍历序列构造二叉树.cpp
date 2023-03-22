/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    // TreeNode *traversal(vector<int> &inorder, vector<int> &postorder)
    // {
    //     // 0. 如果得出来的inorder/postorder为空（他们两个一定是同时为空的）
    //     // 证明这一边的子树已经空掉了，可以返回NULL
    //     if (inorder.size() == 0 || postorder.size() == 0)
    //     {
    //         return NULL;
    //     }

    //     // 1. 后序遍历最后一个数字一定是root节点
    //     int rootValue = postorder[postorder.size() - 1];
    //     TreeNode *root = new TreeNode(rootValue);

    //     // 2. 由于后序遍历最终是中间节点，所以根据postorder是否被切割完毕判断是否是叶子节点，从而结束递归
    //     if (postorder.size() == 1)
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
    //     // 5. 切割后序数组，得到 后序左数组（左子树） 和 后序右数组（右子树）
    //     // 后序遍历是左右中，左子树部分一定与中序所切出来的左子树部分大小/数值相同
    //     // 记得后序遍历最后一个节点是root节点，不需要了
    //     // postorder.end() - 1是错误的！！！
    //     postorder.resize(postorder.size() - 1);
    //     vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());
    //     vector<int> rightPostorder(postorder.begin() + leftInorder.size(), postorder.end());

    //     // 6. 递归
    //     root->left = traversal(leftInorder, leftPostorder);
    //     root->right = traversal(rightInorder, rightPostorder);

    //     return root;
    // }

    // 优化vector为下标版本
    TreeNode *traversal(vector<int> &inorder, int inorderBegin, int inorderEnd, vector<int> &postorder, int postorderBegin, int postorderEnd)
    {
        // 0. 如果得出来的postorderBegin与postorderBegin相等（inorderBegin和inorderEnd同理）
        // 证明这一边的子树已经空掉了，可以返回NULL
        if (postorderBegin == postorderEnd)
        {
            return NULL;
        }

        // 1. 后序遍历最后一个数字一定是root节点
        int rootValue = postorder[postorderEnd - 1];
        TreeNode *root = new TreeNode(rootValue);

        // 2. 由于后序遍历最终是中间节点，所以根据postorder是否被切割完毕判断是否是叶子节点，从而结束递归
        if (postorderEnd - postorderBegin == 1)
        {
            return root;
        }

        // 3. 在中序遍历找到上面找出来的中间节点
        int delimiterIndex;
        for (delimiterIndex = 0; delimiterIndex < inorder.size(); delimiterIndex++)
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

        // 5. 切割后序数组，得到 后序左数组（左子树） 和 后序右数组（右子树）
        // 后序遍历是左右中，左子树部分一定与中序所切出来的左子树部分大小/数值相同
        // 记得后序遍历最后一个节点是root节点，不需要了
        int leftPostorderBegin = postorderBegin;
        int leftPostorderEnd = postorderBegin + leftInorderEnd - leftInorderBegin;
        int rightPostorderBegin = leftPostorderEnd;
        int rightPostorderEnd = postorderEnd - 1;

        // 6. 递归
        root->left = traversal(inorder, leftInorderBegin, leftInorderEnd, postorder, leftPostorderBegin, leftPostorderEnd);
        root->right = traversal(inorder, rightInorderBegin, rightInorderEnd, postorder, rightPostorderBegin, rightPostorderEnd);

        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        if (inorder.size() == 0 || postorder.size() == 0)
        {
            return NULL;
        }
        // return traversal(inorder, postorder);
        return traversal(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }
};
// @lc code=end
