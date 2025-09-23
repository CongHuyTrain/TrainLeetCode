#pragma once
#include<vector>
#include<unordered_map>
#include<set>
#include<string>
using namespace std;
class FoodRatings {
public:
	unordered_map<string, set<pair<int, string>>> cuisineToFoods; // cuisine is key, 
    // return set is used to keep the order of the foods( set order greater for example: 12345)
	// pair is used to keep the rating and food name together, we will know the food name is through rating( for function highestRated)
	unordered_map<string, string> foodToCuisines; // typing food to cuisine is faster than find it through vector 
	unordered_map<string, int> foodToRatings; // food to rating, both unordered maps is use for function changeRating
	// that function can't remove if we don't know the cuisine of the food and the old rating of the food( because set and pair)
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++) {
            foodToCuisines[foods[i]] = cuisines[i];
            foodToRatings[foods[i]] = ratings[i];
			cuisineToFoods[cuisines[i]].insert({ -ratings[i], foods[i] }); 
			// plus rating is descending order( because set is ascending order, so we use negative to make it descending)
			// and return the first food is the highest rating food(function highestRated)
        }
    }

    void changeRating(string food, int newRating) {
        string cuisine = foodToCuisines[food];
        int oldRating = foodToRatings[food];
        cuisineToFoods[cuisine].erase({ -oldRating, food });
        cuisineToFoods[cuisine].insert({ -newRating, food });
		foodToRatings[food] = newRating; // update the new rating in foodToRatings, foodToCuisines don't need to update
    }

    string highestRated(string cuisine) {
        return cuisineToFoods[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */