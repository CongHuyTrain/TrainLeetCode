<<<<<<< HEAD
#pragma once
#include"L.h"
#include<unordered_set>
//202. Happy Number
//Easy
//Topics
//Companies
//Write an algorithm to determine if a number n is happy.
//
//A happy number is a number defined by the following process :
//
//Starting with any positive integer, replace the number by the sum of the squares of its digits.
//Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
//Those numbers for which this process ends in 1 are happy.
//Return true if n is a happy number, and false if not.
//
//
//
//Example 1:
//
//Input: n = 19
//Output : true
//Explanation :
//    12 + 92 = 82
//    82 + 22 = 68
//    62 + 82 = 100
//    12 + 02 + 02 = 1
//    Example 2 :
//
//    Input : n = 2
//    Output : false
class Solution {
public:
    int newnumber(int n) { // function that return int for example 12 -> 1^2 + 2^2 = 5.
        int result = 0;
        while (n > 0) { // n != 0 is also right.
            result += (n % 10) * (n % 10);
            n = n / 10;
        }
        return result;
    }
    bool isHappy(int n) {
        unordered_set<int> set; // unordered_set is a library c++ that is hashtable, it will not access element that is similar
        while (n != 1 && !set.count(n)) { // count() is check element appears how many time, it have not appear, then continous
            // explain we need n that digit of it will sum 1, and beside we need to check it if it infinity.
            set.insert(n); // like flat to say it already do with that element.
            n = newnumber(n); // once again with new number
        }
        //whole loot to check that if it infinity, then stop. 
        return n == 1; // 
    }
    //explane why it isnot increase.
    //max digit A is A or AA, for example 9 is 81 -> 64 + 1 = 65 -> ...
    //max digit AA is A, AA, AAA, for example 99 is 81 plus 81 -> 162. 
    // max digit AAAA, fe 9999 is 324. it will down AAA
    // so, i can conclude that it can not increase infinity
};

// another way
/*

    Time Complexity : O(logN) where N is the number.

    Space Complexity : O(1), Constant space.

    Solved using Floyd's Cycle-Finding Algorithm.

*/


/***************************************** Approach 2 *****************************************/

//class Solution {
//private:
//    int nextNumber(int n) {
//        int newNumber = 0;
//        while (n != 0) {
//            int num = n % 10;
//            newNumber += num * num;
//            n = n / 10;
//        }
//        return newNumber;
//    }
//public:
//    bool isHappy(int n) {
//        int slowPointer = n;
//        int fastPointer = nextNumber(n);
//        while (fastPointer != 1 && fastPointer != slowPointer) {
//            slowPointer = nextNumber(slowPointer);
//            fastPointer = nextNumber(nextNumber(fastPointer));
//        }
//        return fastPointer == 1;
//    }
=======
#pragma once
#include"L.h"
#include<unordered_set>
//202. Happy Number
//Easy
//Topics
//Companies
//Write an algorithm to determine if a number n is happy.
//
//A happy number is a number defined by the following process :
//
//Starting with any positive integer, replace the number by the sum of the squares of its digits.
//Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
//Those numbers for which this process ends in 1 are happy.
//Return true if n is a happy number, and false if not.
//
//
//
//Example 1:
//
//Input: n = 19
//Output : true
//Explanation :
//    12 + 92 = 82
//    82 + 22 = 68
//    62 + 82 = 100
//    12 + 02 + 02 = 1
//    Example 2 :
//
//    Input : n = 2
//    Output : false
class Solution {
public:
    int newnumber(int n) { // function that return int for example 12 -> 1^2 + 2^2 = 5.
        int result = 0;
        while (n > 0) { // n != 0 is also right.
            result += (n % 10) * (n % 10);
            n = n / 10;
        }
        return result;
    }
    bool isHappy(int n) {
        unordered_set<int> set; // unordered_set is a library c++ that is hashtable, it will not access element that is similar
        while (n != 1 && !set.count(n)) { // count() is check element appears how many time, it have not appear, then continous
            // explain we need n that digit of it will sum 1, and beside we need to check it if it infinity.
            set.insert(n); // like flat to say it already do with that element.
            n = newnumber(n); // once again with new number
        }
        //whole loot to check that if it infinity, then stop. 
        return n == 1; // 
    }
    //explane why it isnot increase.
    //max digit A is A or AA, for example 9 is 81 -> 64 + 1 = 65 -> ...
    //max digit AA is A, AA, AAA, for example 99 is 81 plus 81 -> 162. 
    // max digit AAAA, fe 9999 is 324. it will down AAA
    // so, i can conclude that it can not increase infinity
};

// another way
/*

    Time Complexity : O(logN) where N is the number.

    Space Complexity : O(1), Constant space.

    Solved using Floyd's Cycle-Finding Algorithm.

*/


/***************************************** Approach 2 *****************************************/

//class Solution {
//private:
//    int nextNumber(int n) {
//        int newNumber = 0;
//        while (n != 0) {
//            int num = n % 10;
//            newNumber += num * num;
//            n = n / 10;
//        }
//        return newNumber;
//    }
//public:
//    bool isHappy(int n) {
//        int slowPointer = n;
//        int fastPointer = nextNumber(n);
//        while (fastPointer != 1 && fastPointer != slowPointer) {
//            slowPointer = nextNumber(slowPointer);
//            fastPointer = nextNumber(nextNumber(fastPointer));
//        }
//        return fastPointer == 1;
//    }
>>>>>>> ccfc2d41cc8ed0575db2cca47d1d2f8d82bb3b45
//};