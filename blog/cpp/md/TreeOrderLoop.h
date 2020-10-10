#include <iostream>
#include <stack>
#include <queue>

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

void preOrderLoop(TreeNode* root) {
    stack<TreeNode*> s;
    TreeNode* cur = root;
    s.push(cur);
    while (!s.empty()) {
        cur = s.top();
        s.pop();
        cout << cur->_val;
        if (cur->_left) {
            s.push(cur->_left);
        }
        if (cur->_right) {
            s.push(cur->_right);
        }
    }
}

void levelOrder(TreeNode* root) {
    if (root) {
        queue<TreeNode*> q;
        TreeNode* cur = root;
        q.push(cur);
        while (!q.empty()) {
            cur = q.front();
            q.pop();
            cout << cur->_val;
            if (cur->_left) {
                q.push(cur->_left);
            }
            if (cur->_right) {
                q.push(cur->_right);
            }
        }
    }
}
