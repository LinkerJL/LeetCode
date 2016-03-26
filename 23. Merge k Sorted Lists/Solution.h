#pragma once
#include <vector>
using std::vector;
#include <utility>
using std::swap;
#include <cstdlib>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int len = lists.size();
        if (!len) {
            return nullptr;
        }
        while (--len) {
            swap(lists[rand() % len], lists[len]);
            lists[len - 1] = mergeTwoLists(lists[len - 1], lists[len]);
        }
        return lists[0];
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) {
            return l2;
        }
        if (!l2) {
            return l1;
        }
        if (l1->val <= l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
};
