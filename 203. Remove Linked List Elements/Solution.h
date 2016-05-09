#pragma once
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *pre = nullptr;
        auto cur = head;
        while (cur) {
            if (cur->val == val) {
                if (pre) {
                    pre->next = cur->next;
                    //delete cur;
                    cur = pre->next;
                } else {
                    head = cur->next;
                    //delete cur;
                    cur = head;
                }
            } else {
                pre = cur;
                cur = pre->next;
            }
        }
        return head;
    }
};
