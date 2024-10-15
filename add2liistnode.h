//#pragma once
///**
// * Definition for singly-linked list.
// * public class ListNode {
// *     int val;
// *     ListNode next;
// *     ListNode() {}
// *     ListNode(int val) { this.val = val; }
// *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
// * }
//
//class Solution {
//    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
//        ListNode l3 = new ListNode(0);
//        int r = 0;
//        while(l1 != null  || l2 != null || r == 1)
//        {
//            l3.val = l1.val + l2.val + r;
//            r = 0;
//            if(l3.val > 9){
//                l3.val /= 10;
//                r = 1;
//            }
//            l3.next = new ListNode(0);
//            l3 = l3.next;
//            l1 = l1.next;
//            l2 = l2.next;
//        }
//        l3.next = (l1 != null) ? l1: l2;
//        return l3;
//    }
//}*/
//class Solution {
//    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
//        ListNode dummy = new ListNode(0);
//        ListNode l3 = dummy;
//        int carry = 0;
//        int x = -1;
//        int y = -1;
//        int sum = -1;
//        while (l1 != null || l2 != null || carry > 0) {
//            x = (l1 != null) ? l1.val : 0;
//            y = (l2 != null) ? l2.val : 0;
//            sum = x + y + carry;
//            carry = sum / 10;
//
//            l3.next = new ListNode(sum % 10);
//            l3 = l3.next;
//
//            if (l1 != null) l1 = l1.next;
//            if (l2 != null) l2 = l2.next;
//        }
//
//        if (carry > 0) {
//            l3.next = new ListNode(carry);
//        }
//
//        return dummy.next;
//    }
//}

