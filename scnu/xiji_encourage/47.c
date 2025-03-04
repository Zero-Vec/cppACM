#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 二叉树节点结构体
struct TreeNode {
    char val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// 创建新节点
struct TreeNode* newNode(char val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// 根据前序遍历序列和中序遍历序列构建二叉树
struct TreeNode* buildTree(const char* preorder, const char* inorder, int in_start, int inorderEnd, int* preorderIndex) {
    if (in_start > inorderEnd) {
        return NULL;
    }

    char rootVal = preorder[*preorderIndex];
    (*preorderIndex)++;
    struct TreeNode* root = newNode(rootVal);

    if (in_start == inorderEnd) {
        return root;
    }

    int in_id = in_start;
    while (inorder[in_id] != rootVal) {
        in_id++;
    }

    root->left = buildTree(preorder, inorder, in_start, in_id - 1, preorderIndex);
    root->right = buildTree(preorder, inorder, in_id + 1, inorderEnd, preorderIndex);

    return root;
}

// 后序遍历二叉树并输出节点值
void postorderTraversal(struct TreeNode* root, char* postorder, int* post_id) {
    if (root == NULL) {
        return;
    }
    postorderTraversal(root->left, postorder, post_id);
    postorderTraversal(root->right, postorder, post_id);
    postorder[(*post_id)++] = root->val;
}

int main() {
    char preorder[100];
    char inorder[100];
    scanf("%s", preorder);
    scanf("%s", inorder);

    int pre_id = 0;
    struct TreeNode* root = buildTree(preorder, inorder, 0, strlen(inorder) - 1, &pre_id);

    char postorder[100];
    int post_id = 0;
    postorderTraversal(root, postorder, &post_id);
    postorder[post_id] = '\0';

    printf("%s\n", postorder);
    return 0;
}