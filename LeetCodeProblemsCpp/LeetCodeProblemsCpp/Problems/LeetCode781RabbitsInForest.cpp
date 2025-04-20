#include "LeetCode781RabbitsInForest.h"

#include <iostream>
#include <unordered_map>
using namespace std;

int LeetCode781RabbitsInForest::numRabbits(vector<int>& answers)
{
    unordered_map<int, int> map{};
    int length = static_cast<int>(answers.size());
    for (int i = 0; i < length; ++i)
    {
     if (!map.contains(answers[i]))
     {
         map[answers[i]]=0;
     }
        map[answers[i]]++;
    }
    int result=0;
    for (auto & pair:map)
    {
        result+= (pair.second/(pair.first+1)+(pair.second%(pair.first+1)!=0?1:0))*( pair.first+1);
    }
    return result;
}

void LeetCode781RabbitsInForest::Run()
{
    vector<int> answers={10, 10, 10};
    cout << numRabbits(answers)<<'\n';
}
