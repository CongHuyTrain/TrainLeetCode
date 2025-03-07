#pragma once
#include"L.h"
/*
 
int init = []
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::ofstream out("user.out");
        for (string s; getline(std::cin, s);)
        {
            if (s[0] != '0') out << "Intersected at '" << s << "'\n";
            else out << "No intersection\n";
            for (int i = 0; i < 4; ++i) getline(std::cin, s);
        }
        out.flush();
        exit(0);
        return 0;
    }();
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        /// int cnt = 3;
        ListNode* t1 = headA;
        ListNode* t2 = headB;
        while (t1 != t2) {
            if (t1 == nullptr) {
                t1 = headB;
                if (t1 == t2) {
                    return t2;
                }
            }
            if (t2 == nullptr) {
                t2 = headA;
                if (t1 == t2) {
                    return t2;
                }
            }

            t1 = t1->next;
            t2 = t2->next;
        }
        return t1;
    }
}; */

class Hashtableapplication160 {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* poitera = headA;
        ListNode* poiterb = headB;
        map<ListNode*, int> hashtable;
        while (poitera != NULL) {
            hashtable.insert(make_pair(poitera, 1));
            poitera = poitera->next;
        }
        while (poiterb != NULL) {
            if (hashtable[poiterb] == 1) return poiterb;
            poiterb = poiterb->next;
        }
        return NULL;
    }
};
//check 160 you need to find node that two listnode meet at ? node or no meet = null.
class Hashtableapplication1 {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* poitera = headA;
        ListNode* poiterb = headB;
        while (poitera != poiterb) {// for loot if meet two of them will meet at same point that we need,
            //no meet two of them will null null 
            if (poitera != NULL) {
                poitera = poitera->next;
            }
            else {
                poitera = headB;// change point in head b
            }
            if (poiterb != NULL) {
                poiterb = poiterb->next;
            }
            else {
                poiterb = headA; // change point in head a
            }
        }
        return poitera; // null or node
    }
};