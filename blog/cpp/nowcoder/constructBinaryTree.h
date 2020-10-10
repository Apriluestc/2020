#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x)
        :val(x),
        left(nullptr),
        right(nullptr)
    {}
};

class Solution {
public:
    TreeNode* constructBinaryTree(vector<int> pre, vector<int> in) {
        if (pre.size() != in.size()) {
            return nullptr;
        }
    }
private:
};
