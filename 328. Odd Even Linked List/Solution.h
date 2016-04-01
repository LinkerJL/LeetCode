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
        auto node_odd = head, node_even_head = head->next, node_even = node_even_head;
        while (node_even && node_even->next) {
            node_odd = node_odd->next = node_even->next;
            node_even = node_even->next = node_odd->next;
        }
        node_odd->next = node_even_head;
        return head;
    }
};
