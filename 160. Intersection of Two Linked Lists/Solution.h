#pragma once

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto node_a = headA, node_b = headB;
        while (node_a != node_b) {
            node_a = node_a ? node_a->next : headB;
            node_b = node_b ? node_b->next : headA;
        }
        return node_a;
    }
};
