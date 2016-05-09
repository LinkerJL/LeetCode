#pragma once
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        auto node_ptr = &head;
        while (*node_ptr) {
            if ((*node_ptr)->val == val) {
                //auto node = *node_ptr;
                *node_ptr = (*node_ptr)->next;
                //delete node;
            } else {
                node_ptr = &(*node_ptr)->next;
            }
        }
        return head;
    }
};
