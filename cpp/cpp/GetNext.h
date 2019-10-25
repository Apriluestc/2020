struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode* next;
    TreeNode(int x)
        :val(x),
        left(nullptr),
        right(nullptr),
        next(nullptr)
    {}
};

TreeNode* GetNext(TreeNode* pNode) {
    if (pNode == nullptr) {
        return nullptr;
    }
    if (pNode->right != nullptr) {
        while (pNode->left != nullptr) {
            pNode = pNode->left;
        }
        return pNode;
    }
    while (pNode->next != nullptr) {
        if (pNode->next->left == pNode) {
            return pNode;
        }
        pNode = pNode->next;
    }
    return nullptr;
}
