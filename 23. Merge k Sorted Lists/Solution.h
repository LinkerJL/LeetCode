#pragma once
#include <vector>
using std::vector;
#include <algorithm>
using std::make_heap;
using std::pop_heap;
using std::push_heap;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode head(0);
        vector<ListNode*> v;
        for (auto node : lists) {
            if (node) {
                v.push_back(node);
            }
        }
        make_heap(v.begin(), v.end(), heapComp);
        ListNode * curNode = &head;
        while (v.size()) {
            curNode->next = v.front();
            pop_heap(v.begin(), v.end(), heapComp);
            v.pop_back();
            curNode = curNode->next;
            if (curNode->next) {
                v.push_back(curNode->next);
                push_heap(v.begin(), v.end(), heapComp);
            }
        }
        return head.next;
    }
private:
    static bool heapComp(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};
