#pragma once

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!(headA && headB)) {
            return nullptr;
        }
        auto node_a = headA, node_b = headB;
        while (node_a != node_b) {
            node_a = node_a->next;
            node_b = node_b->next;
            if (node_a == node_b) {
                return node_a;
            }
            if (!node_a) {
                node_a = headB;
            }
            if (!node_b) {
                node_b = headA;
            }
        }
        return node_a;
    }
};
