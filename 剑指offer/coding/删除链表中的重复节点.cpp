#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x)
        :val(x),
        next(nullptr)
    {}
};

class Solution {
public:
    ListNode* deleteDuplication(ListNode* head) {

        // 链表为空或者只有一个节点不做删除处理
        // 不存在重复结点
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* cur;
        if (head->next->val == head->val) {
            int tmp = head->val;
            cur = head->next->next;
            delete head->next;
            delete head;
            while (cur != nullptr && cur->val == tmp) {
                ListNode* node = cur;
                cur = cur->next;
                delete node;
            }
            return deleteDuplication(cur);
        } else {
            cur = head->next;
            head->next = deleteDuplication(cur);
            return head;
        }
    }
};

int main()
{
    return 0;
}
