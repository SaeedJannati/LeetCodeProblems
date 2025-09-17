#pragma once
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class LeetCode2353DesignAFoodRatingSystem
{
public:
    class FoodRatings
    {
    private:
        unordered_map<string, unordered_map<string, int>> unordered{};
        unordered_map<string, map<int, set<string>>> ordered{};
        unordered_map<string, string> foodCuisineMap{};

    public:
        FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings)
        {
            auto length = static_cast<int>(foods.size());
            for (auto i = 0; i < length; i++)
            {
                foodCuisineMap[foods[i]] = cuisines[i];
                if (!unordered.contains(cuisines[i]))
                {
                    unordered.insert({cuisines[i], {}});
                }
                if (!ordered.contains(cuisines[i]))
                {
                    ordered.insert({cuisines[i], {}});
                }
                unordered[cuisines[i]].emplace(foods[i], ratings[i]);
                if (!ordered[cuisines[i]].contains(ratings[i]))
                {
                    ordered[cuisines[i]][ratings[i]] = {};
                }
                ordered[cuisines[i]][ratings[i]].insert(foods[i]);
            }
        }

        void changeRating(string food, int newRating)
        {
            auto cuisine = foodCuisineMap[food];
            auto oldRating = unordered[cuisine][food];
            unordered[cuisine][food] = newRating;
            ordered[cuisine][oldRating].erase(food);
            if (ordered[cuisine][oldRating].empty())
                ordered[cuisine].erase(oldRating);
            ordered[cuisine][newRating].insert(food);
        }

        string highestRated(string cuisine)
        {
            return *ordered[cuisine].rbegin()->second.begin();
        }
    };
};
