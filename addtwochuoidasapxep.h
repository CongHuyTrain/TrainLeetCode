#pragma once
#include"L.h"
 //class Solution {
 //public:
 //    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
 //        ListNode* head ;   //check list1 and list2 if 1 null of 2 list if all null return null                                                                                                                 
 //        /*if (list2 == nullptr) {
 //            return list1;
 //        }
 //        else if (list1 == nullptr) {
 //            return list2;
 //        }*/
 //        //no need
 //        if (list1->val <= list2->val) {
 //            head = list1;
 //            list1 = list1->next;
 //        }
 //        else {
 //            head = list2;
 //            list2 = list2->next;
 //        }
 //
 //        ListNode* tail = list2;
 //        while (list1 != nullptr && list2 != nullptr) {
 //            if (list1->val <= list2->val) {
 //                tail->next = list1;
 //                list1 = list1->next;
 //            }
 //            else {
 //                tail->next = list2;
 //                list2 = list2->next;
 //            }
 //            tail = tail->next;
 //        }
 //        if (list1 != nullptr)
 //            tail->next = list1;
 //        else if (list2 != nullptr)
 //            tail->next = list2;
 //
 //        return head;
 //    }
 //};
 // code someone else
class  addtwochuoidasapxep {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* prev = new ListNode(-1); //creat new 
        ListNode* prevh = prev;
        while (list1 != nullptr && list2 != nullptr) {
            //cout<<prev->val<<" ";
            if (list1->val >= list2->val) {
                prev->next = list2;
                list2 = list2->next;
            }
            else {
                prev->next = list1;
                list1 = list1->next;
            }
            prev = prev->next;
        }
        prev->next = list1 == nullptr ? list2 : list1;
        return prevh->next; //
    }
};
