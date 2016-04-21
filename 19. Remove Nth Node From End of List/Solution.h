#pragma once

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(0), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto a = head, b = head;
        while (n > 0) {
            b = b->next;
            --n;
        }
        if (!b) {
            return head->next;
        }
        while (b->next) {
            a = a->next;
            b = b->next;
        }
        a->next = a->next->next;
        return head;
    }
};
