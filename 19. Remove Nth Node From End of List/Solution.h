#pragma once

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(0), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto a = &head;
        auto b = head;
        while (n > 1) {
            --n;
            b = b->next;
        }
        while (b->next) {
            a = &((*a)->next);
            b = b->next;
        }
        //b = *a;
        //*a = (*a)->next;
        //delete(b);
        *a = (*a)->next;
        return head;
    }
};
