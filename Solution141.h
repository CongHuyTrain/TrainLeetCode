#pragma once
#include"L.h"
//Zeynep Sena Yesilyurt
class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* slowPtr = head;
        ListNode* fastPtr = head;

        while (slowPtr != nullptr && fastPtr != nullptr && fastPtr->next != nullptr) {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;

            if (slowPtr == fastPtr) {
                return true;
            }
        }

        return false;
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /*class Solution {
 public:
     bool hasCycle(ListNode *head) {
         map<int, int> n;
         int i = 2;
         n.insert(make_pair(1, head->val));
         head = head->next;
         while(head != nullptr){
             n.insert(make_pair(i, head->val));
             for(int j = 2; j < i+1; j++){
                 if(n[1] == n[j]){
                     return true;
                 }
             }
             i = i+1;
         }
         return false;
     }
 };*/
class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return false;
        }

        unordered_set<ListNode*> visited;
        while (head != nullptr) {
            if (visited.count(head)) {
                return true;
            }
            visited.insert(head);
            head = head->next;
        }

        return false;
    }
};