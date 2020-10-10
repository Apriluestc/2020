#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int _val;
    TreeNode* _left;
    TreeNode* _right;
    TreeNode(int x)
        :_val(x),
        _left(nullptr),
        _right(nullptr)
    {}
};

// 先序遍历，根 左 右
void preOrder(const TreeNode* root) {
    if (root == nullptr) {
        return ;
    }
    cout << root->_val;
    preOrder(root->_left);
    preOrder(root->_right);
}

// 中序遍历，左 根 右
void inOrder(const TreeNode* root) {
    if (root == nullptr) {
        return ;
    }
    inOrder(root->_left);
    cout << root->_val;
    inOrder(root->_right);
}

// 后续遍历，左 右 根
void posOrder(const TreeNode* root) {
    if (root == nullptr) {
        return ;
    }
    posOrder(root->_left);
    posOrder(root->_right);
    cout << root->_val;
}
