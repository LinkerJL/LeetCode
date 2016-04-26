#pragma once
#include <algorithm>
using std::swap;

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
        auto len_a = 0, len_b = 0;
        auto node_a = headA;
        while (node_a->next) {
            node_a = node_a->next;
            ++len_a;
        }
        auto node_b = headB;
        while (node_b->next) {
            node_b = node_b->next;
            ++len_b;
        }
        if (node_a != node_b) {
            return nullptr;
        }
        if (len_a < len_b) {
            swap(len_a, len_b);
            swap(headA, headB);
        }
        len_a -= len_b;
        while (len_a) {
            headA = headA->next;
            --len_a;
        }
        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};
