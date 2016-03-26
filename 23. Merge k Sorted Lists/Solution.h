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
        ListNode *la = l1, *lb = l2;
        while (true) {
            if (la->val > lb->val) {
                swap(*la, *lb);
            }
            if (!la->next) {
                la->next = lb;
                break;
            }
            la = la->next;
        }
        return l1;
    }
};
