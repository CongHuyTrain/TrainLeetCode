#pragma once
//3100. Water Bottles II
//Solved
//Medium
//You are given two integers numBottles and numExchange.
//numBottles represents the number of full water bottles that you initially have.
//In one operation, you can perform one of the following operations :
//Drink any number of full water bottles turning them into empty bottles.
//Exchange numExchange empty bottles with one full water bottle.Then, increase numExchange by one.
//Note that you cannot exchange multiple batches of empty bottles for the same value of numExchange.For example, 
//if numBottles == 3 and numExchange == 1, you cannot exchange 3 empty water bottles for 3 full bottles.
//Return the maximum number of water bottles you can drink.
class Solution {
public:
    // too easy
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int drinkBottles = 0, emptyBottles = 0;
        while (numBottles + emptyBottles >= numExchange) {
            drinkBottles += numBottles;
            emptyBottles = numBottles + emptyBottles - numExchange;
            numBottles = 1;
            numExchange++;
        }
        return drinkBottles + numBottles;
    }
};
// code learned from others
//class Solution {
//public:
//    int maxBottlesDrunk(int numBottles, int numExchange) {
//        int ans = numBottles;
//        for (int empty = numBottles; empty >= numExchange; numExchange++) {
//            ans++;
//            empty -= numExchange - 1;
//        }
//        return ans;
//    }
//};