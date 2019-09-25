#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/*
 * 从尾到头打印链表
 *
 * 方案一：修改链表
 * 方案二：不修改链表
 * */

struct ListNode {
    int val_;
    ListNode* next_;
    ListNode(int x)
        :val_(x),
        next_(nullptr)
    {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* pNode) {
        if (pNode == nullptr || pNode->next_ == nullptr) {
            return pNode;
        }
        ListNode* pPre = nullptr;
        ListNode* pCur = pNode;
        ListNode* pNext = nullptr;
        while (pCur) {
            pNext = pCur->next_;
            pCur->next_ = pPre;
            pPre = pCur;
            pCur = pNext;
        }
        return pPre;
    }
    vector<int> printListFromTailTpHead(ListNode* pNode) {
        ListNode* Node = pNode;
        stack<int> s;
        int count_ = 0;
        while (Node) {
            s.push(Node->val_);
            count_++;
            Node = Node->next_;
        }
        vector<int> res(count_, 0);
        for (int i = 0; i < count_; i++) {
            res[i] = s.top();
            s.pop();
        }
        return res;
    }
    void printListFromTailToHead(ListNode* pNode, vector<int>& res) {
        if (pNode != nullptr) {
            printListFromTailToHead(pNode->next_, res);
            res.push_back(pNode->val_);
        }
    }
};
