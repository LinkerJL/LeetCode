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
        while (a->next) {
            a = a->next;
            --n;
            if (n < 0) {
                b = b->next;
            }
        }
        if (n > 0) {
            //a = head->next;
            //delete head;
            //return a;
            return head->next;
        }
        //a = b->next;
        //b->next = a->next;
        //delete a;
        b->next = b->next->next;
        return head;
    }
};
