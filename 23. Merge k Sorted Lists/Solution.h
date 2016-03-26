#pragma once
#include <vector>
using std::vector;
#include <queue>
using std::priority_queue;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode head(0);
        priority_queue<ListNode*, vector<ListNode*>, Compare> q;
        for (auto node : lists) {
            if (node) {
                q.push(node);
            }
        }
        ListNode *curNode = &head;
        while (!q.empty()) {
            curNode->next = q.top();
            q.pop();
            curNode = curNode->next;
            if (curNode->next) {
                q.push(curNode->next);
            }
        }
        return head.next;
    }
private:
    struct Compare {
        bool operator()(const ListNode* a, const ListNode* b) {
            return a->val > b->val;
        }
    };
};
