#pragma once

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head) {
            return nullptr;
        }
        ListNode *node_even_pre = head, *node_odd_pre = head->next, *node_odd;
        while (node_odd_pre && node_odd_pre->next) {
            node_odd = node_odd_pre->next;
            node_odd_pre->next = node_odd->next;
            node_odd->next = node_even_pre->next;
            node_even_pre->next = node_odd;

            node_even_pre = node_odd;
            node_odd_pre = node_odd_pre->next;
        }
        return head;
    }
};
