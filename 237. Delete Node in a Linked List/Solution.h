#pragma once

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    void deleteNode(ListNode* node) {
        if (node && node->next) {
            *node = *(node->next);
        }
    }
};
