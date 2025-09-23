//
// Created by saeed on 9/23/25.
//

#include "LeetCode1774ClosestDessertCost.h"

#include <iostream>
#include <numeric>
#include <bits/ranges_algo.h>


using namespace std;



int LeetCode1774ClosestDessertCost::closestCost(vector<int> &baseCosts, vector<int> &toppingCosts, int target) {
    int maxBase=*ranges::max_element(baseCosts);
    int sumToppings=accumulate(toppingCosts.begin(), toppingCosts.end(), 0)*2;
    int maxPrice=maxBase+sumToppings;
    vector<bool> canMake(maxPrice+1,false);
    for (auto  const base: baseCosts) {
        canMake[base] = true;
    }

}

void LeetCode1774ClosestDessertCost::Run() {
    vector<int> baseCosts{3,10};
    vector<int> toppings{2,5};
    int target{9};
    cout<<closestCost(baseCosts,toppings,target)<<endl;
}
