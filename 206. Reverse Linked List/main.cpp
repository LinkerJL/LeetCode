#include "Solution.h"

int main() {
    Solution s;
    auto head = new ListNode(1);
    head->next = new ListNode(2);
    ListNode *new_head = s.reverseList(head);
    delete head->next;
    delete head;
    return 0;
}