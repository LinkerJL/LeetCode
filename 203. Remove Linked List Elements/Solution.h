#pragma once
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) {
            return nullptr;
        }
        head->next = removeElements(head->next, val);
        if (head->val == val) {
            auto node = head->next;
            //delete head;
            return node;
        } else {
            return head;
        }
    }
};
