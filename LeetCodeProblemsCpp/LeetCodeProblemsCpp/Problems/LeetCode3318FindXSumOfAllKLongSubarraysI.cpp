#include "LeetCode3318FindXSumOfAllKLongSubarraysI.h"

#include <queue>
#include <unordered_map>

#include "Auxilaries.h"
using namespace std;

vector<int> LeetCode3318FindXSumOfAllKLongSubarraysI::findXSum(vector<int>& nums, int k, int x)
{
    unordered_map<int, int> frequencyMap{};
    unordered_map<int,int> heapIndices{};
    priority_queue< pair<int,  int>> frequencyHeap{};
    vector<int> result{};
    int length= static_cast<int>(nums.size());
    for (int i=0;i<k-1;++i)
    {
        ++frequencyMap[nums[i]];
    }
    for (int j=k-1;j<length;++j)
    {
        if (j>=k)
        {
            --frequencyMap[nums[j-k]];
        }
     
            ++frequencyMap[nums[j]];
       
        frequencyHeap={};
        for (auto & [freq, num] : frequencyMap)
        {
            frequencyHeap.emplace(num,freq);
        }
        int resultElement{};
        for ( int i=0;i<x;i++)
        {
            if (frequencyHeap.empty())
                break;
            auto top = frequencyHeap.top();
            frequencyHeap.pop();
            resultElement+=top.second*top.first;
        }
        result.push_back(resultElement);
    }
    return result;
}

void LeetCode3318FindXSumOfAllKLongSubarraysI::Run()
{
    vector<int> nums={9,2,2};
    int k=3;
    int x=3;
    Auxilaries::PrintVector(findXSum(nums,k,x));
}
