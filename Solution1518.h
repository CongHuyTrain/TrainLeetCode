#pragma once
// i recommend you see Solution3100 first
//1518. Water Bottles
//Solved
//Easy
//There are numBottles water bottles that are initially full of water.
//You can exchange numExchange empty water bottles from the market with one full water bottle.
//The operation of drinking a full water bottle turns it into an empty bottle.
//Given the two integers numBottles and numExchange, return the maximum number of water bottles you can drink.
//Example 1:
//Input: numBottles = 9, numExchange = 3
//Output : 13
//Explanation : You can exchange 3 empty bottles to get 1 full water bottle.
//Number of water bottles you can drink : 9 + 3 + 1 = 13.
//Example 2 :
//    Input : numBottles = 15, numExchange = 4
//    Output : 19
//    Explanation : You can exchange 4 empty bottles to get 1 full water bottle.
//    Number of water bottles you can drink : 15 + 3 + 1 = 19.
//    Constraints :
//    1 <= numBottles <= 100
//    2 <= numExchange <= 100
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int drinked = 0, emptyBottles = 0;
		while (numBottles > 0) { // while we still have bottle
            drinked += numBottles; // drink
			emptyBottles += numBottles; // get empty bottles
			numBottles = emptyBottles / numExchange; // exchange empty bottles for full bottles
			emptyBottles = emptyBottles % numExchange; // get remaining empty bottles
        }
        return drinked;
    }
};
//class Solution {
//public:
//    int numWaterBottles(int b, int n) {
//        return b + (b - 1) / (n - 1); // it is a math solution
//    }
//}; 