#include <queue>
#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int rhx = 0)
        :val(rhx),
        left(nullptr),
        right(nullptr)
    {}
};

class Solution {
public:
    void LevelOrder(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        std::queue<TreeNode*> q;
        // 根节点入队
        q.push(root);
        while (!q.empty()) {
            TreeNode* tmp = root;
            // 输出根节点
            std::cout << tmp->val;
            q.pop();
            if (tmp->left) {
                q.push(tmp->left);
            }
            if (tmp->right) {
                q.push(tmp->right);
            }
        }
    }
};
