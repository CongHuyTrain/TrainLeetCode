#pragma once
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class RemoveDuplication {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* current = head;
        while (current && current->next) {
            if (current->val == current->next->val) {
                ListNode* temp = current->next;
                current->next = current->next->next;
                delete temp;
            }
            else {
                current = current->next;
            }
        }

        return head;
    }


    // nhanh 
    /*class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* prev = head;
        ListNode* temp = head->next;
        while(temp!=NULL){
            if(prev->val == temp->val){
                prev->next = temp->next;
                temp = temp->next;
            }
            else{
                prev = prev->next;
                temp = temp->next;
            }
        }
        return head;
    }
};*/
};

