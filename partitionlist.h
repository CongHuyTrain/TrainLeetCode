#pragma once
#include"L.h"
class partitionlist {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* bigger = new ListNode(-1);
        ListNode* smaller = new ListNode(-1);
        ListNode* big = bigger;
        ListNode* small = smaller;
        while (head) {
            if (head->val >= x) {
                bigger->next = head;
                bigger = bigger->next;
            }
            else {
                smaller->next = head;
                smaller = smaller->next;
            }
            head = head->next;
        }
        bigger->next = NULL;
        smaller->next = big->next;
        return small->next;

    }
};