#pragma once

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!(head && head->next)) {
            return true;
        }
        ListNode *mid = getMiddleNode(head);
        ListNode *first = head;
        ListNode *second = reverseList(mid->next);
        while (second) {
            if (first->val != second->val) {
                return false;
            }
            first = first->next;
            second = second->next;
        }
        return true;
    }
private:
    ListNode* getMiddleNode(ListNode* head) {
        if (!head) {
            return nullptr;
        }
        ListNode *one_step = head, *two_step = head;
        while (two_step->next && two_step->next->next) {
            one_step = one_step->next;
            two_step = two_step->next->next;
        }
        return one_step;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = nullptr, *cur = head, *nex;
        while (cur) {
            nex = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nex;
        }
        return pre;
    }
};
